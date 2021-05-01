#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <chrono>
#include <conio.h>
#include <regex>
#include "Produs.h"
#include "Aliment.h"
#include "User.h"
#include "Menu.h"
#include "Meal.h"
#include "Getters-Functions.cpp"
#include "nutritional-values.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;


extern double userkcalPerDay;
extern double userfats;
extern double userglucides;
extern double userfibres;
extern double userproteins;
extern double usersalt;

bool runned = false;
///aici scrierea se va face pe 
///adica se vor scrie alimentele pe mic dejun , pranz , cina si gustari

void writeAlimente()
{

    ///prima data verificam daca fisierul exista
    string nume_fisiere[] = { "mic-dejun.txt","pranz.txt","cina.txt","gustare.txt" };
    string file_name;
    system("cls");
    cout << "Introduceti cifra corespunzatoare mesei careia doriti sa ii atribuiti acest aliment:\n";
    cout << "1.Mic dejun\n";
    cout << "2.Pranz\n";
    cout << "3.Cina\n";
    cout << "4.Gustare\n";

    char c;
    cin >> c;

    while ((isdigit(c) && ((c - '0') != 1 && (c - '0') != 2) && (c - '0') != 3 && (c - '0') != 4) || !isdigit(c))
    {
        cout << "\nIntroduceti o optiune valida va rog!!!\n\n";
        cin >> c;
    }

    switch (c)
    {
    case '1':
        file_name = nume_fisiere[0];
        break;
    case '2':
        file_name = nume_fisiere[1];
        break;
    case '3':
        file_name = nume_fisiere[2];
        break;
    case '4':
        file_name = nume_fisiere[3];
        break;

    }

    fstream f;
    f.open(file_name,ios::app);
    ///acuma va trebui sa introducem obiecte de forma celor care contin
    ///date pentru 
     ///acuma ce facem este ca vom introduce un aliment in fisier

    ///std::string nume, double val_energetica,double grasimi, double glucide, double fibre,double proteine,double cantitate
    system("cls");
    string nume;
    string line;
    double val_energ, grasimi, glucide, fibre, proteine, cantitate, sare;
    cout << "Numele alimentului:";
    fflush(stdin);
    cin.get();
    getline(cin, nume);
    cout << "Introdu valoarea energetica a alimentului:";
    cin >> val_energ;
    cout << "Introdu grasimile:";
    cin >> grasimi;
    cout << "Introdu glucidele:";
    cin >> glucide;
    cout << "Introdu fibrele:";
    cin >> fibre;
    cout << "Proteine:";
    cin >> proteine;
    cout << "Sare:";
    cin >> sare;
    cout << "Cantitate:";
    cin >> cantitate;


    line = "\n" + nume + "," + to_string(val_energ) + "," + to_string(grasimi) + "," + to_string(glucide) + "," + to_string(fibre) + "," + to_string(proteine) + "," + to_string(sare) + "," + to_string(cantitate);
    f << line;
    f.close();
}




void displayData(User u)
{
    system("cls");
    cout << "<<<<<<<===== THIS IS YOUR DATA =======>>>>>>>" << endl;
    cout << "Nume:" << u.getNume() << endl;
    /// name, age, sex, greutate, inaltime, greutate_dorita, b1, a, s1, m
    cout <<"Varsta:" << u.getVarsta() << endl;
    cout <<"Sex:" << (u.getSex() ? "F" : "M") << endl;
    cout <<"Greutate:" << (u.getGreutate()) << " kg" << endl;
    cout <<"Greutate dorita:" << (u.getGreutate_dorita()) << " kg" << endl;
    cout <<"BMI:";
    switch (u.getPersonBmi())
    {
    case Under:
        cout << "Under" << endl;
        break;
    case Norm:
        cout << "Normal" << endl;
        break;
    case Over:
        cout << "Over" << endl;
        break;
    case Obese:
        cout << "Obese" << endl;
        break;
    case ObeseExtreme:
        cout << "Under" << endl;
        break;
    }

    cout << "Activitate:";
    switch (u.getPersonActivity())
    {
    case Sedentar:
        cout << "Sedentar" << endl;
        break;
    case Usoara:
        cout << "Usoara" << endl;
        break;
    case Moderata:
        cout << "Moderata" << endl;
        break;
    case Intensa:
        cout << "Intensa" << endl;
        break;
    }
    cout << "Scop:";

    switch (u.getPersonScope()) {
    case Scadere_in_greutate:
        cout << "Scadere in greutate" << endl;
        break;
    case Mentinere:
        cout << "Mentinere" << endl;
        break;
    case Crestere_in_greutate:
        cout << "Crestere in greutate" << endl;
        break;
    }
    cout << "Tipul de metabolism:";
    switch (u.getPersonMetabolism())
    {
    case Lent:
        cout << "Lent" << endl;
        break;
    case Normal:
        cout << "Normal" << endl;
        break;
    case Rapid:
        cout << "Rapid" << endl;
        break;
    }

    system("pause");
}


