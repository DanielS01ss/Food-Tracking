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
		
		int consum =0;
		double proteine = 0;
		double carbo = 0;
		double grasimi= 0 ;


		for (int i = 0; i < this->alimente_consumate.size(); i++)
		{
			
			consum += ((alimente_consumate[i].getQuantity() * alimente_consumate[i].getAliment().getValEnergetica()) / alimente_consumate[i].getAliment().getCantitate())*alimente_consumate[i].getPortion();
			proteine+= ((alimente_consumate[i].getQuantity() * alimente_consumate[i].getAliment().getProteine()) / alimente_consumate[i].getAliment().getCantitate()) * alimente_consumate[i].getPortion();
			carbo+= ((alimente_consumate[i].getQuantity() * alimente_consumate[i].getAliment().getGlucide()) / alimente_consumate[i].getAliment().getCantitate()) * alimente_consumate[i].getPortion();
			grasimi += ((alimente_consumate[i].getQuantity() * alimente_consumate[i].getAliment().getGrasimi()) / alimente_consumate[i].getAliment().getCantitate()) * alimente_consumate[i].getPortion();
			
		} 
		this->real.setConsum(consum);
		this->real.setProteine(proteine);
		this->real.setCarbohidrati(carbo);
		this->real.setGrasimi(grasimi);
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