#pragma once
#include <iostream>
//Klasa sluzi za obracun plata na mjesecnom nivou svih zaposlenih
//Ovoj klasi pristup ima administracija firme

enum Vrsta_radnika { terenski_radnik = 0, kancelarijski_radnik };

class Radnik
{

private:

	char ime[15], prezime[30];
	int godinaStaza;
	float satnica;
	Vrsta_radnika vrsta;
public:

	Radnik();

	void setIme();
	void setPrezime();
	void setGodinaStaza();
	void setSatnica();
	void setVrsta(Vrsta_radnika x);

	char* getIme();
	char* getPrezime();
	int getGodinaStaza();
	float getSatnica();
	Vrsta_radnika getVrsta();

	void unosRadnika();
	void ispisRadnika();

	friend std::istream& operator>>(std::istream& stream, Radnik& r);
	friend std::ostream& operator<<(std::ostream& stream, Radnik& r);

	void promjenaVrste();

	~Radnik() {};

};

