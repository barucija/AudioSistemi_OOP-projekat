#pragma once
#include "Radnik.h"
#include <vector>

using std::vector;

class Plata
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

	void ispisRadnika();
	void pretragaRadnik(char ime[]);
	void ispisPlata();
	void ispisPlataUslov(int s1, int s2);
	void otpustiRadnika();

	~Plata() {};

};

