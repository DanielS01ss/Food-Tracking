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
	double bmr;
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

}

double calculateFats(User u,int kcals)
{
	///30 % din calorii ar trebui sa fie grasimi
	///dar daca este sa pierdem in greutate atunci sa zicem ca reducem la 35 %
	if(u.getPersonScope()==Scadere_in_greutate)
		return ((kcals * 35) / 100);
	else if (u.getPersonScope() == Mentinere || u.getPersonScope() == Crestere_in_greutate)
	{
		return((kcals * 27) / 100);
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