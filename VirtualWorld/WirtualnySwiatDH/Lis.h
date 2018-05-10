#pragma once
#include "Zwierze.h"

class Lis : public Zwierze {
public:
	Lis(int wiek, int pozycjaX, int pozycjaY, Swiat * swiat) : Zwierze('l', 3, 7, wiek, pozycjaX, pozycjaY, swiat) {};
	void Akcja();
	void Rysuj();
};