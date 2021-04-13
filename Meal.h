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

	void set_Mic_Dejun(Menu m)
	{
		this->mic_dejun = m;
	}
	void set_Pranz(Menu m)
	{
		this->pranz= m;
	}
	void set_Cina(Menu m)
	{
		this->cina = m;
	}
	void set_Gustari(Menu m)
	{
		this->gustari = m;
	}
	void setData(string data)
	{
		this->Data = data;
	}
	string getData()
	{
		return this->Data;
	}
	Progres getExpected()
	{
		return this->expected;
	}
	Progres getReal()
	{
		return this->real;
	}
	Menu getMic_de_Jun()
	{
		return this->mic_dejun;
	}
	Menu getPranz()
	{
		return this->pranz;
	}

	Menu getCina()
	{
		return this->cina;
	}
	Menu getGustari()
	{
		return this->gustari;
	}
	void calculate_progress_real()
	{
		this->real = mic_dejun.getProgresReal() + cina.getProgresReal() + pranz.getProgresReal() + gustari.getProgresReal();
	}
	friend ostream& operator<<(ostream& z, Meal& m);

private:
	Progres expected, real;
	Menu mic_dejun, pranz, cina, gustari;
	std::string Data;
};