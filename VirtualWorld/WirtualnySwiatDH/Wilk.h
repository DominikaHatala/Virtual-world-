#pragma once
#include "Zwierze.h"

class Wilk : public Zwierze {
public:
	Wilk(int wiek, int pozycjaX, int pozycjaY, Swiat * swiat) : Zwierze('w', 9, 5, wiek, pozycjaX, pozycjaY, swiat) {};
	void Rysuj();
};