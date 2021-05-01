#include <iostream>
#include "User.h"
#include "enums.h"
using namespace std;

double calculateKcals(User u)
{
	///caloriile se calc
	///prima data vine calculat bmr
	///si dupa amr
	///bmr e cat iti i-a sa sustii functii vitale ale organismului
	///si la amr cat iti i-a sa ramai la greutatea curenta
	///si de acolo vom lucra
	/*double bmr;
	if (u.getSex() == 1)
	{
		bmr = 655.1 + (9.563 * u.getGreutate()) + (1.850 * u.getInaltime()) - (4.676 * u.getVarsta());
	}
	else {

		bmr = 66.47 + (13.75 * u.getGreutate()) + (5.003 * u.getInaltime()) - (6.775 * u.getVarsta());
	}

	///acuma ce facem este ca o sa obtinem amr care amr ce inseamna
	///este practic necesarul caloric pe care-l vom avea pentru a putea sa ne mentinem
	///la greutatea curenta
	double amr = 0;

	if (u.getPersonActivity() == Sedentar)
	{
		 amr = bmr * 1.2;
	}
	else if (u.getPersonActivity() == Usoara)
	{
		amr = bmr * 1.375;
	}
	else if (u.getPersonActivity() == Moderata)
	{
		amr = bmr * 1.55;
	}
	else if (u.getPersonActivity() == Intensa)
	{
		amr = bmr * 1.9;
	}
	///si acuma daca este sa avem nevoie sa slabim scadem 500 de calorii daca nu urcam 500 de calorii

	if (u.getPersonScope() == Scadere_in_greutate)
	{
		return(amr - 500);
	}
	else if (u.getPersonScope() == Mentinere)
	{
		return amr;
	}
	else {
		return (amr + 500);
	}
	*/
	///aici avem a doua implementare a calculatorului de kcal

	///avem asa: luam greutatea in kg si o inmultim cu 0.9 daca este femeie si cu 1.0 daca este barbat

	double bmr,bodyFat,bmi = u.getInaltime()/(u.getGreutate()*u.getGreutate());

	bmr = u.getGreutate() * 24;

	///acuma trebuie sa calculam si fat percentage pentru a putea duce la capat treaba
	//si o sa avem asa
	///o sa luam si bmi-ul ca si valoare aicea
	///caci avem nevoie de el
	///bmi ca si valoare este kg/inaltime*inaltime';

	///masculin e 0 feminin e 1
	if (u.getSex() == 1)
	{
		///acesta este procentajul de grasime
		bodyFat = (1.20 * bmi) + (0.23 * u.getVarsta()) - 16.2;
		///si acuma calculam si bmr
		///acesta trebuie inmultit cu lean factor in functie de grasime
		if (bodyFat >= 14 && bodyFat < 19)
		{
			bmr = bmr * 1;
		}
		else if (bodyFat >= 19 && bodyFat < 29)
		{
			bmr = bmr * 0.95;
		}
		else if (bodyFat >= 29 && bodyFat <=38)
		{
			bmr = bmr * 0.90;
		}
		else {
			bmr = bmr * 0.85;
		}
	}
	else {

		bodyFat = (1.20 * bmi) + (0.23 * u.getVarsta()) - 5.4;
		if (bodyFat >= 10 && bodyFat < 15)
		{
			bmr = bmr * 1;
		}
		else if (bodyFat >= 15 && bodyFat < 21)
		{
			bmr = bmr * 0.95;
		}
		else if (bodyFat >= 21 && bodyFat <= 28)
		{
			bmr = bmr * 0.90;
		}
		else if(bmr>28) {
			bmr = bmr * 0.85;
		}

	}

	//acuma tot calculul de mai sus vine inmultit cu nivelul de activitate
	Activitate a = u.getPersonActivity();
	if (a ==  Sedentar)
	{
		bmr = bmr * 1.3;
	}
	else if (a == Usoara)
	{
		bmr = bmr * 1.55;
	}
	else if (a == Moderata)
	{
		bmr = bmr * 1.65;
	}
	else if (a == Intensa)
	{
		bmr = bmr * 1.80;
	}

	///si acuma trebuie sa returnam neaparat cate kcal trebuie sa consume userul
	Scop s = u.getPersonScope();
	if (s == Scadere_in_greutate)
	{
		bmr = bmr - 500;
	}
	else if (s == Crestere_in_greutate)
	{
		bmr = bmr + 500;
	}

	return bmr;
}

double calculateFats(User u,int kcals)
{
	if(u.getPersonScope()==Scadere_in_greutate)
		return (kcals *0.2 )/9;
	else if (u.getPersonScope() == Mentinere)
	{
		return(kcals*0.275)/9;
	}
	else if (u.getPersonScope() == Crestere_in_greutate)
	{
		return(kcals * 0.35) / 9;
	}

}

double calculateFibres(int kcals)
{
	///formula este asa kcal /1000 * 14
	return ((kcals) / 1000) * 14;

}

double calculateCarbs(User u, int kcal)
{
	if (u.getPersonScope() == Scadere_in_greutate)
	{
		return 100;
	}
	else {

		return 150;
	}
}

double calculateProteins(User u,int kcals)
{
	///daca vrea sa scada in greutate avem 1.6 * kg
	if (u.getPersonScope() == Scadere_in_greutate)
		return (1.6 * u.getGreutate());
	else if (u.getPersonScope() == Crestere_in_greutate)
		return (2 * u.getGreutate());
	else
		return (1.9 * u.getGreutate());
}

double getSalt()
{

	return 1.5;
}