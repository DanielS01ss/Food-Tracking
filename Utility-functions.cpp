#include <iostream>
#include <string>
#include <regex>
#include "Aliment.h"
#include "Progres.h"
#include "Produs.h"
#include "Meal.h"

using namespace std;




Aliment searchAliment(string name,string meal_name, int size,Aliment al[100])
{
    ///ce facem este ca iteram prin mealul-ul respectiv si returnam alimentul care are numele la fel cu cel cautat
    for (int i = 0; i < size; i++)
    {
        if (al[i].getNume() == name)
            return al[i];
    }   
    Aliment a;
    return a;

}


Produs parseAliment(string s,string meal_name, Aliment mic_dejunA[100], int mic_dejun_size, Aliment pranzA[100], int pranz_size, Aliment cinaA[100],
    int cina_size, Aliment gustariA[100], int gustari_size)
{
    Produs p1;
    string nume;
    double cantitate;
    double portie;
    size_t pos = 0;
    string token;


    ///si ce ar trebui este ca ar trebui sa avem o functie care sa aiba deja toate alimentele
    ///ca sa putem extrage alimentul nostru pe care dorim sa-l cautam si sa-l stocam ulterior sub forma de al in produs
    ///pentru ca are un camp dedicat pentru asta
    ///asa ca asta vom si face

    ///avem functia de getAlimente si putem sa ne folosim de ea
    ///ca sa luam toate alimentele din fisier si ulterior dupa ce facem
    ///acest lucru ne putem apuca sa cautam fiecare aliment
    pos = s.find(",");
    token = s.substr(0, pos);
    s.erase(0, pos + 1);
    nume = token;

    pos = s.find(",");
    token = s.substr(0, pos);
    s.erase(0, pos + 1);
    p1.setCantitate(stod(token));


    p1.setPortion(stod(s));
    /*

        STRUCTURA PRODUS:

            1. Aliment al
            2. double cantitate
            3.double portie


    */
    ///aici deja avem nevoie de alimentele din main
    ///si vom face o functie de search dupa nume
    string meal1 = "mic-dejun",
        meal2 = "pranz",
        meal3 = "cina",
        meal4 = "gustare";
    Aliment al;
    if (meal_name == meal1)
    {
        al = searchAliment(nume, meal1, mic_dejun_size, mic_dejunA);
    } 
    else if (meal_name == meal2)
    {
        al = searchAliment(nume, meal2, pranz_size, pranzA);
    }
    else if (meal_name == meal3)
    {
        al = searchAliment(nume, meal3, cina_size, cinaA);
    }
    else if (meal_name == meal4)
    {
        al = searchAliment(nume, meal4, gustari_size, gustariA);
    }

    p1.setAliment(al);
    return p1;

}

Progres parseProgress(string s)
{
    Progres p;
    int consumul;
    double proteine;
    double carbohidrati;
    double grasimi;
    ///si acuma ce facem este ca vom face parsing dupa ,
    size_t pos = 0;
    string token;
    ///asta e recurring 

    pos = s.find(",");
    token = s.substr(0, pos);
    s.erase(0, pos + 1);
    ///aici ai consumul
    p.setConsum(stoi(token));

    pos = s.find(",");
    token = s.substr(0, pos);
    s.erase(0, pos + 1);
    ///aici ai proteine
    p.setProteine(stod(token));

    pos = s.find(",");
    token = s.substr(0, pos);
    s.erase(0, pos + 1);
    ///aici ai carbo
    p.setCarbohidrati(stod(token));


    pos = s.find(",");
    token = s.substr(0, pos);
    s.erase(0, pos + 1);
    ///aici ai grasimi
    p.setGrasimi(stod(token));

    return p;

}

void saveData(vector<Meal>&m)
{
    ///iteram prin fiecare masa si vom stoca in logs2.txt toata treaba prima data ca
    ///sa putem verifica
    ofstream f("logs2.txt");

    for (int i = 0; i < m.size(); i++)
    {
        f << m[i].getData() << endl;
        ///progresul global per masa
        Progres real = m[i].getReal();
        Progres expected = m[i].getExpected();
        Menu mic_de_jun = m[i].getMic_de_Jun();
        Menu pranz = m[i].getPranz();
        Menu cina = m[i].getCina();
        Menu gustari = m[i].getGustari();
        ///afisam progresul asteptat
        f <<expected;
        ///afisam progresul real
        f << real;
        ///afisam progresul pe micul dejun
        ///afisam progresul real si expected pe micul dejun
        ///si dupa afisam alimente recomandate si consumate
        f << mic_de_jun;
        f << pranz;
        f <<cina;
        f <<gustari;
        
    }

    f.close();

}



