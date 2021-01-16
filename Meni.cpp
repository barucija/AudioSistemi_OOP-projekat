#include "Meni.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void Meni::adminMeni()
{

	cout << endl;

	cout << endl;
	cout << endl;

	cout << "\t\t\t         ________________" << endl;
	cout << "\t\t\t        |                |" << endl;
	cout << "\t\t\t        |   ADMIN MENI   |" << endl;
	cout << "\t\t\t        |________________|" << endl;

	cout << endl;
	cout << endl;

	cout << "\t\t\t ODABERITE REDNI BROJ ZELJENE OPCIJE \n";

	cout << endl;

	cout << "\t\t\t          1. Unos radnika u sistem\n";
	cout << "\t\t\t          2. Pregled radnika\n";
	cout << "\t\t\t          3. Otpusti radnika\n";

	cout << "\t\t\t          7. Promjena nacina rada\n";
	cout << "\t\t\t          10. Izlaz\n";

	cout << endl;
	cout << endl;
	cout << endl;

	cout << "_____________________________________________________________________________________________\n\n";

	cout << endl;

	cout << "\t\t\t  _____________________________________\n";
	cout << "\t\t\t |                                     |\n";
	cout << "\t\t\t |  UNESITE REDNI BROJ ZELJENE OPCIJE  |\n";
	cout << "\t\t\t |_____________________________________|\n";

	cout << "\n\n\t\t\t    Birate opciju pod rednim brojem: ";
}

void Meni::uposlenikMeni()
{

	cout << endl;

	cout << endl;
	cout << endl;

	cout << "\t\t\t         ____________________" << endl;
	cout << "\t\t\t        |                    |" << endl;
	cout << "\t\t\t        |   UPOSLENIK MENI   |" << endl;
	cout << "\t\t\t        |____________________|" << endl;

	cout << endl;
	cout << endl;

	cout << "\t\t\t ODABERITE REDNI BROJ ZELJENE OPCIJE \n";

	cout << endl;

	cout << "\t\t\t          1. Kreiranje skladista (samo pri prvom pokretanju se koristi)\n";
	cout << "\t\t\t          2. Unos opreme u sistem\n";
	cout << "\t\t\t          3. Popunjenost skladista\n";
	cout << "\t\t\t          4. Prikaz skladista\n";

	cout << "\t\t\t          7. Promjena nacina rada\n";
	cout << "\t\t\t          10. Izlaz\n";

	cout << endl;
	cout << endl;
	cout << endl;

	cout << "_____________________________________________________________________________________________\n\n";

	cout << endl;

	cout << "\t\t\t  _____________________________________\n";
	cout << "\t\t\t |                                     |\n";
	cout << "\t\t\t |  UNESITE REDNI BROJ ZELJENE OPCIJE  |\n";
	cout << "\t\t\t |_____________________________________|\n";

	cout << "\n\n\t\t\t    Birate opciju pod rednim brojem: ";
}

void Meni::kupacMeni()
{

	cout << endl;

	cout << endl;
	cout << endl;

	cout << "\t\t\t         ________________" << endl;
	cout << "\t\t\t        |                |" << endl;
	cout << "\t\t\t        |   KUPAC MENI   |" << endl;
	cout << "\t\t\t        |________________|" << endl;

	cout << endl;
	cout << endl;

	cout << "\t\t\t ODABERITE REDNI BROJ ZELJENE OPCIJE \n";

	cout << endl;

	cout << "\t\t\t          1. Ispis skladista\n";
	cout << "\t\t\t          2. Pretraga skladista po nazivu opreme\n";
	cout << "\t\t\t          3. Pretraga skladista po brendu opreme\n";
	cout << "\t\t\t          4. Narudzba\n";
	cout << "\t\t\t          5. Fiskalni racun\n";

	cout << "\t\t\t          7. Promjena nacina rada\n";
	cout << "\t\t\t          10. Izlaz\n";

	cout << endl;
	cout << endl;
	cout << endl;

	cout << "_____________________________________________________________________________________________\n\n";
	
	cout << endl;

	cout << "\t\t\t  _____________________________________\n";
	cout << "\t\t\t |                                     |\n";
	cout << "\t\t\t |  UNESITE REDNI BROJ ZELJENE OPCIJE  |\n";
	cout << "\t\t\t |_____________________________________|\n";

	cout << "\n\n\t\t\t    Birate opciju pod rednim brojem: ";
}

void Meni::krajnjiMeni()
{
	system("CLS");

	cout << endl;
	cout << endl;

	cout << "\t\t         _____________________________________" << endl;
	cout << "\t\t        |                                     |" << endl;
	cout << "\t\t        |  HVALA NA KORISTENJU NASEG SISTEMA  |" << endl;
	cout << "\t\t        |_____________________________________|" << endl;

	cout << endl;
	cout << endl;
	cout << endl;

	cout << "\n\n\n\t\t\t\t\t\t  Pritisnite ESC za izlazak iz programa\n";

	system("PAUSE>null");
	system("CLS");
}

void Meni::pocetniMeni()
{
	cout << "\n\n\t\t\t RENTAL PARTNER\n";
	cout << "\t\t\tZa nastavak pritisnite 1\n";
	cout << "\t\t\tZa izlaz iz programa pritisnite 2\n";
	cout << "\t\t\tIzbor: ";
}