///aceasta este doar o functie de afisare aicea

///aici va fi un screen pentru vizualizare date
///pe progres si pe alimente
///la progres vor exista doua optiuni: real si expected
///vizualizare alimente: introduse si recomandate
///
void RealProgress(Meal main_meal)
{
    system("cls");
    Progres p = main_meal.getReal();
    cout << "--->> PROGRES REAL <<-----" << endl;
    cout << "     DATA:" << main_meal.getData() << endl;;
    cout << endl;
    cout << "KCAL:" << p.getConsum() << endl;
    cout << "CARBOHIDRATI:" << p.getCarbohidrati() << endl;
    cout << "GRASIMI:" << p.getGrasimi() << endl;
    cout << "PROTEINE:" << p.getProteine() << endl;

    system("pause");
}

void ExpectedProgress(Meal main_meal)
{
    Progres p = main_meal.getExpected();
    system("cls");
    
    cout << "--->> PROGRES ASTEPTAT <<-----" << endl;
    cout << "     DATA:" << main_meal.getData() << endl;;
    cout << endl;
    cout << "KCAL:" << p.getConsum() << endl;
    cout << "CARBOHIDRATI:" << p.getCarbohidrati() << endl;
    cout << "GRASIMI:" << p.getGrasimi() << endl;
    cout << "PROTEINE:" << p.getProteine() << endl;

    system("pause");

}


///LA MANCARE LE AFISEZI PE CATEGORII
///ADICA PE MESE: mic dejun pranz, cina

void enteredFoods()
{
  ///aici efectiv afisam
    ifstream f("alimente-introduse.txt");
    string line;
    while (!f.eof())
    {
        getline(f, line);
        cout << line << endl;

    }
    f.close();
    cin.get();

}

void recomendedFoods()
{
    ///aicea vor fi mancarurile recomandate

}

///aici ne ocupam de a afisa alimentele introduse
void afisare_alimente_introduse(Meal main_meal)
{

    system("cls");
    cout << "============= MIC DEJUN =============" << endl;
    vector<Produs> data = main_meal.getMic_de_Jun().getAlimenteConsumate();
    cout << "<<<<<------------->>>>>>>" << endl;
    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i].getAliment().getNume() << endl;
        cout<<"Cantitate:"<< data[i].getQuantity()<< endl;
        cout << "Portie:" << data[i].getPortion() << endl << endl;
        cout << "<<<<<------------->>>>>>>" << endl;
    }
    
    cout << endl << endl;
    data.clear();
    data = main_meal.getPranz().getAlimenteConsumate();
    cout << "============= PRANZ =============" << endl;
    cout << "<<<<<------------->>>>>>>" << endl;
    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i].getAliment().getNume() << endl;
        cout << "Cantitate:" << data[i].getQuantity() << endl;
        cout << "Portie:" << data[i].getPortion() << endl << endl;
        cout << "<<<<<------------->>>>>>>" << endl;
    }

    cout << endl << endl;
    data.clear();
    data = main_meal.getCina().getAlimenteConsumate();
    cout << "============= CINA =============" << endl;
    cout << "<<<<<------------->>>>>>>" << endl;
    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i].getAliment().getNume() << endl;
        cout << "Cantitate:" << data[i].getQuantity() << endl;
        cout << "Portie:" << data[i].getPortion() << endl << endl;
        cout << "<<<<<------------->>>>>>>" << endl;
    }

    cout << endl << endl;
    data.clear();
    data = main_meal.getGustari().getAlimenteConsumate();
    cout << "============= GUSTARI =============" << endl;
    cout << "<<<<<------------->>>>>>>" << endl;
    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i].getAliment().getNume() << endl;
        cout << "Cantitate:" << data[i].getQuantity() << endl;
        cout << "Portie:" << data[i].getPortion() << endl << endl;
        cout << "<<<<<------------->>>>>>>" << endl;
    }

    cout << endl;
    system("pause");
}

