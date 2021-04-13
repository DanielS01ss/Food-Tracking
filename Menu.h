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

///in acesta clasa vom avea pe mese toata chestia asta facuta
///adica o sa am masa x care masa x ce va contine este ca vom introduce datele aferente alimentelor introduse
/// si practic vom stoca alimentele consumate intr-un vector
///ca dupa sa stocam progresul in progres
///si progresul va fi pe masa