#pragma once
#include "Zwierze.h"

class Antylopa : public Zwierze {
public:
	Antylopa(int wiek, int pozycjaX, int pozycjaY, Swiat * swiat) : Zwierze('a', 4, 4, wiek, pozycjaX, pozycjaY, swiat) {};
	void Akcja();
	void Kolizja(Organizm * ofiara);
	void Rysuj();
	void Ucieczka(int pozycjaX, int pozycjaY, Organizm * ofiara);
};