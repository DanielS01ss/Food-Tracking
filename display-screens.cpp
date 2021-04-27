#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <chrono>
#include <conio.h>
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
void RealProgress()
{
    ifstream f("progres-real-menu.txt");
    string line;
   
    while (!f.eof())
    {
        getline(f, line);
        cout << "Data:" << line << "\n";
        cout << "-----Mic dejun-----\n";
        getline(f, line);
        cout << "Consum:" << line << endl;
        getline(f, line);
        cout << "Carbohidrati:" << line << endl;
        getline(f, line);
        cout << "Grasimi:" << line << endl;

        cout << "-----Pranz-----\n";
        getline(f, line);
        cout << "Consum:" << line << endl;
        getline(f, line);
        cout << "Carbohidrati:" << line << endl;
        getline(f, line);
        cout << "Grasimi:" << line << endl;
        cout << endl << endl;
        cout << "-----Cina-----\n";
        getline(f, line);
        cout << "Consum:" << line << endl;
        getline(f, line);
        cout << "Carbohidrati:" << line << endl;
        getline(f, line);
        cout << endl << endl;
        cout << "Grasimi:" << line << endl;
        cout << endl << endl;
        cout << "----Gustari----\n";
        getline(f, line);
        cout << "Consum:" << line << endl;
        getline(f, line);
        cout << "Carbohidrati:" << line << endl;
        getline(f, line);
        cout << "Grasimi:" << line << endl;
        cout << endl << endl;
    }
    f.close();
    system("pause");


}

void ExpectedProgress()
{
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

void afisare_alimente_introduse()
{

    ifstream f("alimente-introduse.txt");
    string line;
    while (!f.eof())
    {
        getline(f, line);
        cout << line << endl;
    }
    system("pause");
    system("pause");
}

void afisare_alimente_recomandate()
{
    system("pause");
}

void viewAlimente()
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
        afisare_alimente_introduse();
        break;
    case '2':
        afisare_alimente_recomandate();
        break;
    }
}

void viewProgress()
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
            RealProgress();
            break;
        case '2':
            ExpectedProgress();
            break;
    }   

}

///in functia asta ce facem este ca avem o functie care
///ce va face este ca ne va afisa mesele si cand userul selecteaza o masa
///ii afisam alimentele aferente acelei mese iar el ce va face este ca va selecta una din lista
///si alimentele selectate le stocam intr-un vector 

void setProductData(vector<Produs>&prod,Aliment alim[], int n,string mealName)
{
    ///intram in fisierul cu micul dejun si extragem de acolo toate datele necesare
    /// si dupa ce facem cu ele este ca ne apucam si le afisam ca apoi dupa ce isi alege userul
    ///data sa o putem pune pe 
    Produs p;
    system("cls");
    ///si acuma vom citi datele intr-un while din fisier
    ///le vom stoca pe toate in aliment
    ///afisam alimentele cu numele mesei aferente
    ///si ce facem este ca intrebam userul de alimentul pe care si-l doreste
    ///sa il i-a si pe langa asta ii cerem si portia cat si cantiatea

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
    cout << "Introduceti portia:";
    cin >> portion;
    p.setCantitate(qt);
    p.setPortion(portion);
    ///si acuma dupa ce am setat cantitatea si restul intrebam userul daca mai vrea sa mai introduca produse
    prod.push_back(p);

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
            cout << "Introduceti portia:";
            cin >> portion;
            p.setCantitate(qt);
            p.setPortion(portion);
            ///si acuma dupa ce am setat cantitatea si restul intrebam userul daca mai vrea sa mai introduca produse
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

void writeChosenFood(vector<Produs> p,string meal)
{
    ofstream f;
    f.open("alimente-introduse.txt", ios::app);
    f << "---->> "<< meal <<" <<----\n";
    for (int i = 0; i < p.size(); i++)
    {
        ///aici afisam ulterior datele calculate
        string line;
        line = p[i].getAliment().getNume();
        f << line<<endl;
        line = "Cantitate:" + to_string(p[i].getQuantity());
        f << line <<endl;
        line = "Portie:" + to_string(p[i].getPortion());
        f << line << endl;
        
        
    }
    f.close();
  
}

void writeRecommendedFood()
{

}

void enterFood()
{
    
    Aliment alimente[20];
    char opt ='-';
    Menu micDejun, pranz, cina, gustare;
    Meal m;
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
 
        vector<Produs> prodMicDejun,prodPranz,prodCina,prodGustare;
        int n = 0;
        switch (opt)
        {
        case '1':

            getAlimente(alimente, n, "mic-dejun.txt");
            setProductData(prodMicDejun, alimente, n, "Mic Dejun");
            ///si aicea vem si logica progres pe masa
            micDejun.setAlimenteConsumate(prodMicDejun);
            micDejun.getProgresExpected().setConsum(getCalories(alimente,n));
            writeChosenFood(prodMicDejun,"Mic dejun");
            micDejun.calculateProgressReal();
            break;

        case '2':
            getAlimente(alimente, n, "pranz.txt");
            setProductData(prodPranz, alimente, n, "Pranz");
            pranz.setAlimenteConsumate(prodPranz);
            pranz.calculateProgressReal();
            pranz.getProgresExpected().setConsum(getCalories(alimente, n));
            writeChosenFood(prodPranz,"Pranz");
            break;
        case '3':
            getAlimente(alimente, n, "cina.txt");
            setProductData(prodCina, alimente, n, "Cina");
            cina.setAlimenteConsumate(prodCina);
            cina.calculateProgressReal();
            cina.getProgresExpected().setConsum(getCalories(alimente, n));
            writeChosenFood(prodCina,"Cina");
            break;
        case '4':
            getAlimente(alimente, n, "gustare.txt");
            setProductData(prodGustare, alimente, n, "Gustare");
            gustare.setAlimenteConsumate(prodGustare);
            gustare.calculateProgressReal();
            gustare.getProgresExpected().setConsum(getCalories(alimente, n));
            writeChosenFood(prodGustare,"Gustare");
            break;
        }
    }
        
    ///acuma aicea stocam restul datelor in meal
    ///adica practic datele introduse le stocam in meal
    m.set_Mic_Dejun(micDejun);
    m.set_Gustari(gustare);
    m.set_Pranz(pranz);
    m.set_Cina(cina);
    ///aici vom seta si data
    m.setData(now());

    ///acuma vom creea o functie in produs si acolo vom calcula progresul
    ///ca dupa sa apelam functia aceasta
    ofstream f;
    f.open("progres-real-meal.txt",ios::app);
    f << m;
    f.close();

    ofstream g;
    g.open("progres-real-menu.txt",ios::app);

    
    string data = now();

    g << data<<endl;
    g << micDejun;
    g << pranz;
    g << cina;
    g <<gustare;


    g.close();
}

void viewData()
{
    char c = '0';

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
            viewProgress();
            break;
        case '2':
            viewAlimente();
            break;
        case '3':
            enterFood();
            break;
        case '4':
            break;

        }
    }

}

void welcome(User u)
{
   
    char c ='0';
    
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
            viewData();
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