void afisare_alimente_recomandate(Meal main_meal)
{
    system("cls");
    cout << "============= MIC DEJUN =============" << endl;
    vector<Produs> data = main_meal.getMic_de_Jun().getAlimenteRecomandate();
    cout << "<<<<<------------->>>>>>>" << endl;
    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i].getAliment().getNume() << endl;
        cout << "Cantitate:" << data[i].getQuantity() << endl;
        cout << "Portie:" << data[i].getPortion() << endl << endl;
        cout << "<<<<<------------->>>>>>>" << endl;
    }

    cout << endl << endl;
    data.clear();
    data = main_meal.getPranz().getAlimenteRecomandate();
    cout << "============= PRANZ =============" << endl;
    cout << "<<<<<------------->>>>>>>" << endl;
    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i].getAliment().getNume() << endl;
        cout << "Cantitate:" << data[i].getQuantity() << endl;
        cout << "Portie:" << data[i].getPortion() << endl << endl;
        cout << "<<<<<------------->>>>>>>" << endl;
    }

    cout << endl << endl;
    data.clear();
    data = main_meal.getCina().getAlimenteRecomandate();
    cout << "============= CINA =============" << endl;
    cout << "<<<<<------------->>>>>>>" << endl;
    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i].getAliment().getNume() << endl;
        cout << "Cantitate:" << data[i].getQuantity() << endl;
        cout << "Portie:" << data[i].getPortion() << endl << endl;
        cout << "<<<<<------------->>>>>>>" << endl;
    }

    cout << endl << endl;
    data.clear();
    data = main_meal.getGustari().getAlimenteRecomandate();
    cout << "============= GUSTARI =============" << endl;
    cout << "<<<<<------------->>>>>>>" << endl;
    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i].getAliment().getNume() << endl;
        cout << "Cantitate:" << data[i].getQuantity() << endl;
        cout << "Portie:" << data[i].getPortion() << endl << endl;
        cout << "<<<<<------------->>>>>>>" << endl;
    }

    cout << endl;
    system("pause");
   
}

void viewAlimente(Meal main_meal)
{
    system("cls");
    char c = '0';
    cout << "1.Introduse"<<endl;
    cout << "2.Recomandate"<<endl;
    cin >> c;
    while (isdigit(c) && ((c - '0') != 1 && (c - '0') != 2)||!isdigit(c))
    {
        cout << "\nIntroduceti o optiune valida va rog!!!\n\n";
        cin >> c;
    }
    switch (c)
    {
    case '1':
        afisare_alimente_introduse(main_meal);
        break;
    case '2':
        afisare_alimente_recomandate(main_meal);
        break;
    }
}

void viewProgress(Meal main_meal)
{
    system("cls");
    char c = '0';
    cout << "1.Real" << endl;
    cout << "2.Expected"<<endl;
    cin >> c;
    while ((isdigit(c) && ((c - '0') != 1 && (c - '0') != 2))||!isdigit(c))
    {
        cout << "\nIntroduceti o optiune valida va rog!!!\n\n";
        cin >> c;
    }
    switch (c)
    {
        case '1':
            RealProgress(main_meal);
            break;
        case '2':
            ExpectedProgress(main_meal);
            break;
    }   

}


///ce face functia asta este ca imi aduca produsele sub forma de elemente de tipul Produs
//in vectorul aferent si ce facem este ca 


