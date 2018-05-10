#pragma once
#include "Organizm.h"

class Roslina : public Organizm {
public:
	Roslina(char typ, int sila, int inicjatywa, int wiek, int pozycjaX, int pozycjaY, Swiat * swiat) : Organizm(typ, sila, inicjatywa, wiek, pozycjaX, pozycjaY, swiat) {};
	void Akcja();
	void Kolizja(Organizm * ofiara);
	virtual void Rysuj() {};
};