#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <chrono>
#include <time.h>
#include "Utility-functions.cpp"
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
    int day = stoi(to_string(t.tm_mday));
    int month = stoi(to_string(t.tm_mon+1));
    int year = stoi(to_string(t.tm_year + 1900));
    string day_str = (day < 10) ? ("0" + to_string(day)) : (to_string(day));
    string month_str = (month < 10) ? ("0" + to_string(month)) : (to_string(month));
    string year_str = to_string(year);
    
    string str = day_str+"/"+month_str+"/"+year_str;
    return str;
}

void getAlimente(Aliment alim[100], int& k, string fileName)
{
    ///ce face aceasta functie este ca va trebuie sa intre in fisierul cu alimente
    ///si ce va face aceasta functie este ca va intra in fisier
    ///si va lua fiecare linie ca pe un string si dupa ce il parsuieste
    ///va atribui alimentele in vector

    ifstream f(fileName);
    if (!f)
    {
        return;
    }
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



///vectorul cu meals contine toate mesele din toate zilele
///de asta are si un camp cu date

void getUserMealData(vector<Meal>&m ,Aliment mic_dejunA[100],int mic_dejun_size, Aliment pranzA[100],int pranz_size , Aliment cinaA[100],
    int cina_size, Aliment gustariA[100], int gustari_size)
{

    ///acuma vom avea doua variante
    ///daca exista fisierul si daca nu exista fisierul
    ifstream f("logs2.txt");

    if (!f)
    {
        return;
    }

    ///citim pana la finalul fisierului
    string dummy = "default";
    string data;
    string progres;
   
    ///a doua incercare de a scrie o functie de citire corecta a dateleor
   
    bool pass = false;
    while (!f.eof())
    {
        Menu mic_dejun,pranz,cina,gustari;
        Meal meal;

        vector<Produs> al_recomandate;
        vector<Produs> al_consumate;
        ///prima data citim data
        string date;
        ///citim data din fisier
        if (date == "" && pass == false)
            getline(f, date);
        ///setam data pe setDate adica practic setam data pe meal
        if (date == "")
            return;
        pass = true;
        meal.setData(date);
        date = "";
        ///luam progresul din fisier
        ///si il parsuim 

        getline(f, progres);
        Progres p1 = parseProgress(progres);
        meal.set_Expected(p1);

        getline(f, progres);
        Progres p2 = parseProgress(progres);
        
        ///setam progresul real
        meal.set_Real(p2);


        //// DE AICI INCEPE CODUL PER MEAL

        ///setam progresul asteptat
        getline(f, progres);
        p1 = parseProgress(progres);
        mic_dejun.setProgresExpected(p1);

        ///setam progresul real
        getline(f, progres);
        p1 = parseProgress(progres);
        mic_dejun.setProgresReal(p1);
      
        ///acuma citim prima steluta
        getline(f, dummy);
        data = "";
        while (data != "*")
        {
            if (data.size() != 0)
            {
                ///citim alimentul si daca se afla il introduce sub forma de produs
                Produs p = parseAliment(data,"mic-dejun",  mic_dejunA,  mic_dejun_size,  pranzA, pranz_size, cinaA,
                    cina_size, gustariA, gustari_size);
                al_consumate.push_back(p);
            }
            ///citim urmatorul produs
            getline(f, data);
        }
       
        ///data reprezinta de asemenea anumite alimente
        data = "";
        while (data != "*")
        {
            if (data.size() != 0)
            {
                Produs p = parseAliment(data, "mic-dejun", mic_dejunA, mic_dejun_size, pranzA, pranz_size, cinaA,
                    cina_size, gustariA, gustari_size);
                al_recomandate.push_back(p);
            }

            getline(f, data);
        }

        mic_dejun.setAlimenteConsumate(al_consumate);
        mic_dejun.setAlimenteRecomandate(al_recomandate);
   

        al_recomandate.clear();
        al_consumate.clear();
        
        ///PANA AICI

        getline(f, progres);
        p1 = parseProgress(progres);
        pranz.setProgresExpected(p1);

        ///aici ce facem este ca setam progresul pentru pranz
        ///si il parsuim
        getline(f, progres);
        p1 = parseProgress(progres);
        pranz.setProgresReal(p1);


        getline(f, dummy);
        data = "";
        while (data != "*")
        {
            if (data.size() != 0)
            {
                Produs p = parseAliment(data, "pranz", mic_dejunA, mic_dejun_size, pranzA, pranz_size, cinaA,
                    cina_size, gustariA, gustari_size);
                al_consumate.push_back(p);
            }

            getline(f, data);
        }


        data = "";
        while (data != "*")
        {
            if (data.size() != 0)
            {
                Produs p = parseAliment(data, "pranz", mic_dejunA, mic_dejun_size, pranzA, pranz_size, cinaA,
                    cina_size, gustariA, gustari_size);
                al_recomandate.push_back(p);
            }

            getline(f, data);
        }

        pranz.setAlimenteConsumate(al_consumate);
        pranz.setAlimenteRecomandate(al_recomandate);

        al_recomandate.clear();
        al_consumate.clear();

        //////////////////////////////
        getline(f, progres);
        p1 = parseProgress(progres);
        cina.setProgresExpected(p1);


        getline(f, progres);
        p1 = parseProgress(progres);
        cina.setProgresReal(p1);

        getline(f, dummy);


    
        data = "";
        while (data != "*")
        {
            if (data.size() != 0)
            {
                Produs p = parseAliment(data, "cina", mic_dejunA, mic_dejun_size, pranzA, pranz_size, cinaA,
                    cina_size, gustariA, gustari_size);
                al_consumate.push_back(p);
            }

            getline(f, data);
        }


        data = "";
        while (data != "*")
        {
            if (data.size() != 0)
            {
                Produs p = parseAliment(data, "cina", mic_dejunA, mic_dejun_size, pranzA, pranz_size, cinaA,
                    cina_size, gustariA, gustari_size);
                al_recomandate.push_back(p);
            }

            getline(f, data);
        }

        cina.setAlimenteConsumate(al_consumate);
        cina.setAlimenteRecomandate(al_recomandate);


        al_recomandate.clear();
        al_consumate.clear();

        ////si aici mai avem gustarile

        getline(f, progres);
        p1 = parseProgress(progres);
        gustari.setProgresExpected(p1);


        getline(f, progres);
        p1 = parseProgress(progres);
        gustari.setProgresReal(p1);

        getline(f, dummy);



        data = "";
        while (data != "*")
        {
            if (data.size() != 0)
            {
                Produs p = parseAliment(data, "gustare", mic_dejunA, mic_dejun_size, pranzA, pranz_size, cinaA,
                    cina_size, gustariA, gustari_size);
                al_consumate.push_back(p);
            }

            getline(f, data);
        }


        data = "";
        while (data != "*")
        {
            if (data.size() != 0)
            {
                Produs p = parseAliment(data, "gustare", mic_dejunA, mic_dejun_size, pranzA, pranz_size, cinaA,
                    cina_size, gustariA, gustari_size);
                al_recomandate.push_back(p);
            }

            getline(f, data);
        }

        gustari.setAlimenteConsumate(al_consumate);
        gustari.setAlimenteRecomandate(al_recomandate);


        al_recomandate.clear();
        al_consumate.clear();


        ///si aicea ar veni sa setam per meal practic toate mesele
        meal.set_Mic_Dejun(mic_dejun);
        meal.set_Pranz(pranz);
        meal.set_Cina(cina);
        meal.set_Gustari(gustari);
        //getline(f, dummy);
        ///aici ce trebuie sa facem este ca daca mai e sa ramana stelute ce trebuie
        ///sa le stergem
        ///facem stergere de stelute
        getline(f, dummy);
        if (dummy == "*")
        {
            while (dummy == "*")
                getline(f, dummy);  
            date = dummy;
        }
        m.push_back(meal);
    } 
  
}
