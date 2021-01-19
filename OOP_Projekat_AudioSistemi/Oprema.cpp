#include "Oprema.h"
#include <fstream>
#include <iostream>

using std::cout;
using std::cin;


void Oprema::setNazivOpreme()
{

	cout << "\t\t\tMolimo Vas unesite naziv opreme: ";
	cin.getline(this->nazivOpreme, 20);

}

char* Oprema::getNazivOpreme()
{

	return this->nazivOpreme;

}

void Oprema::setBrendOpreme()
{

	cout << "\t\t\tMolimo unesite naziv prozivodjaca opreme: ";
	cin.getline(this->brendAudioOpreme, 20);

}

char* Oprema::getBrendOpreme()
{

	return this->brendAudioOpreme;

}

void Oprema::setCijenaOpreme()
{

	cout << "\t\t\tMolimo unesite cijenu opreme: ";
	cin >> this->cijenaOpreme;

	cin.ignore();

}

float Oprema::getCijenaOpreme()
{
	return this->cijenaOpreme;
}


void Oprema::setBrojOpremeNaStanju()
{

	cout << "\t\t\tUnesi broj opreme koju zelite unijeti: ";
	cin >> this->brojOpremeNaStanju;
	cin.ignore();

}

int Oprema::getBrojOpremeNaStanju()
{

	return this->brojOpremeNaStanju;

}

void Oprema::setVrstaOpreme(VrstaOpreme x)
{

	this->vrsta_opreme = x;

}

VrstaOpreme Oprema::getVrstaOpreme()
{

	return this->vrsta_opreme;

}

void Oprema::unesiOpremu()
{

	system("cls");



	cin.ignore();

	this->setNazivOpreme();
	this->setBrendOpreme();

	cout << "\t\t\tDa li je oprema audio ili binska?\n";
	cout << "\t\t\t1. Audio oprema\n";
	cout << "\t\t\t2. Binska oprema\n";

	int izborVrsteOpreme;
	cout << "\t\t\tVas izbor je: ";
	cin >> izborVrsteOpreme;
	cin.ignore();

	if (izborVrsteOpreme == 1) {
		this->setVrstaOpreme(audio_oprema);
		cout << "\n\t\t\tUnosite podatke o audio opremi!\n";
	}

	else {
		this->setVrstaOpreme(binska_oprema);
		cout << "\n\t\t\tUnosite podatke o binskoj opremi!\n";

	}

	this->setCijenaOpreme();
	this->setBrojOpremeNaStanju();

}


void Oprema::povecajBrojOpremeNaStanju(int x)
{

	this->brojOpremeNaStanju += x;

}

void Oprema::smanjiBrojOpremeNaStanju(int x)
{

	this->brojOpremeNaStanju -= x;

}

