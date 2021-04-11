#pragma once
#include <string>
#include "enums.h"
using namespace std;


class User {

public:

	User()
	{
		
	}

	User(std::string nume, int varsta, bool sex, double greutate, double inaltime, double greutate_dorita, BMI b1, Activitate act, Scop s, Metabolism
		m1)
	{
		this->nume = nume;
		this->varsta = varsta;
		this->sex = sex;
		this->greutate = greutate;
		this->inaltime = inaltime;
		this->greutate_dorita = greutate_dorita;
		this->person_bmi = b1;
		this->activity = act;
		this->personal_purpose = s;
		this->person_metabolism = m1;
	}

	void setNume(std::string name)
	{
		this->nume = name;
	}

	void setSex(bool sex)
	{
		this->sex = sex;
	}

	void setVarsta(int age)
	{
		this->varsta = age;
	}

	void setGreutate(double greutate)
	{
		this->greutate = greutate;
	}

	void setInaltime(double inaltime)
	{
		this->inaltime = inaltime;
	}

	void setGreutateDorita(double greutate_dorita)
	{
		this->greutate_dorita = greutate_dorita;
	}

	void setPersonBMI(BMI b)
	{
		this->person_bmi = b;
	}

	void setPersonalScope(Scop s1)
	{
		this->personal_purpose = s1;
	}

	void setPersonMetabolism(Metabolism m1)
	{
		this->person_metabolism = m1;
	}
	void setPersonActivity(Activitate a)
	{
		this->activity = a;
	}


	std::string getNume()
	{
		return this->nume;
	}
	int getVarsta()
	{
		return this->varsta;
	}
	bool getSex()
	{
		return this->sex;
	}
	double getGreutate()
	{
		return this->greutate;
	}
	double getInaltime()
	{
		return this->inaltime;
	}
	double getGreutate_dorita()
	{
		return this->greutate_dorita;
	}
	BMI getPersonBmi()
	{
		return this->person_bmi;
	}
	Scop getPersonScope()
	{
		return this->personal_purpose;
	}
	Metabolism getPersonMetabolism()
	{
		return this->person_metabolism;
	}

	Activitate getPersonActivity()
	{
		return this->activity;
	}

private:
	std::string nume;
	int varsta;
	bool sex;
	double greutate, inaltime,greutate_dorita;
	BMI person_bmi;
	Activitate activity;
	Scop personal_purpose;
	Metabolism person_metabolism;

};