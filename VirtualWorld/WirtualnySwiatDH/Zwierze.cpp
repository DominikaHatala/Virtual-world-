#include "Swiat.h"
#include "Zwierze.h"
#include <cstdlib>
#include <iostream>

void Zwierze::Akcja() {
	int kierunek = std::rand() % 8;
	/*
	0 1 2
	3   4
	5 6 7
	*/
	int pozX = this->pobierzPozycjeX();
	int pozY = this->pobierzPozycjeY();

	switch (kierunek)
	{
	case 0:
		if (pozX > 1 && pozY > 1) {
			pozX--;
			pozY--;
		}
		break;
	case 1:
		if (pozY > 1) {
			pozY--;
		}
		break;
	case 2:
		if (pozX < plansza - 2 && pozY > 1) {
			pozX++;
			pozY--;
		}
		break;
	case 3:
		if (pozX > 1) {
			pozX--;
		}
		break;
	case 4:
		if (pozX < plansza - 2) {
			pozX++;
		}
		break;
	case 5:
		if (pozX > 1 && pozY < plansza - 2) {
			pozX--;
			pozY++;
		}
		break;
	case 6:
		if (pozY < plansza - 2) {
			pozY++;
		}
		break;
	case 7:
		if (pozX < plansza - 2 && pozY < plansza - 2) {
			pozX++;
			pozY++;
		}
		break;
	default:
		break;
	}

	Organizm * ofiara = NULL;

	if (pozX >= 1 && pozX < plansza - 2 && pozY >= 1 && pozY < plansza - 2) {
		int indeksOfiary = this->pobierzSwiat()->zwrocIndeks(pozX, pozY);

		if (indeksOfiary != -1) {
			ofiara = this->pobierzSwiat()->organizmy[indeksOfiary];
			this->Kolizja(ofiara);
		}
		else {
			this->ustawPozycjeX(pozX);
			this->ustawPozycjeY(pozY);
		}
	}
}

void Zwierze::Kolizja(Organizm * ofiara) {
	if (ofiara != NULL) {
		if (this->pobierzTyp() == ofiara->pobierzTyp()) {
			int index = this->pobierzSwiat()->zwrocIndeks(ofiara->pobierzPozycjeX(), ofiara->pobierzPozycjeY());

			this->stworzNowyOrganizm(this->pobierzSwiat()->organizmy[index]->pobierzPozycjeX(), this->pobierzSwiat()->organizmy[index]->pobierzPozycjeY());
		}
		else if (this->pobierzSile() >= ofiara->pobierzSile() && ofiara->pobierzTyp() == 'g') {
			Organizm * atakujacy = this;
			ofiara->Kolizja(atakujacy);
		}
		else if (this->pobierzSile() >= ofiara->pobierzSile() && ofiara->pobierzTyp() == 'c') {
			Organizm * atakujacy = this;
			ofiara->Kolizja(atakujacy);
		}
		else {
			this->Walka(ofiara);
		}
	}
}

void Zwierze::Walka(Organizm * ofiara) {
	if (ofiara->pobierzTyp() == 'g' || ofiara->pobierzTyp() == 'b'){
		ofiara->Kolizja(this);
		return;
	}

   else if (this->pobierzSile() >= ofiara->pobierzSile()) {
		int index = this->pobierzSwiat()->zwrocIndeks(ofiara->pobierzPozycjeX(), ofiara->pobierzPozycjeY());

		this->ustawPozycjeX(ofiara->pobierzPozycjeX());
		this->ustawPozycjeY(ofiara->pobierzPozycjeY());

		std::cout << this->pobierzTyp() << " zjadl " << ofiara->pobierzTyp() << "." << std::endl;

		this->pobierzSwiat()->organizmy[index] = NULL;
	}
	else {
		int index = this->pobierzSwiat()->zwrocIndeks(this->pobierzPozycjeX(), this->pobierzPozycjeY());

		std::cout << ofiara->pobierzTyp() << " zjadl " << this->pobierzTyp() << "." << std::endl;

		this->pobierzSwiat()->organizmy[index] = NULL;
	}
}