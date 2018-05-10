#include "Zwierze.h"
#include "Antylopa.h"
#include "Swiat.h"
#include <ctime>
#include <iostream>

void Antylopa::Akcja() {
	for (int i = 0; i < 2; i++) {
		Zwierze::Akcja();
	}
}

void Antylopa::Kolizja(Organizm * ofiara) {
	std::srand(time(NULL));

	int szansa = std::rand() % 2;

	if (szansa == 0) {
		std::cout << this->pobierzTyp() << " nie moze uciec.\n";
		Zwierze::Kolizja(ofiara);
	}
	else {
		this->Ucieczka(this->pobierzPozycjeX(), this->pobierzPozycjeY(), ofiara);
	}
}

void Antylopa::Rysuj() {
	std::cout << "A";
}

void Antylopa::Ucieczka(int pozycjaX, int pozycjaY, Organizm * ofiara) {

	int pozX = this->pobierzPozycjeX();
	int pozY = this->pobierzPozycjeY();

	bool czyUcieka = false;

	if (this->pobierzSwiat()->zwrocIndeks(pozX - 1, pozY - 1) == -1) {
		this->ustawPozycjeX(pozX - 1);
		this->ustawPozycjeY(pozY - 1);
		czyUcieka = true;
	}
	else if (this->pobierzSwiat()->zwrocIndeks(pozX, pozY - 1) == -1) {
		this->ustawPozycjeX(pozX);
		this->ustawPozycjeY(pozY - 1);
		czyUcieka = true;
	}
	else if (this->pobierzSwiat()->zwrocIndeks(pozX + 1, pozY - 1) == -1) {
		this->ustawPozycjeX(pozX + 1);
		this->ustawPozycjeY(pozY - 1);
		czyUcieka = true;
	}
	else if (this->pobierzSwiat()->zwrocIndeks(pozX - 1, pozY) == -1) {
		this->ustawPozycjeX(pozX - 1);
		this->ustawPozycjeY(pozY);
		czyUcieka = true;
	}
	else if (this->pobierzSwiat()->zwrocIndeks(pozX + 1, pozY) == -1) {
		this->ustawPozycjeX(pozX + 1);
		this->ustawPozycjeY(pozY);
		czyUcieka = true;
	}
	else if (this->pobierzSwiat()->zwrocIndeks(pozX - 1, pozY + 1 ) == -1) {
		this->ustawPozycjeX(pozX - 1);
		this->ustawPozycjeY(pozY + 1);
		czyUcieka = true;
	}
	else if (this->pobierzSwiat()->zwrocIndeks(pozX, pozY + 1) == -1) {
		this->ustawPozycjeX(pozX);
		this->ustawPozycjeY(pozY + 1);
		czyUcieka = true;
	}
	else if (this->pobierzSwiat()->zwrocIndeks(pozX + 1, pozY + 1) == -1) {
		this->ustawPozycjeX(pozX + 1);
		this->ustawPozycjeY(pozY + 1);
		czyUcieka = true;
	}

	if (czyUcieka) {
		ofiara->ustawPozycjeX(pozX);
		ofiara->ustawPozycjeY(pozY);
		std::cout << this->pobierzTyp() << " ucieka.\n";
	}
	else {
		int index = this->pobierzSwiat()->zwrocIndeks(this->pobierzPozycjeX(), this->pobierzPozycjeY());

		ofiara->ustawPozycjeX(pozX);
		ofiara->ustawPozycjeY(pozY);

		std::cout << ofiara->pobierzTyp() << " zjadl " << this->pobierzTyp() << "." << std::endl;
		this->pobierzSwiat()->organizmy[index] = NULL;
	}
}