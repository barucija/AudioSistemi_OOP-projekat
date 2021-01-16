#include "Skladiste.h"
#include <iostream>
#include <memory>
#include "Oprema.h"

using std::cout;
using std::cin;

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

void Skladiste::spremiOpremuUSkladiste()
{

	if (this->getKapacitetStvariUSkladistu() == Oprema::ukupanBrojOpremeNaStanju) {

		cout << "\t\t\tSkladiste je puno!\n";

	}

	else {

		Oprema temp;
		temp.unesiOpremu();
		int brojac = 0;

		for (int i = 0; i < this->oprema.size(); i++) {

			if (_strcmpi(this->oprema[i].getNazivOpreme(), temp.getNazivOpreme()) == 0) {

				brojac++;

				if (temp.getBrojOpremeNaStanju() + Oprema::ukupanBrojOpremeNaStanju > this->getKapacitetStvariUSkladistu()) {
					cout << "\t\t\tTa brojka nadmasuje ukupni kapacitet za skladistenje!\n";
				}

				else {
					this->oprema[i].povecajBrojOpremeNaStanju(temp.getBrojOpremeNaStanju());
					cout << "\t\t\tUspjesno skladistena oprema!\n";

					Oprema::ukupanBrojOpremeNaStanju += temp.getBrojOpremeNaStanju();
				}

			}

			if (brojac == 0) {

				if (temp.getBrojOpremeNaStanju() + Oprema::ukupanBrojOpremeNaStanju > this->getKapacitetStvariUSkladistu()) {
					cout << "\t\t\tTa brojka nadmasuje ukupni kapacitet za skladistenje!\n";
				}

				else {
					this->oprema[i].povecajBrojOpremeNaStanju(temp.getBrojOpremeNaStanju());
					cout << "\t\t\tUspjesno skladistena oprema!\n";

					Oprema::ukupanBrojOpremeNaStanju += temp.getBrojOpremeNaStanju();
				}

			}

		}

	}

}

void Skladiste::uzmiIzSkladista()
{

	char narudzba[60];

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
				Oprema::ukupanBrojOpremeNaStanju -= kolicinaZaNaruciti;

			}

		}

	}

}

void Skladiste::prikazSkladista()
{

	cout << "\n\n\n";

	cout << "\t\t\tSkladiste firme Rental Parter\n\n";

	if (this->oprema.size() == 0) {

		cout << "\t\t\tSkladiste je trenutno prazno!\n";

	}

	else {

		for (int i = 0; i < this->oprema.size(); i++) {

			cout << "\t\tNaziv opreme\t\tBrend\t\tNa stanju primjeraka\t\tCijena\n";
			cout << "\t\t" << this->oprema[i].getNazivOpreme() << "\t\t" << this->oprema[i].getBrendOpreme() << "\t\t" << this->oprema[i].getBrojOpremeNaStanju() << "\t\t" << this->oprema[i].getCijenaOpreme() << "\n";

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

