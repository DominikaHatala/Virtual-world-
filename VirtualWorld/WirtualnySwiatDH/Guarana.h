#pragma once
#include "Roslina.h"

class Guarana : public Roslina {
public:
	Guarana(int wiek, int pozycjaX, int pozycjaY, Swiat * swiat) : Roslina('g', 0, 0, wiek, pozycjaX, pozycjaY, swiat) {};
	void Kolizja(Organizm * ofiara);
	void Rysuj();
};