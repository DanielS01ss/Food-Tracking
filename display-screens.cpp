#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "User.h"

using namespace std;

///aici scrierea se va face pe fisiere
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

    while (isalpha(c) && ((c - '0') != 1 && (c - '0') != 2) && (c - '0') != 3 && (c - '0') != 4)
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




void toUpperStr(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] > '=a' && s[i] <= 'z')
        {
            s[i] = s[i] - 32;
        }
    }

}

///aceasta este doar o functie de afisare aicea
void getAlimente()
{
    ///ce face aceasta functie este ca va trebuie sa intre in fisierul cu alimente
    ///si ce va face aceasta functie este ca va intra in fisier
    ///si va lua fiecare linie ca pe un string si dupa ce il parsuieste
    ///va atribui alimentele in vector
    system("cls");
    string nume_fisiere[] = { "mic-dejun.txt","pranz.txt","cina.txt","gustare.txt" };
    string file_name;
    int i = 0;

    fstream f;
    ///declaram o linie
    string line, token;
    ///citim aceasta linie din fisier
    size_t pos = 0;
 
    
    for (int i = 0; i < 4; i++)
    {
        f.open(nume_fisiere[i]);
        pos = nume_fisiere[i].find(".");
        token = nume_fisiere[i].substr(0, pos);
      
        cout << "\n\n>>>> " << token << " <<<<<<<\n\n";
        cout << endl << endl;
        while (!f.eof())
        {
            getline(f, line);
            pos = line.find(",");
            token = line.substr(0, pos);
            line.erase(0, pos + 1);
            if (line.size() == 0)
            {
                cout << "\nNu exista alimente aferente acestei mese!!!\n\n";
                break;
            }
            cout << "--------" << token << "--------" << endl;

            pos = line.find(",");
            token = line.substr(0, pos);
            line.erase(0, pos + 1);
            cout << "Valoare energetica:" << token << endl;
            

            pos = line.find(",");
            token = line.substr(0, pos);
            line.erase(0, pos + 1);
           

            pos = line.find(",");
            token = line.substr(0, pos);
            line.erase(0, pos + 1);
            cout << "Glucide:" << token << endl;

            pos = line.find(",");
            token = line.substr(0, pos);
            line.erase(0, pos + 1);
            cout << "Fibre:" << token << endl;

            pos = line.find(",");
            token = line.substr(0, pos);
            line.erase(0, pos + 1);
            cout << "Proteine:" << token << endl;

            pos = line.find(",");
            token = line.substr(0, pos);
            line.erase(0, pos + 1);
            cout << "Sare:" << token << endl;


            pos = line.find(",");
            token = line.substr(0, pos);
            line.erase(0, pos + 1);
            cout << "Cantitate:" << token << endl;
          
        }
        f.close();

    }

    cin.get();
    cin.get();
}

///aici va fi un screen pentru vizualizare date
///pe progres si pe alimente
///la progres vor exista doua optiuni: real si expected
///vizualizare alimente: introduse si recomandate
///
void RealProgress()
{
    cout << "\nHere the real progres will be displayed. Coming soon..." << endl;
    cin.get();
}

void ExpectedProgress()
{
    cout << "\nHere the expected progres will be displayed. Coming soon..." << endl;
    cin.get();
}


///LA MANCARE LE AFISEZI PE CATEGORII
///ADICA PE MESE: mic dejun pranz, cina

void enteredFoods()
{
    ///aicea vor fi pe categorii
    ///alimentele
    ///va fi pe pranz cina, etc
    ///afisezi alimentele pe mic dejun pranz
    ///cu portie etc


}

void recomendedFoods()
{
    ///aicea vor fi mancarurile recomandate

}

void viewAlimente()
{
    system("cls");
    char c = '0';
    cout << "1.Introduse"<<endl;
    cout << "2.Recomandate"<<endl;
    cin >> c;
    while (isalpha(c) && ((c - '0') != 1 && (c - '0') != 2))
    {
        cout << "\nIntroduceti o optiune valida va rog!!!\n\n";
        cin >> c;
    }
    switch (c)
    {
    case 1:
        RealProgress();
        break;
    case 2:
        ExpectedProgress();
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
    while (isalpha(c) && ((c - '0') != 1 && (c - '0') != 2))
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

void enterFood()
{
    ///aicea o sa avem stocarea in fisier a datelor
    ///adica practic vom introduce cate un produs 
    cout << "Here we will enter the food!";

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
        while (isalpha(c) && ((c - '0') != 1 && (c - '0') != 2) && (c - '0') != 3 && (c - '0') != 4)
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
            enteredFoods();
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
        while (isalpha(c) && ((c - '0') != 1 && (c - '0') != 2) && (c - '0') != 3 && (c - '0') != 4)
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

   /// Sleep(3000);
    system("CLS");


    ///creeare utilizator ce face este ca creeaza alt user
    ///peste cel care este acuma

    ///la creeare user putem creea un user nou
    ///sau putem sa facem alte schimbari
    ///dar schimbarile le facem in edit user

    f.close();
}