___________________________________________________________________________________

Predmet: Objekto-orijentisano programiranje

Pri realizaciji projekta učestvovali: Emir Baručija; Ahmed Babić; Imran Agić

Broj indeksa: 140; 85; 89
___________________________________________________________________________________

Naziv projekta: Firma „Rental Partner“ (audio sistemi)

Nastavnik: Doc. dr. Adnan Dželihodžić

Saradnik: V. as. mr. Edin Tabak
___________________________________________________________________________________


##			OPIS PROJEKTA
*Program firme koja se bavi rentanjem, servisiranjem i prodajom audio sistema

Završni projekat iz predmeta objekto-orijentisano programiranje.
Program nudi tri (3) korisnička režima: administracija firme, radnici, te kupci, ili korisnici.
Ukoliko koristite ovaj program kao administracija firme „Rental Partner“ imate mogućnost „zapošljavanja radnik“ ili samo unošenja već zaposlenih u sistem, također možete izvršiti provjeru to jeste ispis svih radnika. Na kraju u mogućnosti ste nekome od radnika dati otkaz, te će taj isti radnik biti uklonjen sa spiska zaposlenih.
Ukoliko koristite ovaj program kao radnik firme „Rental Partner“ imate mogućnost kreiranja početne veličine skladišta, to jeste količine stvari koje skladište u samom početku može primiti. Kasnijim unošenjem kapacitet skladišta se povećava, jer nema određen kapacitet zbog prostora. 
Pored toga možete izvršiti unos opreme, te istu ispisati koja će kasnije služiti kao meni koji će pokretati korisnici ovog programa.
Naposljetku u svakom momentu možete provjeriti koliko stvari se nalazi u skladištu zbog same orijentacije.
 

Ukoliko koristite ovaj program kao korisnik ili kupac, takoreći, prije svega Vam se nudi opcija sa ispisom čitavog inventara, to jeste dijelova i sistema koji se već nalaze pohranjeni u isti.
U svakom momentu možete izvršiti pretragu skladišta prema nazivu opreme, ali i željenom brendu ukoliko sklapate kompletan sistem.
Narudžbu vršite tako što unosite vrstu opreme koju trebate, te količinu iste, a onda Vam sistem javlja da li ste to nalazi u sistemu i da li Vam može biti isporučeno. 
Kako bi firma bila potpuno ispravna nakon svake narudžbe dobijate fiskalni račun.
Input-i su osigurani za većinu mogućih grešaka koje korisnik može napraviti, bar za one kojih smo se mi mogli sjetiti dok smo radili na ovom programu.


#	OPIS NEOPHODNIH ELEMENATA KORIŠTENIH U PROJEKTU
*Navedeni elementi koji su bili „must have“ u ovom projektu


1.	
3 klase:

Pored tri (3) klase koje su bile obavezne, u projektu se nalazi još osam (8) koje su također po našem mišljenju bile neophodne kako bi sistem dosegao svoj maksimum.
Klase: „Kupac“, „Meni“, „Oprema“, „Plata“, „Radnik“, „Skladište“, „Lični podaci“.

2.
Enumeracije

Mnoge klase imaju u svom sastavu enumeracije kao što npr. klasa „Radnik“ ima enumeraciju koja daje mogućnosti administraciji firme pri zapošljavanju radnika izbor između vrste posla koji će taj radnik obavljati. S tim enumeracija daje izbor „terenski radnik“, ali i „kancelarijski“.
Na ovom primjeru su zasnovane i ostale enumeracije, apropo tome nije ih potrebno navoditi.

3.
Pametni pokazivači

Pametni pokazivači su iskorišteni kao varijable koje su se koristile pri računanju mjesečnih prihoda. Ovo je samo jedan od primjera.

4.
Iznimke

Iskorištene u sektoru koji vrši pretragu radnika po imenu.

5.
Virtuelne funkcije

6.
Preopterećene operatore

Korišteno pri unosi i ispisu radnika koje unosi administracija firme, u klasi „Plata“.

7.
Nasljeđivanje

Korišteno pri upotrebi i primjeni ličnih podataka osoba koje unose iste u sistem, bilo to riječ o zaposlenom u firmi ili korisniku/kupcu koji želi izvršiti narudžbu.

8.
Rad sa datotekama

Ispisivanje fiskalnog računa kroz tekstualnu datoteku.

9.
Meni

Svaki od načina rada, za administraciju/zaposlene/kupce ima svoj meni, kao i meni pri samom pokretanju programa, ali i završetku istog.

![Graphic design](https://github.com/OOP-PTF-2020/Grupa18/blob/main/IMAGE/newtest.png)
![Our photo](https://github.com/OOP-PTF-2020/Grupa18/blob/main/IMAGE/newtest_us.png)
