#pragma once

enum VrstaOpreme { audio_oprema = 0, binska_oprema };

class Oprema
{

private:

	char brendAudioOpreme[20];
	char nazivOpreme[20];
	int brojOpremeNaStanju;
	float cijenaOpreme;

	VrstaOpreme vrsta_opreme;

public:

	//Popis inventara/opreme
	//Funkcionalnosti dostupne samo zaposlenim

	Oprema() {};

	void setVrstaOpreme(VrstaOpreme x);
	VrstaOpreme getVrstaOpreme();

	void setNazivOpreme();
	char* getNazivOpreme();

	void setBrendOpreme();
	char* getBrendOpreme();

	void setCijenaOpreme();
	float getCijenaOpreme();

	void setBrojOpremeNaStanju();
	int getBrojOpremeNaStanju();

	void unesiOpremu();

	void povecajBrojOpremeNaStanju(int x);
	void smanjiBrojOpremeNaStanju(int x);

	~Oprema() {};

};

