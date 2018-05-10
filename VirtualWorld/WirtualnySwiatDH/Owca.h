#pragma once
#include "Zwierze.h"

class Owca : public Zwierze {
public:
	Owca(int wiek, int pozycjaX, int pozycjaY, Swiat * swiat) : Zwierze('o', 4, 4, wiek, pozycjaX, pozycjaY, swiat) {};
	void Rysuj();
}; 