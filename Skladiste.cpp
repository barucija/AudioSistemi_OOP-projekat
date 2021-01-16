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

}

void Skladiste::setKapacitetStvariUSkladistu()
{

	cout << "\n\t\t\tUnesite kapacitet stvari koje mogu biti skladistene u skladistu: ";
	cin >> this->kapacitetStvariUSkladistu;
	cin.ignore();

	cout << "\n\n\t\t\tUspjesno ste postavili kapacitet skladista!\n";

}

int Skladiste::getKapacitetStvariUSkladistu()
{
	return this->kapacitetStvariUSkladistu;
}

void Skladiste::setSpremiOpremuUSkladiste()
{



	if (this->getKapacitetStvariUSkladistu() == this->getUkupanBrojOpremeNaStanju()) {

		cout << "\t\t\tSkladiste je puno!\n";

	}

	else {

		std::shared_ptr<Oprema> temp = std::make_shared<Oprema>();
		temp->unesiOpremu();

		this->oprema.push_back(*temp);

		Skladiste::ukupanBrojOpremeNaStanju += temp->getBrojOpremeNaStanju();

	}

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

				cout << "\t\t\tKoliko primjeraka ove opreme zelite naruciti?\n\t\tUnesite kolicinu: ";
				int kolicinaZaNaruciti;
				cin >> kolicinaZaNaruciti;
				cin.ignore();

				if (this->oprema[i].getBrojOpremeNaStanju() < kolicinaZaNaruciti) {

					cout << "\t\t\tNa stanju nemamo toliki broj primjeraka!";

				}

				else {

					this->oprema[i].smanjiBrojOpremeNaStanju(kolicinaZaNaruciti);
					Skladiste::ukupanBrojOpremeNaStanju -= kolicinaZaNaruciti;

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

	cout << "\n\n\n";

	cout << "\t\t\tSkladiste firme Rental Parter\n\n";

	if (this->getSpremljenoIzSkladista().size() == 0) {

		cout << "\t\t\tSkladiste je trenutno prazno!\n";

	}

	else {

		for (int i = 0; i < this->getSpremljenoIzSkladista().size(); i++) {

			cout << std::setw(20) << "Naziv opreme" << std::setw(20) << "Brend" << std::setw(30) << "Na stanju primjeraka" << std::setw(20) << "Cijena";
			cout << "\n____________________________________________________________________________________________\n\n";
			cout << std::setw(20) << this->oprema[i].getNazivOpreme() << std::setw(20) << this->oprema[i].getBrendOpreme() << std::setw(30) << this->oprema[i].getBrojOpremeNaStanju() << std::setw(20) << this->oprema[i].getCijenaOpreme() << "\n";

		}

	}


}

void Skladiste::pretragaPoNazivu()
{

	char nazivZaPretragu[30];
	cout << "\n\t\t\tUnesite naziv opreme za pretragu: ";
	cin.getline(nazivZaPretragu, 30);

	if (this->oprema.size() == 0) {

		cout << "\t\t\tSkladiste je trenutno prazno!\n";

	}

	else {

		Skladiste* temp = new Skladiste();

		for (int i = 0; i < this->oprema.size(); i++) {

			if (_strcmpi(this->oprema[i].getNazivOpreme(), nazivZaPretragu) == 0) {

				temp->oprema.push_back(this->oprema[i]);

			}

			if (temp->oprema.size() == 0) {

				cout << "\t\t\tOprema s tim nazivom se ne nalazi u sistemu!\n";

			}

			else {

				temp->prikazSkladista();

			}

		}

	}

}

void Skladiste::fiskalni_racun()
{

	std::ofstream fiskalni_racun("fiskalni_racun.txt");

	for (int i = 0; i < this->oprema.size(); i++) {

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

int Skladiste::getUkupanBrojOpremeNaStanju()
{
	return Skladiste::ukupanBrojOpremeNaStanju;
}

void Skladiste::naStanjuJeTrenutnoXOpreme()
{

	cout << "\t\t\tU skladistu je trenutno " << Skladiste::ukupanBrojOpremeNaStanju << " dijelova.\n";

}