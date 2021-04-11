#pragma once

#include <string>

class Aliment {

public:
	Aliment()
	{

	}

	Aliment(std::string nume, double val_energetica,double grasimi, double glucide, double fibre,double proteine,double cantitate)
	{
		this->nume = nume;
		this->val_energetica = val_energetica;
		this->grasimi = grasimi;
		this->glucide = glucide;
		this->fibre = fibre;
		this->proteine = proteine;
		this->sare = sare;
		this->cantitate = cantitate;
	}

	void setNume(string name)
	{
		this->nume = name;
	}

	void setValEnergetica(double val_eng)
	{
		this->val_energetica = val_eng;
	}

	void setGrasimi(double grasimi)
	{
		this->grasimi = grasimi;
	}

	void setGlucide(double glucide)
	{
		this->glucide = glucide;
	}

	void setFibre(double fibre)
	{
		this->fibre = fibre;
	}
	void setProteine(double proteine)
	{
		this->proteine = proteine;
	}

	void setCantitate(double cantitate)
	{
		this->cantitate = cantitate;
	}

	void setSare(double sare)
	{
		this->sare = sare;

	}

	

	string getNume()
	{
		return this->nume;
	}
	double getValEnergetica()
	{
		return this->val_energetica;
	}



	double getGrasimi()
	{
		return this->grasimi;
	}

	double getGlucide()
	{
		return this->glucide;
	}

	double getFibre()
	{
		return this->fibre;
	}
	double getProteine()
	{
		return this->proteine;
	}

	double getCantitate()
	{
		return this->cantitate;
	}

	double getSare()
	{
		return this->sare;
	}

	void afisare()
	{	
		cout << "\nNume:" << this->nume << endl;
		cout << "\nValoare energetica:" << this->val_energetica << endl;
		cout << "\nGrasimi:" << this->grasimi << endl;
		cout << "\nGlucide:" << this->glucide << endl;
		cout << "\nFibre:" << this->fibre << endl;
		cout << "\nProteine:" << this->proteine << endl;
		cout << "\nSare:" << this->sare << endl;
		cout << "\nCantitate:" << this->cantitate << endl;
	}

private :
	std::string nume;
	double val_energetica;
	double grasimi;
	double glucide;
	double fibre;
	double proteine;
	double sare;
	double cantitate;
};