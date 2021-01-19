#pragma once
#include "Oprema.h"
#include <vector>

using std::vector;

class Skladiste
{

private:

	int kapacitetStvariUSkladistu;

	static int ukupanBrojOpremeNaStanju;
	vector<Oprema> oprema;

public:

	Skladiste();

	void setSpremiOpremuUSkladiste();
	vector<Oprema>& getSpremljenoIzSkladista();


	void uzmiIzSkladista();

	void prikazSkladista();

	void pretragaPoNazivu();
	void pretragaPoBrendu();

	void fiskalni_racun();

	void prikaziFiskalniRacun();


	int getUkupanBrojOpremeNaStanju();

	static void naStanjuJeTrenutnoXOpreme();

	~Skladiste() {};
};

