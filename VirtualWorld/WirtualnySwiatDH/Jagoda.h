#pragma once
#include "Roslina.h"

class Jagoda : public Roslina {
public:
	Jagoda(int wiek, int pozycjaX, int pozycjaY, Swiat * swiat) : Roslina('j', 99, 0, wiek, pozycjaX, pozycjaY, swiat) {};
	void Kolizja(Organizm * ofiara);
	void Rysuj();
}; 
