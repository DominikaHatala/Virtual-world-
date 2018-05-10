#pragma once
#include "Roslina.h"

class Trawa : public Roslina {
public:
	Trawa(int wiek, int pozycjaX, int pozycjaY, Swiat * swiat) : Roslina('t', 0, 0, wiek, pozycjaX, pozycjaY, swiat) {};
	void Rysuj();
};