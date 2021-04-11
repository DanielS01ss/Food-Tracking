#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include "User.h"
#include "enums.h"
#include "Aliment.h"
#include "calculator-functions.cpp"
#include "display-screens.cpp"
using namespace std;


///aici putem face fisiere pentru a putea stoca pentru fiecare meniu al zilei imparte
///adica daca e sa introduca 

//// progresul reprezinta ce a mancat
///


/*

    !!!!! LA SEX
    LA SEX MASCULIN ESTE 0 IAR FEMINIM ESTE 1 


*/



///noi aici o sa avem de creeat un user
///userul acesta este folosit doar o data
///adica per aplicatie vom avea doar un singur user

void editUser(User &d)
{
    system("cls");
    char option;

    /*cout << "------->>>>>  EDITARE UTILIZATOR  <<<<<----------\n\n";
    cout << endl << endl;
    cout << "1.  Nume:" << d.getNume() << endl;
    cout << "2.  Varsta:" << d.getVarsta() << endl;
    cout << "3.  Sex:" << (d.getSex() ? "F" : "M") << endl;
    cout << "4. Greutate:" << d.getGreutate() << endl;
    cout << "5. Inaltime:" << d.getInaltime() << endl;
    cout << "6. Greutate_dorita:" << d.getGreutate_dorita() << endl;
    Activitate a = d.getPersonActivity();
    cout << "7.Activitate:";
    switch (a)
    {
    case Sedentar:
        cout << "Sendetar" << endl;;
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
    cout << "8. Exit" << endl;
    cout << "\n\n\n Introduceti datele indexul datei pe care doriti sa o modificati!" << endl;
    option = getchar();*/
    option = 0;

    while (option!='8')
    {

        cout << "------->>>>>  EDITARE UTILIZATOR  <<<<<----------\n\n";
        cout << endl << endl;
        cout << "1.  Nume:" << d.getNume() << endl;
        cout << "2.  Varsta:" << d.getVarsta() << endl;
        cout << "3.  Sex:" << (d.getSex() ? "F" : "M") << endl;
        cout << "4. Greutate:" << d.getGreutate() << endl;
        cout << "5. Inaltime:" << d.getInaltime() << endl;
        cout << "6. Greutate_dorita:" << d.getGreutate_dorita() << endl;
        Activitate a = d.getPersonActivity();
        cout << "7.Activitate:";
        switch (a)
        {
        case Sedentar:
            cout << "Sendetar" << endl;;
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
        cout << "8. Exit" << endl;
        cout << "\n\n\n Introduceti datele indexul datei pe care doriti sa o modificati!" << endl;
        fflush(stdin);
        cin.get();
        option = getchar();
        ///acuma vine o reverificare a datelor si o operare a optiunii

        if (option == '1')
        {
            system("cls");
            string nume;
            cout << "Introdu numele:";
            cin >> nume;
            d.setNume(nume);
            system("cls");
        }
        else if (option == '2')
        {

            system("cls");
            int age;
            cout << "Introdu varsta:";
            cin >> age;
            d.setVarsta(age);
            system("cls");
        }
        else if (option == '3')
        {
            bool sex;
            char gender;
            cin >> gender;
            while (gender != 'M' && gender != 'F' && gender != 'm' && gender != 'f')
            {
                cout << "\n\n\INTRODUCETI CORECTUL SEXUL!!!!\n\n";
                cout << "Sex(M\F):";
                cin >> gender;
            }
            gender = tolower(gender);
            if (gender == 'm')
                sex = 0;
            else
                sex = 1;
            
            d.setSex(sex);
        }
        else if (option == '4')
        {
            system("cls");
            double greutate;
            cout << "Introdu greutatea:";
            cin >> greutate;
            d.setGreutate(greutate);
            double height = d.getInaltime();
            double bmi_number = greutate / (height* height);
            ///aici o sa ave asa:
            ///vom analiza care este bmi-ul in functie de rezultatul pe care l-am obtinut

            BMI b1;
            if (bmi_number < 18.5)
            {
                b1 = Under;
            }
            else if (bmi_number >= 18.5 && bmi_number < 25)
            {
                b1 = Normal;
            }
            else if (bmi_number >= 25 && bmi_number < 30)
            {
                b1 = Over;
            }
            else if (bmi_number >= 30 && bmi_number < 40)
            {
                b1 = Obese;
            }
            else {
                b1 = ObeseExtreme;
            }

            Scop s1;
            double greutate_dorita = d.getGreutate_dorita();
           
            if (greutate == greutate_dorita)
            {
                s1 = Mentinere;
            }
            else if (greutate_dorita > greutate)
            {
                s1 = Crestere_in_greutate;
            }
            else if (greutate_dorita < greutate)
            {
                s1 = Scadere_in_greutate;
            }

            d.setPersonalScope(s1);
            d.setPersonBMI(b1);

            system("cls");
        }
        else if (option == '5')
        {
            system("cls");
            double inaltime;
            cout << "Inaltime:";
            cin >> inaltime;

            double bmi_number = d.getGreutate()/ (inaltime * inaltime);
            ///aici o sa ave asa:
            ///vom analiza care este bmi-ul in functie de rezultatul pe care l-am obtinut

            BMI b1;
            if (bmi_number < 18.5)
            {
                b1 = Under;
            }
            else if (bmi_number >= 18.5 && bmi_number < 25)
            {
                b1 = Normal;
            }
            else if (bmi_number >= 25 && bmi_number < 30)
            {
                b1 = Over;
            }
            else if (bmi_number >= 30 && bmi_number < 40)
            {
                b1 = Obese;
            }
            else {
                b1 = ObeseExtreme;
            }
            d.setPersonBMI(b1);
            d.setInaltime(inaltime);
            system("cls");
        }
        else if (option == '6')
        {
            system("cls");
            double greutateDorita;
            cout << "Introdu greutatea dorita:";
            cin >> greutateDorita;
            d.setGreutateDorita(greutateDorita);

            Scop s1;
            double greutate_dorita = d.getGreutate_dorita();
            double greutate = d.getGreutate();
            if (greutate == greutate_dorita)
            {
                s1 = Mentinere;
            }
            else if (greutate_dorita > greutate)
            {
                s1 = Crestere_in_greutate;
            }
            else if (greutate_dorita < greutate)
            {
                s1 = Scadere_in_greutate;
            }

            d.setPersonalScope(s1);
            system("cls");

        }
        else if (option == '7')
        {
            system("cls");
            Activitate a;
            int actv;
            cout << "\n\nIntroduceti cifra corespunzatoarea tipului de activitate pe care o intreprindeti:\n";
            cout << "1.Sendentar\n";
            cout << "2.Usoara\n";
            cout << "3.Moderata\n";
            cout << "4.Intensa\n";
            cin >> actv;
            switch (actv)
            {
            case 1:
                a = Sedentar;
                break;

            case 2:
                a = Usoara;
                break;

            case 3:
                a = Moderata;
                break;

            case 4:
                a = Intensa;
                break;
            }
            d.setPersonActivity(a);
            system("cls");
        }
        else if (option == '8')
        {

            break;
        }

    }

    

    ///aici revine o rescriere in fisier a noului utilizator care practic este creeat prin
    ///modificarea celui curent
    ///si acuma ce face este ca rescriem userul in fisierul nostru
    ofstream f("users.txt");
    string line = d.getNume()+ " , " + to_string(d.getVarsta()) + " , " + to_string(d.getSex()) + " , " + to_string(d.getGreutate()) + " , " + to_string(d.getInaltime()) + " , " + to_string(d.getGreutate_dorita()) + " , " + to_string(d.getPersonBmi()) + " , " + to_string(d.getPersonActivity()) + " , " + to_string(d.getPersonScope()) + " , " + to_string(d.getPersonMetabolism());
    f << line;
    f.close();

}


User createUser()
{
    ///aici ce vom face este ca vom citi datele pentru user si apoi il vom stoca in fisier
    system("cls");

    ifstream g("users.txt");
    fflush(stdin);
    if (g)
    {   
        fflush(stdin);
        cin.get();
        system("cls");
        cout << "!!!!ATENTIE !!!! USER DEJA EXISTA!!" << endl;
        cout << "Doriti sa il stergeti si sa creati alt user (y/n)" << endl;
        char response = getchar();
        response = tolower(response);

        if (response == 'y')
        {
            ///aici apelam functia care ce va face este ca ne va
            ///modifica userul
           // g.close();
            g.close();
        }
        else {
            ///si aici vom sterge ecranul
            system("cls");
            //g.close();
            g.close();
            User u;
            return u;
        }
    }
  
    ofstream f("users.txt");
    ///am deschis fisierul in modul append pentru a putea adauga la finalul fisierului
    ///vom avea de adaugat anumite 
    


    ///acuma ce facem este ca 
    ///vom adauga la finalul listei
    ///si vreau sa fie ceva la modul

    /*  Prima data vom citi datele si apoi vom initializa obiectul  */
    std::string name;
    int age;
    bool sex;
    double greutate, inaltime, greutate_dorita;

    cout << "\n\n-------<<<<<< DATE UTILIZATOR >>>>-----------\n\n";
    cout << "\n\n\n";
    cout << "Name:";
    cin >> name;



    cout << "Age:";
    cin >> age;
    cout << "Sex(M/F):";
    char gender;
    cin >> gender;
    while (gender != 'M' && gender != 'F' && gender != 'm' && gender != 'f')
    {
        cout << "\n\n\INTRODUCETI CORECTUL SEXUL!!!!\n\n";
        cout << "Sex(M\F):";
        cin >> gender;
    }
    gender = tolower(gender);
    if (gender == 'm')
        sex = 0;
    else
        sex = 1;

    cout << "\nGreutate:";
    cin >> greutate;

    /*
        Chestii pe care le introduce userul
         greutate dorita
         activitate
         Scop



    */

    cout << "Introduceti greutatea la care doriti sa ajungeti:";
    cin >> greutate_dorita;

    cout << "Introduceti inaltimea:";
    cin >> inaltime;

    Activitate a;
    int actv;
    cout << "\n\nIntroduceti cifra corespunzatoarea tipului de activitate pe care o intreprindeti:\n";
    cout << "1.Sendentar\n";
    cout << "2.Usoara\n";
    cout << "3.Moderata\n";
    cout << "4.Intensa\n";
    cin >> actv;
    switch (actv)
    {
    case 1:
        a = Sedentar;
        break;

    case 2:
        a = Usoara;
        break;

    case 3:
        a = Moderata;
        break;

    case 4:
        a = Intensa;
        break;
    }

    /*
        Aceasta este partea pe care o calculeaza programul
         BMI:
         Metabolism
         SCOP -> il determinam pe baza greutatii
    */

    //BMI = greutate / inaltime^2
    double bmi_number = greutate / (inaltime * inaltime);
    ///aici o sa ave asa:
    ///vom analiza care este bmi-ul in functie de rezultatul pe care l-am obtinut

    BMI b1;
    if (bmi_number < 18.5)
    {
        b1 = Under;
    }
    else if (bmi_number >= 18.5 && bmi_number < 25)
    {
        b1 = Normal;
    }
    else if (bmi_number >= 25 && bmi_number < 30)
    {
        b1 = Over;
    }
    else if (bmi_number >= 30 && bmi_number < 40)
    {
        b1 = Obese;
    }
    else {
        b1 = ObeseExtreme;
    }

    ///vom merge pe ceea ce a introdus userul
    Scop s1;
    if (greutate_dorita == greutate)
    {
        s1 = Mentinere;
    }
    else if (greutate_dorita > greutate)
    {
        s1 = Crestere_in_greutate;
    }
    else if (greutate_dorita < greutate)
    {
        s1 = Scadere_in_greutate;
    }

    ///trebuie sa stabilim metabolismul
    ///si avem asa

    Metabolism m;
    if (a == Sedentar)
    {
        switch (b1)
        {
        case Over:
        case Obese:
        case ObeseExtreme:
            m = Lent;
            break;
        case Normal:
            m = Norm;
            break;
        case Under:
            m = Rapid;
            break;
        }

    }
    /*
       Activitate -> usoara -> obese & obese extreme sau over  == > lent
                            -> normal ==> normal
                            ->  under => rapid

   */

    else if (a == Usoara)
    {
        switch (b1)
        {
        case Over:
        case Obese:
        case ObeseExtreme:
            m = Lent;
            break;
        case Normal:
            m = Norm;
            break;
        case Under:
            m = Rapid;
            break;
        }
    }
    else if (a == Moderata)
    {

        switch (b1) {

        case Obese:
        case ObeseExtreme:
            m = Lent;
            break;
        case Over:
        case Normal:
            m = Norm;
            break;
        case Under:
            m = Rapid;
            break;

        }

    }
    else if (a == Intensa)
    {
        switch (b1) {

        case Over:
        case Obese:
        case ObeseExtreme:
            m = Lent;
            break;
        case Normal:
            m = Norm;
            break;
        case Under:
            m = Rapid;
            break;
        }
    }
    //nume varsta sex greutate inaltime greutate dorita bmi activitate scop metabolism

    User u(name, age, sex, greutate, inaltime, greutate_dorita, b1, a, s1, m);
    ///toate acestea vin adaugate la fisier
    ///si le vom scrie
    string line = name + " , " + to_string(age) + " , " + to_string(sex) + " , " + to_string(greutate) + " , " + to_string(inaltime) + " , " + to_string(greutate_dorita) + " , " + to_string(b1) + " , " + to_string(a) + " , " + to_string(s1) + " , " + to_string(m);
    f << line;
    f.close();
    return u;

}








void login(User u)
{
    ///aici trebuie sa citim datele si sa facem gathering

    welcome(u);


}

///ce face functia de data gathering este ca ne returneaza toate datele #
///de care avem nevoie si ni le returneaza sub forma de obiect user

User dataGathering()
{
  
    User u;
    ///vom lua practic primul user
    ///si dupa vedem
    ifstream f("users.txt");
    ///si citim o linie apoi o separam
    string line;
    getline(f, line);
    ///acuma stringul asta va fi spart pe tokenuri
    //nume varsta sex greutate inaltime greutate dorita bmi activitate scop metabolism

    /*
     !!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    INTREBARE
      CE fel de data type este size_t????????
    !!!!!!!!!!!!!!!!!!!!!!!!!!!
    */

    //nume
    size_t pos = 0;
    pos = line.find(",");
    string token = line.substr(0, pos);
    line.erase(0, pos + 1);
    u.setNume(token);

    //varsta
    pos = line.find(",");
    token = line.substr(0, pos);
    line.erase(0, pos + 1);
    u.setVarsta(stoi(token));
    ///ce face string::npos???

    ///sex
    pos = line.find(",");
    token = line.substr(0, pos);
    line.erase(0, pos + 1);
    u.setSex(stoi(token));

    ///greutate
    pos = line.find(",");
    token = line.substr(0, pos);
    line.erase(0, pos + 1);
    u.setGreutate(stod(token));

    ///inaltime
    pos = line.find(",");
    token = line.substr(0, pos);
    line.erase(0, pos + 1);
    u.setInaltime(stod(token));

    ///greutate dorita
    pos = line.find(",");
    token = line.substr(0, pos);
    line.erase(0, pos + 1);
    u.setGreutateDorita(stod(token));


    ///bmi
    pos = line.find(",");
    token = line.substr(0, pos);
    line.erase(0, pos + 1);
    u.setPersonBMI((BMI)stoi(token));

    ///activitate
    pos = line.find(",");
    token = line.substr(0, pos);
    line.erase(0, pos + 1);
    u.setPersonActivity((Activitate)stoi(token));


    ///scop
    pos = line.find(",");
    token = line.substr(0, pos);
    line.erase(0, pos + 1);
    u.setPersonalScope((Scop)stoi(token));

    ///metabolism
    pos = line.find(",");
    token = line.substr(0, pos);
    line.erase(0, pos + 1);
    u.setPersonMetabolism((Metabolism)stoi(token));
    f.close();
    return u;
}

bool existsUser()
{
    ifstream f("users.txt");
    if (f)
    {
        string line;
        f >> line;
        if (line.size() == 0)
            return false;
        return true;
    } 
    return false;
}



///To do reimplementeaza functia asta
///ca sa returneze alimentele pe fisiere si pe mese ale zilei
///va fi cate un vector pentru fiecare masa a zilei

void getAlimente(Aliment alim[], int &k)
{
    ///ce face aceasta functie este ca va trebuie sa intre in fisierul cu alimente
    ///si ce va face aceasta functie este ca va intra in fisier
    ///si va lua fiecare linie ca pe un string si dupa ce il parsuieste
    ///va atribui alimentele in vector

    ifstream f("alimente.txt");
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
     ///setam pozitia la 0
     
     ///cautam prima virgula
     ///si returnam pozitia primei virgule
     
     ///ce avem pana la prima virgula care a fost mentionat ca si pozitie
     /// vom lua si vom stoca intr-un token
     ///si token practic este prima chestie care ne intereseaza
     ////adica daca avem ceva la modul name calories si fat
     ///ce va face este ca va
    
     ///dupa acesta vom sterge totul pana la token inclusiv
     

}

///acuma ce mai trebuie sa facem este sa creem functia care ne calculeaza 
///cat trebuie sa consume userul nostru
///baza pe preferinte


///trebuie verificat daca am un user
///daca am user atunci ce voi face este ca voi
///trage datele si voi calcula datele aferente pentru consumul caloric
///zilnic al acestuia
///daca nu voi pastra chestia asta ca nu am user si voi cere creeare
///unuia daca acesta nu exista

int main()
{
    
    User u1;
    Aliment a[10];
    int nr = 0;
    getAlimente(a, nr);


    double kcalPerDay, fats, glucides, fibres, proteins, salt;
    kcalPerDay = calculateKcals(u1);
    fats = calculateFats(u1, kcalPerDay);
    fibres = calculateFibres(kcalPerDay);
    glucides = calculateCarbs(u1, kcalPerDay);
    proteins = calculateProteins(u1, kcalPerDay);
    display_logo();

    ///daca userul nu exista
    ///trebuie sa creem unul
    ///si asta trebuie sa fie necesar
    ///adica sa nu pot intra in alte functii de afisare si editare daca nu am user
    bool userExists = existsUser();
    ///daca nu avem user fortam creeare unuia!!
    ///si dupa ce facem este ca vom merge mai departe cu meniul
    char c = '0';
  
    if(userExists)
        u1 = dataGathering();

    while (c != '4')
    {
        fflush(stdin);
        system("cls");
        cout << "1.Creeare User\n";
        cout << "2.Afisare User\n";
        cout << "3.Editare User\n";
        cout << "4.Accesare User\n";
        cout << "5.Iesire\n";
        cout << endl << endl;
        cin >> c;
        while (isalpha(c) && ((c - '0') != 1 && (c - '0') != 2) && (c - '0') != 3 && (c - '0') != 4)
        {
            cout << "\nIntroduceti o optiune valida va rog!!!\n\n";
            cin >> c;
        }
        
        if (userExists)
        {
           
            switch (c)
            {
            case '1':
                u1 = createUser();
                Sleep(1000);
                ///welcome(u1);
                break;
            case '2':
                u1 = dataGathering();
                displayData(u1);
                //welcome(u1);
                break;
            case '3':
                editUser(u1);
                //welcome(u1);
                break;
            case '4':
                welcome(u1);
                break;
            case '5':
                exit(0);
                break;
            
            }


        }
        else {

         
            while (c != '4' && c != '1')
            {
                
                cout << "\n!!! Nu exista niciun user, va rog creeati unul folosind optiune 1 din lista!!\n";
                cin >> c;
                while (isalpha(c) && ((c - '0') != 1 && (c - '0') != 2) && (c - '0') != 3 && (c - '0') != 4)
                {
                    cout << "\nIntroduceti o optiune valida va rog!!!\n\n";
                    cin >> c;
                }
                
            }

            switch (c)
            {
            case '1':
                u1 = createUser();
                Sleep(1000);
                welcome(u1);
                userExists = true;
                break;
            case '4':
                break;
            }

        }
    }
   
    return 0;
}

