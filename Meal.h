#pragma once
#include "Progres.h"
#include "Menu.h"
#include <string>

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