#include <iostream>
#include <string>
#include "Datum.h"
#include <iomanip>
#include "Meni.h"
#include "Plata.h"
#include "Oprema.h"
#include "Skladiste.h"

using std::cin;
using std::cout;
using std::string;
using std::endl;

struct Login {

	string username_korisnika;
	string sifra_korisnika;
	bool login_uspjesan = false;

	void login_uposlenika() {

		Login l;

		cout << endl;

		cout << endl;
		cout << endl;

		cout << "\t\t\t         ____________________ " << endl;
		cout << "\t\t\t        |                    |" << endl;
		cout << "\t\t\t        |  LOGIN UPOSLENIKA  |" << endl;
		cout << "\t\t\t        |____________________|" << endl;

		cout << endl;
		cout << endl;

	}

};

int main() {

	Login l;
	Datum datum;
	Plata adminRadnici;
	Oprema oprema;
	Radnik radnik;
	Skladiste skladiste;

	Meni pozoviMeni;

	/*datum.postaviDatum();
	datum.ispisDatum();*/

	int nastaviIzadji;

	do {

		cout << "\n\n\t\t\t RENTAL PARTNER\n";
		cout << "\t\t\tZa nastavak pritisnite 1\n";
		cout << "\t\t\tZa izlaz iz programa pritisnite 2\n";
		cout << "\t\t\tIzbor: ";
		cin >> nastaviIzadji;
		cin.ignore();

		if (nastaviIzadji == 1) {

			do {

				system("CLS");

				cout << "\n\n\t\t\t RENTAL PARTNER\n";
				cout << "\t\t\t  _________________________\n";
				cout << "\t\t\t |                         |\n";
				cout << "\t\t\t |  ZAPOSLENIK / KORISNIK  |\n";
				cout << "\t\t\t |_________________________|\n";

				cout << "\n\t\t\t        1 - Administracija ";
				cout << "\n\t\t\t        2 - Uposlenik ";
				cout << "\n\t\t\t        3 - Kupac ";


				cout << "\n\n\t\t\t Unesite redni broj opcije: ";
				int login;
				cin >> login;
				cin.ignore();

				int RB_opcije;

				if (login == 1) {

					system("CLS");

					bool login_uspjesan = false;

					do {

						l.login_uposlenika();

						cout << "\t\t\t    Unesite korisnicko ime: ";
						cin >> l.username_korisnika;

						cout << "\n\t\t\t             Unesite sifru: ";
						cin >> l.sifra_korisnika;

						if (l.username_korisnika == "Admin" && l.sifra_korisnika == "Admin") {

							cout << "\n\n\n\n\t\t\t     ---Uspjesno ste prijavljeni---";

							l.login_uspjesan == true;

							cout << "\n\n\n\n\t\t\t\t\t\t\t Pritisnite ENTER\n\t\t\t\t\t\t\t   za nastavak\n";
							cout << "\n\n\t\t\t\t\t\t\t";

							system("PAUSE");

							do {

								system("CLS");

								pozoviMeni.adminMeni();

								cout << endl;

								cout << "\t\t\t  _____________________________________\n";
								cout << "\t\t\t |                                     |\n";
								cout << "\t\t\t |  UNESITE REDNI BROJ ZELJENE OPCIJE  |\n";
								cout << "\t\t\t |_____________________________________|\n";

								cout << "\n\n\t\t\t    Birate opciju pod rednim brojem: ";

								cin >> RB_opcije;
								cin.ignore();

								if (RB_opcije == 1) {

									adminRadnici.setRadnik();

									cout << "\n\n\t\t\tRadnik uspjesno unesen u sistem!\n";

									cout << "\n\n\n\t\t\t\t\t\t\t Pritisnite ENTER\n\t\t\t\t\t   za povratak u glavni izbornik\n";

									system("PAUSE>null");
									system("CLS");

								}

								if (RB_opcije == 2) {

									adminRadnici.ispisRadnika();

									cout << "\n\n\n\t\t\t\t\t\t\t Pritisnite ENTER\n\t\t\t\t\t   za povratak u glavni izbornik\n";

									system("PAUSE>null");
									system("CLS");

								}

								if (RB_opcije == 3) {

									adminRadnici.otpustiRadnika();

									cout << "\n\n\n\t\t\t\t\t\t\t Pritisnite ENTER\n\t\t\t\t\t   za povratak u glavni izbornik\n";

									system("PAUSE>null");
									system("CLS");

								}

								if (RB_opcije == 10) {


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

									cout << "\n\n\t\t\t RENTAL PARTNER\n";
									cout << "\t\t\tZa nastavak pritisnite 1\n";
									cout << "\t\t\tZa izlaz iz programa pritisnite 2\n";
									cout << "\t\t\tIzbor: ";
									cin >> nastaviIzadji;
									cin.ignore();


								}

								system("CLS");

								cout << endl;
								cout << endl;

							} while (RB_opcije != 10);

						}

						system("CLS");

						cout << "\n\n\t\t\t RENTAL PARTNER\n";
						cout << "\t\t\t  _________________________\n";
						cout << "\t\t\t |                         |\n";
						cout << "\t\t\t |  ZAPOSLENIK / KORISNIK  |\n";
						cout << "\t\t\t |_________________________|\n";

						cout << "\n\t\t\t        1 - Administracija ";
						cout << "\n\t\t\t        2 - Uposlenik ";
						cout << "\n\t\t\t        3 - Kupac ";


						cout << "\n\n\t\t\t Unesite redni broj opcije: ";
						int login;
						cin >> login;
						cin.ignore();

					} while (!l.login_uspjesan && RB_opcije != 10);

				}

				if (login == 2) {


					system("CLS");


					bool login_uspjesan = false;

					do {

						l.login_uposlenika();

						cout << "\t\t\t    Unesite korisnicko ime: ";
						cin >> l.username_korisnika;

						cout << "\n\t\t\t             Unesite sifru: ";
						cin >> l.sifra_korisnika;

						if (l.username_korisnika == "Uposlenik" && l.sifra_korisnika == "Uposlenik") {

							cout << "\n\n\n\n\t\t\t     ---Uspjesno ste prijavljeni---";

							l.login_uspjesan == true;

							cout << "\n\n\n\n\t\t\t\t\t\t\t Pritisnite ENTER\n\t\t\t\t\t\t\t   za nastavak\n";

							cout << "\n\t\t\t\t\t\t\t";
							system("PAUSE");

							do {

								system("CLS");

								pozoviMeni.uposlenikMeni();

								cout << endl;

								cout << "\t\t\t  _____________________________________\n";
								cout << "\t\t\t |                                     |\n";
								cout << "\t\t\t |  UNESITE REDNI BROJ ZELJENE OPCIJE  |\n";
								cout << "\t\t\t |_____________________________________|\n";

								cout << "\n\n\t\t\t    Birate opciju pod rednim brojem: ";

								cin >> RB_opcije;
								cin.ignore();

								if (RB_opcije == 1) {

									if (skladiste.getKapacitetStvariUSkladistu() != 0) {

										cout << "\n\t\t\tSkladiste je vec kreirano, a kapacitet istog je " << skladiste.getKapacitetStvariUSkladistu() << "\n\t\t\tprimjeraka koji mogu biti skladisteni!\n";

									}

									else {

										skladiste.setKapacitetStvariUSkladistu();

										cout << "\n\n\n\t\t\t\t\t\t\t Pritisnite ENTER\n\t\t\t\t\t   za povratak u glavni izbornik\n";
										
									}

									system("PAUSE>null");
									system("CLS");

								}

								if (RB_opcije == 2) {

									skladiste.setSpremiOpremuUSkladiste();

									cout << "\n\n\t\t\tOprema uspjesno skladistena!\n";
									cout << "\n\n\n\t\t\t\t\t\t\t Pritisnite ENTER\n\t\t\t\t\t   za povratak u glavni izbornik\n";

									system("PAUSE>null");
									system("CLS");

								}


								if (RB_opcije == 3) {

									cout << "\n\n\n\t\t\tU skladistu se trenutno nalazi " << skladiste.getUkupanBrojOpremeNaStanju() << " stvari!\n";

									cout << "\n\n\n\t\t\t\t\t\t\t Pritisnite ENTER\n\t\t\t\t\t   za povratak u glavni izbornik\n";

									system("PAUSE>null");
									system("CLS");

								}

								if (RB_opcije == 4) {

									skladiste.prikazSkladista();

									cout << "\n\n\n\t\t\t\t\t\t\t Pritisnite ENTER\n\t\t\t\t\t   za povratak u glavni izbornik\n";

									system("PAUSE>null");
									system("CLS");

								}

								if (RB_opcije == 10) {

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

									cout << "\n\n\t\t\t RENTAL PARTNER\n";
									cout << "\t\t\tZa nastavak pritisnite 1\n";
									cout << "\t\t\tZa izlaz iz programa pritisnite 2\n";
									cout << "\t\t\tIzbor: ";
									cin >> nastaviIzadji;
									cin.ignore();

								}

								system("CLS");

								cout << endl;
								cout << endl;

							} while (RB_opcije != 10 && nastaviIzadji != 2);

						}



					} while (!l.login_uspjesan && RB_opcije != 10);


				}

				if (login == 3) {


					system("CLS");



					do {

						system("CLS");

						pozoviMeni.kupacMeni();

						cout << endl;

						cout << "\t\t\t  _____________________________________\n";
						cout << "\t\t\t |                                     |\n";
						cout << "\t\t\t |  UNESITE REDNI BROJ ZELJENE OPCIJE  |\n";
						cout << "\t\t\t |_____________________________________|\n";

						cout << "\n\n\t\t\t    Birate opciju pod rednim brojem: ";

						cin >> RB_opcije;
						cin.ignore();

						if (RB_opcije == 1) {

							skladiste.prikazSkladista();


							cout << "\n\n\n\t\t\t\t\t\t\t Pritisnite ENTER\n\t\t\t\t\t   za povratak u glavni izbornik\n";

							system("PAUSE>null");
							system("CLS");

						}

						if (RB_opcije == 2) {

							skladiste.pretragaPoNazivu();

							cout << "\n\n\t\t\tOprema uspjesno skladistena!\n";
							cout << "\n\n\n\t\t\t\t\t\t\t Pritisnite ENTER\n\t\t\t\t\t   za povratak u glavni izbornik\n";

							system("PAUSE>null");
							system("CLS");

						}


						if (RB_opcije == 3) {

							cout << "\n\n\n\t\t\tU skladistu se trenutno nalazi " << skladiste.getUkupanBrojOpremeNaStanju() << " stvari!\n";

							cout << "\n\n\n\t\t\t\t\t\t\t Pritisnite ENTER\n\t\t\t\t\t   za povratak u glavni izbornik\n";

							system("PAUSE>null");
							system("CLS");

						}

						if (RB_opcije == 4) {

							skladiste.uzmiIzSkladista();

							cout << "\n\n\n\t\t\t\t\t\t\t Pritisnite ENTER\n\t\t\t\t\t   za povratak u glavni izbornik\n";

							system("PAUSE>null");
							system("CLS");

						}
						
						if (RB_opcije == 5) {

							skladiste.fiskalni_racun();

							cout << "\n\n\n\t\t\t\t\t\t\t Pritisnite ENTER\n\t\t\t\t\t   za povratak u glavni izbornik\n";

							system("PAUSE>null");
							system("CLS");

						}

						if (RB_opcije == 10) {

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

							cout << "\n\n\t\t\t RENTAL PARTNER\n";
							cout << "\t\t\tZa nastavak pritisnite 1\n";
							cout << "\t\t\tZa izlaz iz programa pritisnite 2\n";
							cout << "\t\t\tIzbor: ";
							cin >> nastaviIzadji;
							cin.ignore();

						}

						system("CLS");

						cout << endl;
						cout << endl;

					} while (nastaviIzadji != 2);

				}


			} while (nastaviIzadji != 2);

		}

		else {

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

			EXIT_SUCCESS;

		}

	} while (nastaviIzadji != 2);
	

}

