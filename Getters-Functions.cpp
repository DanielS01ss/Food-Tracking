#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <chrono>
#include <time.h>
#include "Produs.h"
#include "Aliment.h"
#include "User.h"
#include "Menu.h"
#include "Meal.h"

string now()
{
    /*
    ///deci chrono este un namespace mai mult
    /// in el are system clock care ce face este ca returneaza
    ///timpul cu precizie , si este mai expert implementat
    /// pentru ca a fost facut in ideea ca exista diferente 
    ///intre masinile de calcul asa ca a fost implementat asta
    ///iar time point este ceva template sau class
    ///si asta system::clock::now() returneaza timpul curent
    chrono::system_clock::time_point p = chrono::system_clock::now();
    ///variabila folosita pentru a stoca timpul
    ///si cred ca to_time_t returneaza timpul
    ///ca sa il poti stoca tin time_t
    ///cum ar veni il converteste
    ///poate este un operator overloaded
    time_t t = chrono::system_clock::to_time_t(p);
    ///aici am declarat un array pentru ca 
    ///asta accepta functia ctime
    ///care ce face este ca cred ca stocheaza
    ///timpul intr-un char array adica practic string dar in c-style
    char str[26];

    ctime_s(str, sizeof str, &t);
    */
    ///aici se face conversia explicti
    ///la tipul string 
    ///ca si daca punem string st(str) s-ar face conversie
    ///deci da

    time_t tmNow;
    tmNow = time(NULL);
    struct tm t = *localtime(&tmNow);
    string str = to_string(t.tm_mday)+"-"+ to_string(t.tm_mon)+"-"+ to_string(t.tm_year+1900);
    return str;
}

void getAlimente(Aliment alim[], int& k, string fileName)
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
