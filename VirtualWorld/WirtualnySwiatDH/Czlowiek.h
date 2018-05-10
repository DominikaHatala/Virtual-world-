#pragma once
#include "Zwierze.h"

class Czlowiek : public Zwierze {
private:
	int wlaczSpecjalnaUmiejetnosc = 0;
	int licznikSpecjalnejUmiejetnosci = 5;
	bool czyUmiejetnosc = false;
	void SpecjalnaUmiejetnosc();
public:
	Czlowiek(int wiek, int pozycjaX, int pozycjaY, Swiat * swiat) : Zwierze('c', 4, 5, wiek, pozycjaX, pozycjaY, swiat) {};
	void Akcja();
	void Poruszanie();
	void Kolizja(Organizm * ofiara);
	void Rysuj();
};