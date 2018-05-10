#include "Zolw.h"
#include "Zwierze.h"
#include <iostream>
#include <ctime>

void Zolw::Rysuj() {
	std::cout << "Z";
}

void Zolw::Akcja() {
	int szansa = std::rand() % 4;

	if (szansa == 0) {
		Zwierze::Akcja();
	}
}

void Zolw::Kolizja(Organizm * ofiara) {
	int pozX = this->pobierzPozycjeX();
	int pozY = this->pobierzPozycjeY();

	if (ofiara->pobierzSile() < 5) {
		std::cout << this->pobierzTyp() << " obronil sie.\n";
	}
	else {
		Zwierze::Kolizja(ofiara);
	}
}