void setProductData(vector<Produs>&prod,Aliment alim[], int n,string mealName,Meal& main_meal)
{
    ///intram in fisierul cu micul dejun si extragem de acolo toate datele necesare
    /// si dupa ce facem cu ele este ca ne apucam si le afisam ca apoi dupa ce isi alege userul
    ///data sa o putem pune pe 
    Produs p;
   
    ///si acuma vom citi datele intr-un while din fisier
    ///le vom stoca pe toate in aliment
    ///afisam alimentele cu numele mesei aferente
    ///si ce facem este ca intrebam userul de alimentul pe care si-l doreste
    ///sa il i-a si pe langa asta ii cerem si portia cat si cantiatea

    Progres prog;

    cout << "<<<<<------------ " << mealName << " <<<<<------------ " << endl;
    cout << endl << endl;
    int i = 0;
    for ( i = 0; i < n; i++)
    {
        cout << (i+1) << ". " << alim[i].getNume() << endl;
        cout << "Valoare energetica:"<< alim[i].getValEnergetica() << endl;
        cout << "Grasimi:" << alim[i].getGrasimi() << endl;
        cout <<"Glucide:"<< alim[i].getGlucide() << endl;
        cout <<"Fibre:" << alim[i].getFibre() << endl;
        cout <<"Proteine:"<< alim[i].getProteine() << endl;
        cout <<"Sare:"<< alim[i].getSare() << endl;
        cout <<"Cantitate:" << alim[i].getCantitate() << endl;
        cout << endl << endl << endl;
    }
    cout << "Selectati va rog alimentul dorit din lista de mai sus:";
  
    char c = '-';
    cin >> c;
    while (((isdigit(c) && (c < '1' || c>(i+'0')))) || !isdigit(c))
    {
        cout << "\nIntroduceti o optiune valida va rog!!!\n\n";
        cin >> c;
    }
    ///in a avem alimentul care ne intereseaza
    p.setAliment(alim[c - '0'-1]);
    ///si acuma intrebam de cantitate
    cout << "Introduceti cantitea:";
    double qt,portion;
    cin >> qt;
    cout << "Introduceti numarul de portii:";
    cin >> portion;
    p.setCantitate(qt);
    p.setPortion(portion);
   /*
            Progresul este alcatuit din:
                -consum 
                -proteine 
                -carbohidrati
                -grasimi
   
   */


    /// o sa avem doar o functie care va avea ca si parametru si masa unde dorim sa updatam progresul
    ///asa ca se va rezolva totul dintr-un apel de functie
    
    set_progres(main_meal, alim[c - '0' - 1], qt, portion, mealName);
   
    prod.push_back(p);

    ///trebuie updatat si progresul aicea
    char opt = 'z';
    cout << "\n\n Doriti sa continuati sa introduceti produse??(y/n)\n\n";
    cin >> opt;
    if (opt == 'y')
    {   
        cin.get();
        while (opt!='n')
           {
            cout << "\n\nSelectati va rog alimentul dorit din lista de mai sus:";
            
            char c = '-';
            cin >> c;
            while ((isdigit(c) && (c < '1' || c>(i + '0'))) || !isdigit(c))
            {
                cout << "\nIntroduceti o optiune valida va rog!!!\n\n";
                cin >> c;
            }
            ///in a avem alimentul care ne intereseaza
            p.setAliment(alim[c - '0' - 1]);
            ///si acuma intrebam de cantitate
            cout << "Introduceti cantitea:";
            double qt, portion;
            cin >> qt;
            cout << "Introduceti numarul de portii:";
            cin >> portion;
            p.setCantitate(qt);
            p.setPortion(portion);
            ///si acuma dupa ce am setat cantitatea si restul intrebam userul daca mai vrea sa mai introduca produse
            ///aici ce facem este ca updatam progresul si pentru urmatoarele produse pe care le introduce utilizator
             ///are loc o updatare de progres de fiecare data
            set_progres(main_meal, alim[c - '0' - 1], qt, portion, mealName);
            
            prod.push_back(p);
            cout << "\n\n Doriti sa continuati sa introduceti produse??(y/n)\n\n";
            cin >> opt;
        }

    }
    else {
        return;
    }
  
    
}



