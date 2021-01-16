#pragma once
#include "Oprema.h"
#include <vector>

using std::vector;

class Skladiste
{

private:

	int kapacitetStvariUSkladistu;
	vector<Oprema> oprema;

public:

	Skladiste();

	void setKapacitetStvariUSkladistu();
	int getKapacitetStvariUSkladistu();

	void spremiOpremuUSkladiste();

	void uzmiIzSkladista();

	void prikazSkladista();

	void pretragaPoNazivu();

	~Skladiste() {};
};

