#include "Roslina.h"
#include "Swiat.h"
#include <iostream>
#include <ctime>

void Roslina::Akcja() {
	int szansa = std::rand() % 100;
	if (szansa == 0) {
		this->stworzNowyOrganizm(this->pobierzPozycjeX(), this->pobierzPozycjeY());
	}
}

void Roslina::Kolizja(Organizm * ofiara) {
	if (ofiara != NULL) {
		if (this->pobierzSile() > ofiara->pobierzSile()) {
			int index = this->pobierzSwiat()->zwrocIndeks(ofiara->pobierzPozycjeX(), ofiara->pobierzPozycjeY());
			this->pobierzSwiat()->organizmy[index] = NULL;
		}
	}
}