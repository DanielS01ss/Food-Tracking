#pragma once
#include "Produs.h"
#include "Progres.h"
#include <vector>

class Menu {

public:

	Menu()
	{

	}
	Menu(Progres exp, Progres real)
	{

		this->expected = exp;
		this->real = real;
	}

	Progres getProgresReal()
	{
		return this->real;
	}
	Progres getProgresExpected()
	{
		return this->expected;
	}

	void setAlimenteConsumate(vector<Produs> alimCons)
	{
		this->alimente_consumate = alimCons;
	}
	void setAlimenteRecomandate(vector<Produs> alimRecom)
	{
		this->alimente_recomandate = alimRecom;
	}

	void setProgresReal(Progres rl)
	{
		this->real = rl;
	}
	
	void setProgresExpected(Progres ex)
	{
		this->expected = ex;
	}
	///progresul este suma datelor din fiecare produs

	///asta de aici vine reimplementat
	
	void calculateProgressReal()
	{
		/*
		for (int i = 0; i < this->alimente_consumate.size(); i++)
		{
			
			this->real.setConsum((this->alimente_consumate[i].getAliment().getValEnergetica() * this->alimente_consumate[i].getQuantity()) / this->alimente_consumate[i].getAliment().getCantitate());
			this->real.setProteineMIN(this->alimente_consumate[i].getAliment().getProteine());
			this->real.setCarbohidratiMIN(this->alimente_consumate[i].getAliment().getGlucide());
			this->real.setGrasimiMIN(this->alimente_consumate[i].getAliment().getGrasimi());
		} */
	}
	///aici faza e ca ne va calcula functia 
	void calculateProgressExpected()
	{

	}
	
	Progres getExpected()
	{
		return this->expected;
	}

	Progres getReal()
	{
		return this->real;
	}
	vector<Produs> getAlimenteRecomandate()
	{
		return this->alimente_recomandate;
	}

	vector<Produs> getAlimenteConsumate()
	{
		return this->alimente_consumate;
	}

	friend ostream& operator<<(ostream& o, Menu& m);

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