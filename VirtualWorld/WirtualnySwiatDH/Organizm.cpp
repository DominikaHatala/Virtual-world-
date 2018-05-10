#include "Organizm.h"
#include "Swiat.h"

Organizm::Organizm() {};

Organizm::Organizm(char typ, int sila, int inicjatywa, int wiek, int pozycjaX, int pozycjaY, Swiat * swiat) {
	this->typ = typ;
	this->sila = sila;
	this->inicjatywa = inicjatywa;
	this->wiek = wiek;
	this->pozycjaX = pozycjaX;
	this->pozycjaY = pozycjaY;
	this->swiat = swiat;
}

void Organizm::ustawTyp(char typ) {
	this->typ = typ;
}

void Organizm::ustawSile(int sila) {
	this->sila = sila;
}

void Organizm::ustawInicjatywe(int inicjatywa) {
	this->inicjatywa = inicjatywa;
}

void Organizm::ustawWiek(int wiek) {
	this->wiek = wiek;
}

void Organizm::ustawPozycjeX(int pozycjaX) {
	this->pozycjaX = pozycjaX;
}

void Organizm::ustawPozycjeY(int pozycjaY) {
	this->pozycjaY = pozycjaY;
}

void Organizm::ustawSwiat(Swiat * swiat) {
	this->swiat = swiat;
}

char Organizm::pobierzTyp() {
	return this->typ;
}

int Organizm::pobierzSile() {
	return this->sila;
}

int Organizm::pobierzInicjatywe() {
	return this->inicjatywa;
}

int Organizm::pobierzWiek() {
	return this->wiek;
}

int Organizm::pobierzPozycjeX() {
	return this->pozycjaX;
}

int Organizm::pobierzPozycjeY() {
	return this->pozycjaY;
}

Swiat * Organizm::pobierzSwiat() {
	return this->swiat;
}

void Organizm::stworzNowyOrganizm(int pozycjaX, int pozycjaY) {
	/*
	0 1 2
	3   4
	5 6 7
	*/
	int kierunek = std::rand() % 8;

	switch (kierunek)
	{
	case 0:
		if (this->swiat->zwrocIndeks(pozycjaX - 1, pozycjaY - 1) == -1) {
			if (pozycjaX - 1 >= 1 && pozycjaX - 1 < plansza - 1 && pozycjaY - 1 >= 1 && pozycjaY - 1 < plansza - 1) {
				this->swiat->dodajOrganizm(this->typ, pozycjaX - 1, pozycjaY - 1);
				std::cout << this->typ << " rozmnozyl sie.\n";
			}
		}
		break;
	case 1:
		if (this->swiat->zwrocIndeks(pozycjaX, pozycjaY - 1) == -1) {
			if (pozycjaX >= 1 && pozycjaX < plansza - 1 && pozycjaY - 1 >= 1 && pozycjaY - 1 < plansza - 1) {
				this->swiat->dodajOrganizm(this->typ, pozycjaX, pozycjaY - 1);
				std::cout << this->typ << " rozmnozyl sie.\n";
			}
		}
		break;
	case 2:
		if (this->swiat->zwrocIndeks(pozycjaX + 1, pozycjaY - 1) == -1) {
			if (pozycjaX + 1 >= 1 && pozycjaX + 1 < plansza - 1 && pozycjaY - 1 >= 1 && pozycjaY - 1 < plansza - 1) {
				this->swiat->dodajOrganizm(this->typ, pozycjaX + 1, pozycjaY - 1);
				std::cout << this->typ << " rozmnozyl sie.\n";
			}
		}
		break;
	case 3:
		if (this->swiat->zwrocIndeks(pozycjaX - 1, pozycjaY) == -1) {
			if (pozycjaX - 1 >= 1 && pozycjaX - 1 < plansza - 1 && pozycjaY >= 1 && pozycjaY < plansza - 1) {
				this->swiat->dodajOrganizm(this->typ, pozycjaX - 1, pozycjaY);
				std::cout << this->typ << " rozmnozyl sie.\n";
			}
		}
		break;
	case 4:
		if (this->swiat->zwrocIndeks(pozycjaX + 1, pozycjaY) == -1) {
			if (pozycjaX + 1 >= 1 && pozycjaX + 1 < plansza - 1 && pozycjaY >= 1 && pozycjaY < plansza - 1) {
				this->swiat->dodajOrganizm(this->typ, pozycjaX + 1, pozycjaY);
				std::cout << this->typ << " rozmnozyl sie.\n";
			}
		}
		break;
	case 5:
		if (this->swiat->zwrocIndeks(pozycjaX - 1, pozycjaY + 1) == -1) {
			if (pozycjaX - 1 >= 1 && pozycjaX - 1 < plansza - 1 && pozycjaY + 1 >= 1 && pozycjaY + 1 < plansza - 1) {
				this->swiat->dodajOrganizm(this->typ, pozycjaX - 1, pozycjaY + 1);
				std::cout << this->typ << " rozmnozyl sie.\n";
			}
		}
		break;
	case 6:
		if (this->swiat->zwrocIndeks(pozycjaX, pozycjaY + 1) == -1) {
			if (pozycjaX >= 1 && pozycjaX < plansza - 1 && pozycjaY + 1 >= 1 && pozycjaY + 1 < plansza - 1) {
				this->swiat->dodajOrganizm(this->typ, pozycjaX, pozycjaY + 1);
				std::cout << this->typ << " rozmnozyl sie.\n";
			}
		}
		break;
	case 7:
		if (this->swiat->zwrocIndeks(pozycjaX + 1, pozycjaY + 1) == -1) {
			if (pozycjaX + 1 >= 1 && pozycjaX + 1 < plansza - 1 && pozycjaY + 1 >= 1 && pozycjaY + 1 < plansza - 1) {
				this->swiat->dodajOrganizm(this->typ, pozycjaX + 1, pozycjaY + 1);
				std::cout << this->typ << " rozmnozyl sie.\n";
			}
		}
		break;
	default:
		break;
	}
}
