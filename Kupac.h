#pragma once
#include "Datum.h"
#include "Skladiste.h"

enum vrstaNacinaNarucivanja { e_mail = 0, broj_telefona, dolazak_u_radnju };

class Kupac
{
private:

	char ime[20], prezime[30], grad[15], adresaStanovanja[30];
	vrstaNacinaNarucivanja vrsta;
	Datum datum;
	Skladiste uzmiNardzbu;

	char email[50], brojTelefona[15];

public:

	Kupac();

	void setIme();
	char* getIme();

	void setPrezime();
	char* getPrezime();

	void setGrad();
	char* getGrad();

	void setAdresaStanovanja();
	char* getAdresaStanovanja();

	void setEmail();
	char* getEmail();

	void setBrojTelefona();
	char* getBrojTelefona();

	void setVrstaNacinaNarucivanja(vrstaNacinaNarucivanja x);
	vrstaNacinaNarucivanja getVrstaNarucivanja();

	void postaviKupca();
	void ispisPodatakaOKupcu();

	~Kupac() {};

};