int getmax(int a, int b)
{

    return ((a > b) ? a : b);
}

///v valori 
///w costuri
int knapsack(int v[], int w[], int n, int W, int i)
{
    // base case: Negative capacity
    if (W < 0) {
        return INT_MIN;
    }

    // base case: no items left or capacity becomes 0
    if (n < 0 || W == 0) {
        return 0;
    }

    // Case 1. Include current item `v[n]` in the knapsack and recur for
    // remaining items `n-1` with decreased capacity `W-w[n]`

    int include = v[n] + knapsack(v, w, n - 1, W - w[n], i + 1);
    // Case 2. Exclude current item `v[n]` from the knapsack and recur for
    // remaining items `n-1`

    int exclude = knapsack(v, w, n - 1, W, i + 1);

    // return maximum value we get by including or excluding the current item
    return max(include, exclude);
}


vector<int>stack;
vector<int> indexes;
vector<int> dummyData;

void bkt(int k, int s, int full)
{
    if (s >= full || k == dummyData.size())
    {
        return;
    }
    else {

        stack.push_back(dummyData[k]);
        indexes.push_back(k);
        bkt(k + 1, s + dummyData[k], full);
    }

}
void setVectorZero(int a[],int size)
{
    for (int i = 0; i < size; i++)
    {
        a[i] = 0;
    }

}

