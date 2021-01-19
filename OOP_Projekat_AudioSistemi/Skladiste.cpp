#include "Skladiste.h"
#include <iostream>
#include <iomanip>
#include <memory>
#include "Oprema.h"
#include <fstream>

using std::cout;
using std::cin;

int Skladiste::ukupanBrojOpremeNaStanju = 0;

Skladiste::Skladiste()
{

	this->kapacitetStvariUSkladistu = 0;

}

void Skladiste::setSpremiOpremuUSkladiste()
{

	std::shared_ptr<Oprema> temp = std::make_shared<Oprema>();
	temp->unesiOpremu();

	this->oprema.push_back(*temp);

	Skladiste::ukupanBrojOpremeNaStanju += temp->getBrojOpremeNaStanju();

}

vector<Oprema>& Skladiste::getSpremljenoIzSkladista()
{

	return this->oprema;

}


void Skladiste::uzmiIzSkladista()
{

	char narudzba[60];

	std::ofstream fiskalniRacun("fiskalni_racun.txt", std::ios::app);

	if (fiskalniRacun.is_open()) {

		cout << "\t\t\tMolimo unesite naziv opreme: ";
		cin.getline(narudzba, 60);

		int brojac = 0;

		for (int i = 0; i < this->oprema.size(); i++) {

			if (_strcmpi(this->oprema[i].getNazivOpreme(), narudzba) == 0) {

				brojac++;

				cout << "\t\t\tKoliko primjeraka ove opreme zelite naruciti?\n\t\t\tUnesite kolicinu: ";
				int kolicinaZaNaruciti;
				cin >> kolicinaZaNaruciti;
				cin.ignore();

				if (this->oprema[i].getBrojOpremeNaStanju() < kolicinaZaNaruciti) {

					cout << "\n\t\tNa stanju nemamo toliki broj primjeraka!";
					cout << "\n\t\tOvih primjeraka na stanju imamo: " << this->oprema[i].getBrojOpremeNaStanju() << " komada.\n";
					cout << "\n\t\tUnesite ponovo broj primjeraka koje zelite narucite shodno broju opreme na stanju: ";

					cin >> kolicinaZaNaruciti;
					cin.ignore();

					this->oprema[i].smanjiBrojOpremeNaStanju(kolicinaZaNaruciti);
					Skladiste::ukupanBrojOpremeNaStanju -= kolicinaZaNaruciti;

					cout << "\n\n\t\tNarudzba uspjesno izvrsena!\n";

				}

				else {

					this->oprema[i].smanjiBrojOpremeNaStanju(kolicinaZaNaruciti);
					Skladiste::ukupanBrojOpremeNaStanju -= kolicinaZaNaruciti;

					cout << "\n\n\t\t\tNarudzba uspjesno izvrsena!\n";

				}

			}

			cin.ignore();

			fiskalniRacun << this->oprema[i].getNazivOpreme() << this->oprema[i].getBrendOpreme() << this->oprema[i].getVrstaOpreme() << this->oprema[i].getCijenaOpreme();


			fiskalniRacun.close();

		}

	}

}

void Skladiste::prikazSkladista()
{

	if (this->getSpremljenoIzSkladista().size() == 0) {

		cout << "\n\n\t\t\tSkladiste je trenutno prazno!\n";

	}

	else {

		cout.width(5);
		cout << std::right << "\tR. br.";
		cout.width(18);
		cout << std::right << "\tNaziv opreme";
		cout.width(19);
		cout << std::right << "Brend opreme";
		cout.width(14);
		cout << std::right << "Na stanju";
		cout.width(14);
		cout << std::right << "Cijena";
		cout.width(14);
		cout << "\n\t-----------------------------------------------------------------------------\n";

		for (int i = 0; i < this->getSpremljenoIzSkladista().size(); i++) {

			cout.width(5);
			cout << std::right << "\t" << i + 1;

			cout.width(10);
			cout << std::right << "\t" << this->oprema[i].getNazivOpreme();

			cout.width(16);
			cout << std::right << this->oprema[i].getBrendOpreme();

			cout.width(17);
			cout << std::right << this->oprema[i].getBrojOpremeNaStanju();;

			cout.width(20);
			cout << std::right << this->oprema[i].getCijenaOpreme();

			cout << "\n";
		}

	}

}