///in cadrul acestei functii userul are posibilitatea
/// de a introduce alimentele pe care le-a consumat in ziua respectiva
///si le vom stoca si in meal
///care tehnic ar veni stocat in fisier
void calculateProgres()
{
    ///practic eu voi pune cat a consumat
    ///si voi avea un consum real adica chiar cat a consumat
    ///si cat trebuia sa consume

}

int getCalories(Aliment alim[], int n)
{
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += alim[i].getValEnergetica();
    }
    return total;
}


///just some helper functions here
void displayAlimente(Aliment a[],int n)
{
    system("cls");

    for (int i = 0; i < n; i++)
    {
        cout << a[i].getNume() << endl;
    }

    system("pause");
}
template <class T>
void display_vector(vector<T> data)
{
    system("cls");
    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i] << endl;
    }
    system("pause");
}


void enterFood(Meal& main_meal)
{
    ///avem un vector cu alimente
    Aliment alimente[20];
    char opt ='-';
    Menu micDejun = main_meal.getMic_de_Jun()
        , pranz = main_meal.getPranz()
        , cina = main_meal.getCina()
                , gustare = main_meal.getGustari();
   
    ///la progres expected vom seta pe fiecare masa consumul
    

    
    while (opt != '5')
    {
        system("cls");

        cout << "Introduceti masa in cadrul careia ati consumat alimentul:\n";
        cout << "1.Mic dejun\n";
        cout << "2.Pranz\n";
        cout << "3.Cina\n";
        cout << "4.Gustare\n";
        cout << "5.Inapoi\n\n";

        cin >> opt;

        while ((isdigit(opt) &&  ( (opt-'0')<1 || (opt-'0')>'5') || !isdigit(opt)))
        {
            cout << "\nIntroduceti o optiune valida va rog!!!\n\n";
            cin >> opt;
        }
 
        vector<Produs> prodMicDejun = micDejun.getAlimenteConsumate()
            ,prodPranz = pranz.getAlimenteConsumate()
            ,prodCina = cina.getAlimenteConsumate()
            ,prodGustare = gustare.getAlimenteConsumate();

        int n = 0;
      
        switch (opt)
        {
        case '1':
            ///aici retragem alimentele din fisierul mic de jun

            getAlimente(alimente, n, "mic-dejun.txt");
            setProductData(prodMicDejun, alimente, n, "Mic Dejun",main_meal);
            micDejun.setAlimenteConsumate(prodMicDejun);
            ///la mic dejun setam progresul real ca fiind          
            micDejun.calculateProgressReal();
            main_meal.set_Mic_Dejun(micDejun);
         
            break;

        case '2':
            getAlimente(alimente, n, "pranz.txt");
            setProductData(prodPranz, alimente, n, "Pranz",main_meal);
            pranz.setAlimenteConsumate(prodPranz);  
            pranz.calculateProgressReal();
            main_meal.set_Pranz(pranz);
            
            break;
        case '3':
            getAlimente(alimente, n, "cina.txt");
            setProductData(prodCina, alimente, n, "Cina",main_meal);
            cina.setAlimenteConsumate(prodCina);
            cina.calculateProgressReal();
            main_meal.set_Cina(cina);
            break;
        case '4':
            getAlimente(alimente, n, "gustare.txt");
            setProductData(prodGustare, alimente, n, "Gustare",main_meal);
            gustare.setAlimenteConsumate(prodGustare);
            gustare.calculateProgressReal();
            main_meal.set_Gustari(gustare);
            break;
        }
    }

    vector<Produs> p;
    
}


void viewData(Meal& main_meal,vector<Meal>&m)
{
    char c = '0';
  
    Progres pr;
  

    while (c != '4')
    {
        system("cls");
        cout << "1.Vizualizare progres" << endl;
        cout << "2.Vizualizare alimente" << endl;
        cout << "3.Introducere aliment" << endl;
        cout << "4.Inapoi" << endl;
        cout << endl;
        cin >> c;
        while ((isdigit(c) && ((c - '0') != 1 && (c - '0') != 2) && (c - '0') != 3 && (c - '0') != 4)|| !isdigit(c))
        {
            cout << "\nIntroduceti o optiune valida va rog!!!\n\n";
            cin >> c;
        }
        switch (c)
        {
        case '1':
           
            viewProgress(main_meal);
            break;
        case '2':
            viewAlimente(main_meal);
            break;
        case '3':
            
            
            enterFood(main_meal);

            break;
        case '4':
            break;

        }
    }
 
 
}



