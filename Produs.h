#pragma once
#include "Aliment.h"

class Produs {

	Produs()
	{

	}
	Produs(Aliment al,double cantitate, double portie)
	{	
		this->al = al;
		this->cantitate = cantitate;
		this->portie = portie;
	}

private:
	Aliment al;
	double cantitate;
	double portie;
};