void Skladiste::pretragaPoNazivu()
{

	char nazivZaPretragu[30];
	cout << "\n\t\t\tUnesite naziv opreme za pretragu: ";
	cin.getline(nazivZaPretragu, 30);

	if (this->getSpremljenoIzSkladista().size() == 0) {

		cout << "\t\t\tSkladiste je trenutno prazno!\n";

	}

	else {

		Skladiste* temp = new Skladiste();

		for (int i = 0; i < this->getSpremljenoIzSkladista().size(); i++) {

			if (_strcmpi(this->oprema[i].getNazivOpreme(), nazivZaPretragu) == 0) {

				temp->oprema.push_back(this->oprema[i]);

			}

		}

		if (temp->getSpremljenoIzSkladista().size() == 0) {

			cout << "\t\t\tOprema s tim nazivom se ne nalazi u sistemu!\n";

		}

		else {

			temp->prikazSkladista();

		}

	}

}

void Skladiste::pretragaPoBrendu()
{

	char brendZaPretragu[30];
	cout << "\n\t\t\tUnesite naziv opreme za pretragu: ";
	cin.getline(brendZaPretragu, 30);

	if (this->getSpremljenoIzSkladista().size() == 0) {

		cout << "\t\t\tSkladiste je trenutno prazno!\n";

	}

	else {

		Skladiste* temp = new Skladiste();

		for (int i = 0; i < this->getSpremljenoIzSkladista().size(); i++) {

			if (_strcmpi(this->oprema[i].getBrendOpreme(), brendZaPretragu) == 0) {

				temp->oprema.push_back(this->oprema[i]);

			}
		}

		if (temp->getSpremljenoIzSkladista().size() == 0) {

			cout << "\t\t\tOprema s tog brenda se ne nalazi u sistemu!\n";

		}

		else {

			temp->prikazSkladista();

		}

	}



}

void Skladiste::fiskalni_racun()
{

	std::ofstream fiskalni_racun("fiskalni_racun.txt");

	for (int i = 0; i < this->getSpremljenoIzSkladista().size(); i++) {

		fiskalni_racun << "__________________________________________________________________________________________________________________________\n\n";
		fiskalni_racun << std::endl;

		fiskalni_racun << "\t\t\t\t\t\tNaziv artikla: " << this->oprema[i].getNazivOpreme() << std::endl;
		fiskalni_racun << "\t\t\t\t\t\tBrend artikla: " << this->oprema[i].getBrendOpreme() << std::endl;
		fiskalni_racun << "\t\t\t\t\t\tVrsta opreme: ";
		if (this->oprema[i].getVrstaOpreme() == audio_oprema) {

			fiskalni_racun << "Audio oprema.\n";

		}

		else {

			fiskalni_racun << "Binska oprema.\n";


		}
		fiskalni_racun << "\t\t\t\t\t\tCijena opreme: " << this->oprema[i].getCijenaOpreme() << std::endl;

	}

}

void Skladiste::prikaziFiskalniRacun()
{

	for (int i = 0; i < this->getSpremljenoIzSkladista().size(); i++) {

		cout << "__________________________________________________________________________________________________________________________\n\n";
		cout << std::endl;

		cout << "\t\t\t\t\t\tNaziv artikla: " << this->oprema[i].getNazivOpreme() << std::endl;
		cout << "\t\t\t\t\t\tBrend artikla: " << this->oprema[i].getBrendOpreme() << std::endl;
		cout << "\t\t\t\t\t\tVrsta opreme: ";
		if (this->oprema[i].getVrstaOpreme() == audio_oprema) {

			cout << "Audio oprema.\n";

		}

		else {

			cout << "Binska oprema.\n";

		}

		cout << "\t\t\t\t\t\tCijena opreme: " << this->oprema[i].getCijenaOpreme() << std::endl;

	}

}

int Skladiste::getUkupanBrojOpremeNaStanju()
{
	return Skladiste::ukupanBrojOpremeNaStanju;
}

void Skladiste::naStanjuJeTrenutnoXOpreme()
{

	cout << "\t\t\tU skladistu je trenutno " << Skladiste::ukupanBrojOpremeNaStanju << " dijelova.\n";

}