Meal searchData(vector<Meal> m)
{
    system("cls");
    string data;
    cout << "Introduceti va rog frumos o data (dd/mm/yyyy):" << endl;
    cin >> data;
    while (!checkData(data))
    {
        system("cls");
        cout << "Va rog introduceti o data corecta!(dd/mm/yyyy):";
        cin >> data;
    }
    return searchMeal(m,data);

}


void askOrSearch(Meal& main_meal,vector<Meal> m,bool runn)
{
    if (runn)
        return;
    else {
        system("cls");
        cout << "Doriti sa :" << endl;
        cout << "1.Afisati si modificati datele pentru o noua masa din ziua curenta?" << endl;
        cout << "2.Vizualizati si modificati datele pentru o masa din trecut?" << endl;
        char c = '0';
        cin >> c;
        while ((isdigit(c) && ((c - '0') != 1 && (c - '0') != 2)) || !isdigit(c))
        {
            cout << "\nIntroduceti o optiune valida va rog!!!\n\n";
            cin >> c;
        }
        Meal d;
        switch (c)
        {
        case '1':
            return;
            break;
        case '2':
            d = searchData(m);
            break;

        }

        ///userul aici ar trebui sa aiba doua optiuni
        ///fie continua cautarea fie merge mai departe si i-a o masa default

        c = 't';
        while (d.getData() == "default")
        {
            system("cls");
            cout << "Nu a fost gasita o intrare cu data aferenta! Doriti sa cautati alta data??(y/n)";
            cin >> c;
            while (c != 'y' && c != 'n')
            {
                cout << endl << "Introduceti o optiune valida va rog!! (y/n)" << endl;
                cin >> c;
            }
            switch (c)
            {
            case 'y':
                d = searchData(m);
                break;
            case 'n':
                return;
                break;
            }
        }


        main_meal = d;

    }
   
}

///to do :
/// introdu o functie care sa caute o anumita data in fisier
///ca userul sa lucreze fie cu meal-ul actual fie cu unul precedent
void welcome(User u,Meal& main_meal,vector<Meal>m)
{
   
    char c ='0';
    Progres prog;
   
    while (c != '4')
    {
        
        system("cls");
        cout << "Bun venit!";
        cout << "\n\nAlegeti o optiune va rog:\n";
        cout << "1.Vizualizare alimente\n"; ///aicea afisam alimentele din fisier
        cout << "2.Introducere aliment\n"; ///aicea introducem un aliment in fisierul cu alimente
        cout << "3.Vizualizare date\n"; ///aicea o sa vizualizam progresul si restul datelor
        cout << "4.Intoarcere";///aicea ne ofera posibilitatea de a ne intoarce la ecranul anterior
        cout << endl;
        cin >> c;
       
        while ((isdigit(c) && ((c - '0') != 1 && (c - '0') != 2) && (c - '0') != 3 && (c - '0') != 4) || !isdigit(c))
        {
            cout << "\nIntroduceti o optiune valida va rog!!!\n\n";
            cin >> c;
        }
        switch (c)
        {
        case '1':
            getAlimente();
            break;
        case '2':
            writeAlimente();
            break;
        case '3':
    
           askOrSearch(main_meal,m,runned);
           runned = true;
           viewData(main_meal,m);

            break;
        case '4':
            break;

        }
    }
   
}




void  display_logo()
{
    vector<string> logo;
    fstream f("logo.txt");
    int i = 0;
    string aux;
    while (getline(f, aux)) {
        logo.push_back(aux);
    }
    for (int i = 0; i < logo.size(); i++)
    {
        cout << logo[i];
        cout << endl;
    }

    Sleep(3000);
    system("CLS");


    ///creeare utilizator ce face este ca creeaza alt user
    ///peste cel care este acuma

    ///la creeare user putem creea un user nou
    ///sau putem sa facem alte schimbari
    ///dar schimbarile le facem in edit user

    f.close();
}