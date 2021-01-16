#include "Plata.h"
#include <iostream>
#include <memory>
#include <iomanip>

using std::cout;
using std::cin;
using std::vector;

float Plata::porez = 0;
float Plata::osnovica = 0;
float Plata::doprinosi = 0;

Plata::Plata()
{
	strcpy_s(this->mjesec, "Januar");
	Plata::porez = 0.1;
	Plata::doprinosi = 0.25;
}

void Plata::setMjesec()
{
	cout << "\t\t\tUnesite mjesec: ";
	cin.getline(this->mjesec, 10);
}

char* Plata::getMjesec()
{
	return this->mjesec;
}

void Plata::setOsnovica()
{
	cout << "\n\t\t\tUnesite osnovicu radnika: ";
	cin >> Plata::osnovica;
	cin.ignore();
}

float Plata::getOsnovica()
{
	return Plata::osnovica;
}

void Plata::setRadnik()
{
	std::shared_ptr<Radnik> temp = std::make_shared<Radnik>();

	Plata radnik;
	cin >> radnik;
	*temp = radnik;
	this->radnici.push_back(*temp);
	this->setOsnovica();
}

vector<Radnik>& Plata::getRadnici()
{
	return this->radnici;
}


void Plata::ispisRadnika()
{
	cout << std::endl;
	cout << "\t\t\t";
	cout.width(5);
	cout << std::right << "R. br.";
	cout.width(21);
	cout << std::right << "Ime i prezime";
	cout.width(18);
	cout << std::right << "Vrsta radnika";
	cout << "\n\t\t\t---------------------------------------------------\n";

	for (int i = 0; i < this->getRadnici().size(); i++) {

		cout << "\t\t\t";

		cout.width(5);
		cout << std::left << i + 1;

		cout.width(14);
		cout << std::right << this->radnici[i].getIme() << " " << this->radnici[i].getPrezime();

		if (this->radnici[i].getVrsta() == terenski_radnik) {
			cout.width(22);
			cout << std::right << "Terenski radnik";
		}
		else {
			cout.width(22);
			cout << std::right << "Kancelarijski";
		}

		cout << "\n";
	}
}

void Plata::pretragaRadnik(char ime[])
{
	if (this->getRadnici().size() == 0) {
		cout << "\t\t\tNema unesenih radnika u sistemu!\n";
	}
	else {

		Plata* temp = new Plata();
		for (int i = 0; i < this->getRadnici().size(); i++) {
			if (_strcmpi(this->getRadnici()[i].getIme(), ime) == 0) {
				temp->getRadnici().push_back(this->getRadnici()[i]);
			}
		}

		try {

			if (temp->getRadnici().size() == 0) {
				throw "\t\t\tU sistemu nema radnika s tim imenom!\n";
			}
			else {
				temp->ispisRadnika();
			}

		}

		catch (const char* Greska) {
			cout << "\t\t\t[GRESKA] " << Greska;
		}


		delete temp;
	}

}

void Plata::ispisPlata()
{
	cout << "Mjesec: " << this->getMjesec() << "\n";


	if (this->getRadnici().size() == 0) {
		cout << "\t\t\tNema unesenih radnika u sistemu!\n";
	}

	else {

		cout.width(5);
		cout << std::right << "R. br.";
		cout.width(22);
		cout << std::right << "Ime i prezime";
		cout.width(14);
		cout << std::right << "Staz";
		cout.width(14);
		cout << std::right << "Topli";
		cout.width(14);
		cout << std::right << "Ukupno";
		cout << "\n-----------------------------------------------------------------------------\n";

		for (int i = 0; i < this->getRadnici().size(); i++) {
			float topli = 0, ukupno = 0;
			cout.width(5);
			cout << std::left << i + 1;

			cout.width(14);
			cout << std::right << this->radnici[i].getIme() << " " << this->radnici[i].getPrezime();

			cout.width(14);
			cout << std::right << this->radnici[i].getGodinaStaza();

			topli = this->radnici[i].getSatnica() * Plata::osnovica + this->radnici[i].getGodinaStaza() * 10;
			cout.width(16);
			cout << std::right << topli;

			ukupno = (topli * (1 - Plata::doprinosi)) * (1 - Plata::porez);

			if (this->radnici[i].getVrsta() == terenski_radnik) {
				cout.width(16);
				cout << std::right << ukupno;
			}

			else {
				ukupno = ukupno * 1.25;
				cout.width(16);
				cout << std::right << ukupno;
			}

			cout << "\n";
		}
	}
}

void Plata::ispisPlataUslov(int s1, int s2)
{
	if (this->getRadnici().size() == 0) {
		cout << "Nema unesenih radnika u sistemu!\n";
	}
	else {
		Plata* temp = new Plata();

		for (int i = 0; i < this->getRadnici().size(); i++) {
			if (this->radnici[i].getGodinaStaza() > s1 || this->radnici[i].getGodinaStaza() < s2) {
				temp->getRadnici().push_back(this->getRadnici()[i]);
			}
		}

		if (temp->getRadnici().size() == 0) {
			cout << "U sistemu nema radnika s tim imenom!\n";
		}

		else {
			temp->ispisPlata();
		}
	}
}

void Plata::otpustiRadnika()
{

		int rbZaOtpust;
		do {
			this->ispisRadnika();
			cout << "\nUnesite redni broj radnika kojeg zelite otpustiti: ";
			cin >> rbZaOtpust;
			cin.ignore();
		} while (rbZaOtpust > this->getRadnici().size() || rbZaOtpust < 1);

		this->radnici.erase(this->radnici.begin() + rbZaOtpust - 1);

		cout << "\n\t\t\tRadnik pored rednim brojem " << rbZaOtpust << " uspjesno otpusten!\n";

		system("PAUSE");
		system("CLS");
		cout << "\t\t\tNovi spisak radnika: \n";

		this->ispisRadnika();

}

std::istream& operator>>(std::istream& stream, Plata& p)
{

	p.setIme();
	p.setPrezime();
	p.setGodinaStaza();
	p.setSatnica();

	cout << "\t\t\tRadnik je: ";

	if (p.getVrsta() == terenski_radnik) {
		cout << "Terenski radnik.\n";
	}

	else {
		cout << "Kancelarijski radnik.\n";
	}

	cout << "\n\t\t\tDa li zelite promijeniti vrstu posla koji radnik obavlja?\n\t\t\t1.Da\n\t\t\t2.Ne\n\t\t\tOdabir: ";
	int izborPromjeneVrste;
	cin >> izborPromjeneVrste;
	cin.ignore();

	switch (izborPromjeneVrste)
	{
	case 1:
		p.promjenaVrste();
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

std::ostream& operator<<(std::ostream& stream, Plata& p)
{
	stream << std::endl;
	stream << "\t\t\t";
	stream.width(5);
	stream << std::right << "R. br.";
	stream.width(21);
	stream << std::right << "Ime i prezime";
	stream.width(18);
	stream << std::right << "Vrsta radnika";
	stream << "\n\t\t\t---------------------------------------------------\n";

	for (int i = 0; i < p.getRadnici().size(); i++) {

		stream << "\t\t\t";

		stream.width(5);
		stream << std::left << i + 1;

		stream.width(14);
		stream << std::right << p.getRadnici()[i].getIme() << " " << p.getRadnici()[i].getPrezime();

		if (p.getRadnici()[i].getVrsta() == terenski_radnik) {
			stream.width(22);
			stream << std::right << "Terenski radnik";
		}
		else {
			stream.width(22);
			stream << std::right << "Kancelarijski";
		}

		stream << "\n";
	}
	return stream;
}
