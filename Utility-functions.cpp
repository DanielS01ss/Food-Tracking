#include <iostream>
#include <string>
#include "Aliment.h"
#include "Progres.h"
#include "Produs.h"

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