void recommendFoodPerMeal(Meal& m, Aliment mic_dejunA[100], int mic_dejun_size, Aliment pranzA[100], int pranz_size, Aliment cinaA[100],
    int cina_size, Aliment gustariA[100], int gustari_size)
{
    
    ///ce facem este ca functia asta ne va recomanda pentru un meal toate datele necesare
    ///adica ce va face este ca ne va partitiona cat ne trebuie aport caloric pe zi si in functie de ala
    ///ne va lua alimentele si le va recomanda ca ulterior sa le stocheze in fisier
    Progres p = m.getMic_de_Jun().getProgresExpected();
    int calories = m.getExpected().getConsum();
    int grasimi = m.getExpected().getGrasimi();
    int proteine = m.getExpected().getProteine();
    int carbohidrati = m.getExpected().getCarbohidrati();
    p.setConsum((calories * 40) / 100);
    p.setGrasimi((grasimi*40)/100);
    p.setProteine((proteine * 40) / 100);
    p.setCarbohidrati((carbohidrati * 40) / 100);
 

    Progres pros1, pros2;
    Menu masa = m.getMic_de_Jun();
    m.set_Mic_Dejun(masa);
    masa.setProgresExpected(p);

    p = m.getPranz().getProgresExpected();
   
    p.setConsum((calories * 30) / 100);
    p.setGrasimi((grasimi * 30) / 100);
    p.setProteine((proteine * 30) / 100);
    p.setCarbohidrati((carbohidrati * 30) / 100);
    p.setCarbohidrati((carbohidrati * 30) / 100);
    masa = m.getPranz();
    masa.setProgresExpected(p);
    m.set_Pranz(masa);


    p = m.getCina().getProgresExpected();
 
    p.setConsum((calories * 20) / 100);
    p.setGrasimi((grasimi * 20) / 100);
    p.setProteine((proteine * 20) / 100);
    p.setCarbohidrati((carbohidrati * 20) / 100);
    masa = m.getCina();
    masa.setProgresExpected(p);
    m.set_Cina(masa);



    p = m.getGustari().getProgresExpected();
  
    p.setConsum((calories * 10) / 100);
    p.setGrasimi((grasimi * 10) / 100);
    p.setProteine((proteine * 10) / 100);
    p.setCarbohidrati((carbohidrati * 10) / 100);
    masa = m.getGustari();
   masa.setProgresExpected(p);
    m.set_Gustari(masa);

    
   
    /*  Aici este implementata logica pentru recomandare mancare*/
   /* Practic luam fuecare meniu imparte si in functie de datele care sunt in fisier ii recomandam mancare*/
    Menu m1 = m.getMic_de_Jun();
    vector<Produs> food;
    int v[100],w[100];
   
    for (int i = 0; i < mic_dejun_size; i++)
    {
        v[i] = w[i] = mic_dejunA[i].getValEnergetica();
        dummyData.push_back(mic_dejunA[i].getValEnergetica());
    }
   ///aici avem valoarea maxima pe care o poate avea in urma incercarii de recomandare
    int val_max_mic_dejun = knapsack(v, w, mic_dejun_size, m.getMic_de_Jun().getProgresExpected().getConsum(),0);
    ///prin backtracking obtinem indicii si ce vor face acesti indici este ca dupa ei ne vom  ghida sa stocam restul datelor
    ///pe stiva urcam toate valoriile si indexi si lor
    bkt(0, 0, val_max_mic_dejun);
 
    setVectorZero(v,mic_dejun_size);
    setVectorZero(w,mic_dejun_size);

    ///acuma ce facem este ca setam valorile la valorii recomandate
    ///iteram prin lista cu alimente pentru a face asta

    vector<Aliment> recommended_food;

    for (int i = 0; i < stack.size(); i++)
    {
        recommended_food.push_back(mic_dejunA[indexes[i]]);
    }


   
   
    vector<Produs> products;
    for (int i = 0; i < recommended_food.size(); i++)
    {
        Produs p;
        p.setAliment(recommended_food[i]);
        p.setPortion(1);
        p.setCantitate(recommended_food[i].getCantitate());
        products.push_back(p);
    }


    masa = m.getMic_de_Jun();
    masa.setAlimenteRecomandate(products);
    m.set_Mic_Dejun(masa);
    stack.clear();
    indexes.clear();
    dummyData.clear();
    recommended_food.clear();
    products.clear();

    ///aici o sa avem pranzul

    for (int i = 0; i < pranz_size; i++)
    {
        v[i] = w[i] = pranzA[i].getValEnergetica();
        dummyData.push_back(pranzA[i].getValEnergetica());
    }

    int val_max_pranz = knapsack(v, w, pranz_size, m.getPranz().getProgresExpected().getConsum(), 0);
    ///prin backtracking obtinem indicii si ce vor face acesti indici este ca dupa ei ne vom  ghida sa stocam restul datelor
    bkt(0, 0, val_max_pranz);
    setVectorZero(v, pranz_size);
    setVectorZero(w, pranz_size);

  

    for (int i = 0; i < stack.size(); i++)
    {
        recommended_food.push_back(pranzA[indexes[i]]);
    }




    for (int i = 0; i < recommended_food.size(); i++)
    {
        Produs p;
        p.setAliment(recommended_food[i]);
        p.setPortion(1);
        p.setCantitate(recommended_food[i].getCantitate());
        products.push_back(p);
    }


    masa = m.getPranz();
    masa.setAlimenteRecomandate(products);
    m.set_Pranz(masa);
    stack.clear();
    indexes.clear();
    dummyData.clear();
    recommended_food.clear();
    products.clear();

     

  ////cina 


    for (int i = 0; i < cina_size; i++)
    {
        v[i] = w[i] = cinaA[i].getValEnergetica();
        dummyData.push_back(cinaA[i].getValEnergetica());
    }

    int val_max_cina = knapsack(v, w, cina_size, m.getCina().getProgresExpected().getConsum(), 0);
    ///prin backtracking obtinem indicii si ce vor face acesti indici este ca dupa ei ne vom  ghida sa stocam restul datelor
    bkt(0, 0, val_max_pranz);
    setVectorZero(v, cina_size);
    setVectorZero(w, cina_size);

    

    for (int i = 0; i < stack.size(); i++)
    {
        recommended_food.push_back(cinaA[indexes[i]]);
    }




   
    for (int i = 0; i < recommended_food.size(); i++)
    {
        Produs p;
        p.setAliment(recommended_food[i]);
        p.setPortion(1);
        p.setCantitate(recommended_food[i].getCantitate());
        products.push_back(p);
    }


    masa = m.getCina();
    masa.setAlimenteRecomandate(products);
    m.set_Cina(masa);
    stack.clear();
    indexes.clear();
    dummyData.clear();
    recommended_food.clear();
    products.clear();


    ///aicea facem la gustari

    for (int i = 0; i < gustari_size; i++)
    {
        v[i] = w[i] = pranzA[i].getValEnergetica();
        dummyData.push_back(pranzA[i].getValEnergetica());
    }

    int val_max_gustari = knapsack(v, w, gustari_size, m.getGustari().getProgresExpected().getConsum(), 0);
    ///prin backtracking obtinem indicii si ce vor face acesti indici este ca dupa ei ne vom  ghida sa stocam restul datelor
    bkt(0, 0, val_max_gustari);
    setVectorZero(v, gustari_size);
    setVectorZero(w, gustari_size);


    for (int i = 0; i < stack.size(); i++)
    {
        recommended_food.push_back(gustariA[indexes[i]]);
    }




    for (int i = 0; i < recommended_food.size(); i++)
    {
        Produs p;
        p.setAliment(recommended_food[i]);
        p.setPortion(1);
        p.setCantitate(recommended_food[i].getCantitate());
        products.push_back(p);
    }


    masa = m.getGustari();
    masa.setAlimenteRecomandate(products);
    m.set_Gustari(masa);
    stack.clear();
    indexes.clear();
    dummyData.clear();
    recommended_food.clear();
    products.clear();


 
}

