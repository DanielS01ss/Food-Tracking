#pragma once
#include "Produs.h"
#include "Progres.h"
#include <vector>

class Menu {

	Menu()
	{

	}
	Menu(Progres exp, Progres real)
	{

		this->expected = exp;
		this->real = real;
	}

private:
	Progres expected, real;
	vector<Produs> alimente_consumate;
	vector<Produs> alimente_recomandate;
};