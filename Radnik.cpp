#include "Radnik.h"
#include <iostream>
#include <string>
#include "Skladiste.h"
#include <memory>

using std::cin;
using std::cout;

Radnik::Radnik()
{
	strcpy_s(this->ime, "Ime");
	strcpy_s(this->prezime, "Prezime");
	this->godinaStaza = 0;
	this->satnica = 10;
	this->vrsta = terenski_radnik;
}

void Radnik::setIme()
{
	cout << "\n\n\t\t\tUnesi ime: ";
	cin.getline(this->ime, 15);
}

void Radnik::setPrezime()
{
	cout << "\t\t\tUnesi prezime: ";
	cin.getline(this->prezime, 30);
}

void Radnik::setGodinaStaza()
{
	cout << "\t\t\tUnesite koliko godina staza osoba ima: ";
	cin >> this->godinaStaza;
	cin.ignore();
}

void Radnik::setSatnica()
{
	cout << "\t\t\tUnesite satnicu radnika: ";
	cin >> this->satnica;
	cin.ignore();
}

void Radnik::setVrsta(Vrsta_radnika x)
{
	this->vrsta = x;
}

char* Radnik::getIme()
{
	return this->ime;
}

char* Radnik::getPrezime()
{
	return this->prezime;
}

int Radnik::getGodinaStaza()
{
	return this->godinaStaza;
}

float Radnik::getSatnica()
{
	return this->satnica;
}

Vrsta_radnika Radnik::getVrsta()
{
	return this->vrsta;
}

void Radnik::unosRadnika()
{
}

void Radnik::ispisRadnika()
{
}

void Radnik::promjenaVrste()
{
	if (this->getVrsta() == terenski_radnik) {
		this->setVrsta(kancelarijski_radnik);
	}

	else {
		this->setVrsta(terenski_radnik);
	}
}

std::istream& operator>>(std::istream& stream, Radnik& r)
{

	r.setIme();
	r.setPrezime();
	r.setGodinaStaza();
	r.setSatnica();

	cout << "\t\t\tRadnik je: ";

	if (r.getVrsta() == terenski_radnik) {
		cout << "Terenski radnik.\n";
	}

	else {
		cout << "Kancelarijski radnik.\n";
	}

	cout << "\n\t\t\tDa li zelite promijeniti vrstu posla koji radnik obavlja?\n\t\t\t1.Da\n\t\t\t2.Ne\n\t\t\tOdabir: ";
	int izborPromjeneVrste;
	stream >> izborPromjeneVrste;
	cin.ignore();

	switch (izborPromjeneVrste)
	{
	case 1:
		r.promjenaVrste();
		cout << "\t\t\tVrsta posla je promijenjena!\n";
		break;
	case 2:
		cout << "\t\t\tVrsta posla ostaje ista!\n";
		break;
	default:
		cout << "\t\t\tPogresan unos!";
		break;
	}
	return stream;
}

std::ostream& operator<<(std::ostream& stream, Radnik& r)
{
	stream << "\t\t\tIme i prezime radnika: " << r.getIme() << " " << r.getPrezime() << "\n";
	stream << "\t\t\tRadnik ima " << r.getGodinaStaza() << " godina staza i koeficijent plate " << r.getSatnica() << "\n";
	stream << "\t\t\tRadnik je: ";

	if (r.getVrsta() == terenski_radnik) {
		cout << "Terenski radnik.\n";
	}

	else {
		cout << "Kancelarijski radnik.\n";
	}
	return stream;
}