///ce face functia asta este ca itereaza printre toate mealurile pe care le avem in main
///practic pe care le avem in fisier si returneaza una care are data pe care o cautam
///ca dupa sa ne putem juca cu ea si sa putem sa modificam datele ulterior
Meal searchMeal(vector<Meal>& m, string date)
{
    for (int i = 0; i < m.size(); i++)
    {
        if (m[i].getData() == date)
        {
            return m[i];
        }
    }

    Meal m1;
    return m1;
}

bool checkData(string data)
{
    char checker[300] = "^([0-2][0-9]|(3)[0-1])(\\/)(((0)[0-9])|((1)[0-2]))(\\/)\\d{4}$";
    regex str_expr(checker);
    if (regex_match(data, str_expr))
    {
        return true;
    }

    return false;

}


void set_progres(Meal& main_meal, Aliment a, double quantity, double portie,string meal_name)
{
    /*
           Progresul este alcatuit din:
               int consumul;
	           double proteine;
	           double carbohidrati;
	           double grasimi;

  */
    ///practic la progresul existent adaugam noul progres
    ///noul progres va insemna progresul la care adaugam 
    ///noi pentru a putea calcula corect ce facem este ca ne vom folosi de regula de trei simpla
    ///adica daca la x grame care sunt trecute in fisier la capitolul alimente sunt un anume numar
    ///de calorii la cantitatea quantity pe care o avem noi vor fi y kcal

    int consumul = ((quantity * a.getValEnergetica()) / a.getCantitate());
    double proteine = ((quantity * a.getProteine()) / a.getCantitate());
    double carbo = ((quantity * a.getGlucide()) / a.getCantitate());
    double grasimi = ((quantity * a.getGrasimi()) / a.getCantitate());

  
    consumul = consumul * portie;
    proteine = proteine * portie;
    carbo = carbo * portie;
    grasimi = grasimi * portie;
    
    



    ///acuma vom seta un nou progres
    Progres p;
    p.setConsum(consumul);
    p.setProteine(proteine);
    p.setCarbohidrati(carbo);
    p.setGrasimi(grasimi);

    ///si acuma tehnic ar trebui sa avem un operator overloaded pe Progres
    ///asta pentru a-l putea updata doar facand plus fara sa ne chinuim prea mult

    ///si acuma vin setat per menu
    ///am putea trage meniul si dupa sa-l
   
    Progres aux_progres,dummy_progres;
    Menu aux_menu;
    if (meal_name == "Mic Dejun")
    {
       
        aux_menu = main_meal.getMic_de_Jun();
        aux_progres = main_meal.getMic_de_Jun().getProgresReal()+p;
        dummy_progres = main_meal.getMic_de_Jun().getProgresReal();
        aux_menu.setProgresReal(aux_progres);
        main_meal.set_Mic_Dejun(aux_menu);
        main_meal.calculate_progress_real();
    
        

    }
    else if(meal_name == "Pranz")
    {
        aux_menu = main_meal.getPranz();
        aux_progres = aux_menu.getProgresReal() + p;
        aux_menu.setProgresReal(aux_progres);
        main_meal.set_Pranz(aux_menu);
        main_meal.calculate_progress_real();
    }
    else if (meal_name == "Cina")
    {
        aux_menu = main_meal.getCina();
        aux_progres = aux_menu.getProgresReal() + p;
        aux_menu.setProgresReal(aux_progres);
        main_meal.set_Cina(aux_menu);
        main_meal.calculate_progress_real();
    }
    else if (meal_name == "Gustare")
    {
        aux_menu = main_meal.getGustari();
        aux_progres = aux_menu.getProgresReal() + p;
        aux_menu.setProgresReal(aux_progres);
        main_meal.set_Gustari(aux_menu);
        main_meal.calculate_progress_real();
    }
    
   

}