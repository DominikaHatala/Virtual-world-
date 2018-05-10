#pragma once
#include "Roslina.h"

class Mlecz : public Roslina {
public:
	Mlecz(int wiek, int pozycjaX, int pozycjaY, Swiat * swiat) : Roslina('m', 0, 0, wiek, pozycjaX, pozycjaY, swiat) {};
	void Akcja();
	void Rysuj();
};