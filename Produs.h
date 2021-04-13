#pragma once
#include "Aliment.h"

class Produs {

public:
	Produs()
	{

	}
	Produs(Aliment al,double cantitate, double portie)
	{	
		this->al = al;
		this->cantitate = cantitate;
		this->portie = portie;
	}
	void setAliment(Aliment a)
	{
		this->al = a;
	}
	void setCantitate(double quantity)
	{
		this->cantitate = quantity;
	}
	void setPortion(double portion)
	{
		this->portie = portion;
	}
	double getQuantity()
	{
		return this->cantitate;
	}
	
	double getPortion()
	{

		return this->portie;
	}
	Aliment getAliment()
	{
		return this->al;
	}

private:
	Aliment al;
	double cantitate;
	double portie;
};

///deci in momentul in care userul introduce un produs acel produs va fi o instanta a clasei acesteia care ce
///va face este ca ne va avea cantitatea si potia si va stoca alimentul cu toate datele sale cat si 
///cantitatea si portia asta pentru a ne ajuta la calcule