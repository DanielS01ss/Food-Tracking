#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Produs.h"
#include "Aliment.h"
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




void getAlimente(Aliment alim[], int& k,string fileName)
{
    ///ce face aceasta functie este ca va trebuie sa intre in fisierul cu alimente
    ///si ce va face aceasta functie este ca va intra in fisier
    ///si va lua fiecare linie ca pe un string si dupa ce il parsuieste
    ///va atribui alimentele in vector

    ifstream f(fileName);
    ///declaram o linie
    string line, token;
    ///citim aceasta linie din fisier

    size_t pos = 0;
    int i = 0;
    /*
    std::string nume
    double val_energetica
    double grasimi
    double glucide
    double fibre
    double proteine
    double sare
    double cantitate
    */
    while (!f.eof())
    {
        getline(f, line);
        pos = line.find(",");
        token = line.substr(0, pos);
        line.erase(0, pos + 1);
        alim[i].setNume(token);

        pos = line.find(",");
        token = line.substr(0, pos);
        line.erase(0, pos + 1);
        alim[i].setValEnergetica(stod(token));

        pos = line.find(",");
        token = line.substr(0, pos);
        line.erase(0, pos + 1);
        alim[i].setGrasimi(stod(token));

        pos = line.find(",");
        token = line.substr(0, pos);
        line.erase(0, pos + 1);
        alim[i].setGlucide(stod(token));

        pos = line.find(",");
        token = line.substr(0, pos);
        line.erase(0, pos + 1);
        alim[i].setFibre(stod(token));

        pos = line.find(",");
        token = line.substr(0, pos);
        line.erase(0, pos + 1);
        alim[i].setProteine(stod(token));

        pos = line.find(",");
        token = line.substr(0, pos);
        line.erase(0, pos + 1);
        alim[i].setSare(stod(token));


        pos = line.find(",");
        token = line.substr(0, pos);
        line.erase(0, pos + 1);
        alim[i].setCantitate(stod(token));
        i++;
    }
    k = i;
   


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
    while (isdigit(c) && ((c - '0') != 1 && (c - '0') != 2)||!isdigit(c))
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
        cout << alim[i].getValEnergetica() << endl;
        cout << alim[i].getGrasimi() << endl;
        cout << alim[i].getGlucide() << endl;
        cout << alim[i].getFibre() << endl;
        cout << alim[i].getProteine() << endl;
        cout << alim[i].getSare() << endl;
        cout << alim[i].getCantitate() << endl;
        cout << endl << endl << endl;
    }
    cout << "Selectati va rog alimentul dorit din lista de mai sus:";
  
    char c = '-';
    cin >> c;
    while ((isdigit(c) && (c < '1' || c>(char)i)) || !isdigit(c))
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
        while (opt!='n')
        {
            cout << "\n\nSelectati va rog alimentul dorit din lista de mai sus:";
            
            char c = '-';
            cin >> c;
            while ((isdigit(c) && (c < '1' || c>(char)i)) || !isdigit(c))
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




void enterFood()
{
    
    Aliment alimente[20];
    system("cls");
    cout << "Introduceti masa in cadrul careia ati consumat alimentul:\n";
    cout << "1.Mic dejun\n";
    cout << "2.Pranz\n";
    cout << "3.Cina\n";
    cout << "4.Gustare";
    char opt;
    cin.get();
    cin >> opt;

    while ((isdigit(opt) && ((opt - '0') != 1 && (opt - '0') != 2))||!isdigit(opt))
    {
        cout << "\nIntroduceti o optiune valida va rog!!!\n\n";
        cin >> opt;
    }

    ///in cazul micului dejun
    ///deci noi afisam toate alimentele userului
    ///si ce face el este ca va alege un aliment
    ///si noi vom creea o instanta a clasei produs
    ///si vom stoca acolo produsul
    ///produs are un camp aliment unde vin stocat alimentul
    ///dar are si portia cat si cantiatea
    vector<Produs> prod;
    int n = 0;
    ///la cazul cerem produsele pentru micul dejun si le stocam 
    switch (opt)
    {
    case '1':

        getAlimente(alimente, n, "mic-dejun.txt");
        setProductData(prod, alimente, n, "Mic Dejun");
    case '2':
        getAlimente(alimente, n, "pranz.txt");
        setProductData(prod, alimente, n, "Pranz");
    case '3':
        getAlimente(alimente, n, "cina.txt");
        setProductData(prod, alimente, n, "Cina");

    case '4':
        getAlimente(alimente, n, "gustare.txt");
        setProductData(prod, alimente, n, "Gustare");
    }

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

   /// Sleep(3000);
    system("CLS");


    ///creeare utilizator ce face este ca creeaza alt user
    ///peste cel care este acuma

    ///la creeare user putem creea un user nou
    ///sau putem sa facem alte schimbari
    ///dar schimbarile le facem in edit user

    f.close();
}