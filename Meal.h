#pragma once
#include "Progres.h"
#include "Menu.h"
#include <string>

///clasa meal
///contine mic dejun pranz si cina
///dar mic dejun pranz si cina sunt mese care practic fac parte din menu
//si noi in clasa meal stocam meniul cat si progresul
class Meal {

public:
	Meal()
	{
		std::cout << "Meal constructor!";
	}
	Meal(Progres exp, Progres real)
	{
		this->expected = exp;
		this->real = real;
	}

private:
	Progres expected, real;
	Menu mic_dejun, pranz, cina, gustari;
	std::string Data;
};