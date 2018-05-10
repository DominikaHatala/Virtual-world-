#pragma once
#include "Zwierze.h"

class Zolw : public Zwierze {
public:
	Zolw(int wiek, int pozycjaX, int pozycjaY, Swiat * swiat) : Zwierze('z', 2, 1, wiek, pozycjaX, pozycjaY, swiat) {};
	void Akcja();
	void Kolizja(Organizm * ofiara);
	void Rysuj();
};