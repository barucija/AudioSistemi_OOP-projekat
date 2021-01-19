#pragma once
#include "Radnik.h"
#include <iostream>
#include <vector>

using std::vector;

class Plata: virtual public Radnik
{

private:

	char mjesec[10];
	vector<Radnik> radnici;
	static float porez, osnovica, doprinosi;
	static void setOsnovica();
	static float getOsnovica();

public:

	Plata();

	void setMjesec();
	char* getMjesec();

	void setRadnik();
	vector<Radnik>& getRadnici();


	friend std::istream& operator>>(std::istream& stream, Plata& p);
	friend std::ostream& operator<<(std::ostream& stream, Plata& p);

	void ispisRadnika();
	void pretragaRadnik(char ime[]);
	void ispisPlata();
	void otpustiRadnika();

	~Plata() {};

};

