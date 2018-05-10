#include <iostream>
#include "Jagoda.h"
#include "Swiat.h"

void Jagoda::Rysuj() {
	std::cout << "J";
}

void Jagoda::Kolizja(Organizm * ofiara) {
	int indeksJagody = this->pobierzSwiat()->zwrocIndeks(this->pobierzPozycjeX(), this->pobierzPozycjeY());
	int indeksOfiary = ofiara->pobierzSwiat()->zwrocIndeks(ofiara->pobierzPozycjeX(), ofiara->pobierzPozycjeY());

	this->pobierzSwiat()->organizmy[indeksJagody] = NULL;
	this->pobierzSwiat()->organizmy[indeksOfiary] = NULL;

	std::cout << ofiara->pobierzTyp() << " zjadl " << this->pobierzTyp() << " i zmarl.\n";
}