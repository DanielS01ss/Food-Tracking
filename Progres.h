#pragma once

class Progres {

public:
	Progres()
	{
	
	}

	int getConsum()
	{
		return this->consumul;
	}
	double getProteine()
	{
		return this->proteine;
	}
	
	double getCarbohidrati()
	{
		return this->carbohidrati;
	}

	double getGrasimi()
	{
		return this->grasimi;
	}
	
	void setConsum(int consum)
	{
		 this->consumul = consum;
	}
	void setProteine(double proteine)
	{
		this->proteine= proteine;
	}
	
	void setCarbohidrati(double carbohidrati)
	{
		this->carbohidrati = carbohidrati;
	}


	void setGrasimi(double grasimi)
	{
		this->grasimi = grasimi;
	}

	/*Progres operator+(Progres p)
	{
		Progres res;
		res.consumul = this->consumul + p.consumul;
		res.carbohidratiMIN = this->carbohidratiMIN + p.carbohidratiMIN;
		res.grasimiMIN = this->grasimiMIN + p.grasimiMIN;
	}
	*/
	friend ostream& operator<<(ostream& o, Progres& p);

private:
	int consumul;
	double proteine;
	double carbohidrati;
	double grasimi;
	
};