#include "Guarana.h"
#include "Swiat.h"
#include <iostream>

void Guarana::Kolizja(Organizm * ofiara) {
	ofiara->ustawSile(ofiara->pobierzSile() + 3);
	int index = this->pobierzSwiat()->zwrocIndeks(this->pobierzPozycjeX(), this->pobierzPozycjeY());
	this->pobierzSwiat()->organizmy[index] = NULL;
	std::cout << ofiara->pobierzTyp() << " zjadl guarane i jego sila zwiekszyla sie o 3. \n";
}

void Guarana::Rysuj() {
	std::cout << "G";
}