#include "Zwierze.h"
#include "Swiat.h"
#include "Organizm.h"
#include "Lis.h"
#include <iostream>

void Lis::Rysuj() {
	std::cout << "L";
}

void Lis::Akcja() {
	int kierunek = std::rand() % 8;

	int pozX = this->pobierzPozycjeX();
	int pozY = this->pobierzPozycjeY();

	switch (kierunek)
	{
	case 0:
		if (this->pobierzSwiat()->zwrocIndeks(pozX - 1, pozY - 1) == -1) {
			Zwierze::Akcja();
		}
		else {
			if (this->pobierzSwiat()->porownajSila(this, this->pobierzSwiat()->organizmy[this->pobierzSwiat()->zwrocIndeks(pozX - 1, pozY - 1)])) {
				Zwierze::Akcja();
			}
		}
		break;
	case 1:
		if (this->pobierzSwiat()->zwrocIndeks(pozX, pozY - 1) == -1) {
			Zwierze::Akcja();
		}
		else {
			if (this->pobierzSwiat()->porownajSila(this, this->pobierzSwiat()->organizmy[this->pobierzSwiat()->zwrocIndeks(pozX, pozY - 1)])) {
				Zwierze::Akcja();
			}
		}
		break;
	case 2:
		if (this->pobierzSwiat()->zwrocIndeks(pozX + 1, pozY - 1) == -1) {
			Zwierze::Akcja();
		}
		else {
			if (this->pobierzSwiat()->porownajSila(this, this->pobierzSwiat()->organizmy[this->pobierzSwiat()->zwrocIndeks(pozX + 1, pozY - 1)])) {
				Zwierze::Akcja();
			}
		}
		break;
	case 3:
		if (this->pobierzSwiat()->zwrocIndeks(pozX - 1, pozY) == -1) {
			Zwierze::Akcja();
		}
		else {
			if (this->pobierzSwiat()->porownajSila(this, this->pobierzSwiat()->organizmy[this->pobierzSwiat()->zwrocIndeks(pozX - 1, pozY)])) {
				Zwierze::Akcja();
			}
		}
		break;
	case 4:
		if (this->pobierzSwiat()->zwrocIndeks(pozX + 1, pozY) == -1) {
			Zwierze::Akcja();
		}
		else {
			if (this->pobierzSwiat()->porownajSila(this, this->pobierzSwiat()->organizmy[this->pobierzSwiat()->zwrocIndeks(pozX + 1, pozY)])) {
				Zwierze::Akcja();
			}
		}
		break;
	case 5:
		if (this->pobierzSwiat()->zwrocIndeks(pozX - 1, pozY + 1) == -1) {
			Zwierze::Akcja();
		}
		else {
			if (this->pobierzSwiat()->porownajSila(this, this->pobierzSwiat()->organizmy[this->pobierzSwiat()->zwrocIndeks(pozX - 1, pozY + 1)])) {
				Zwierze::Akcja();
			}
		}
		break;
	case 6:
		if (this->pobierzSwiat()->zwrocIndeks(pozX, pozY + 1) == -1) {
			Zwierze::Akcja();
		}
		else {
			if (this->pobierzSwiat()->porownajSila(this, this->pobierzSwiat()->organizmy[this->pobierzSwiat()->zwrocIndeks(pozX, pozY + 1)])) {
				Zwierze::Akcja();
			}
		}
		break;
	case 7:
		if (this->pobierzSwiat()->zwrocIndeks(pozX + 1, pozY + 1) == -1) {
			Zwierze::Akcja();
		}
		else {
			if (this->pobierzSwiat()->porownajSila(this, this->pobierzSwiat()->organizmy[this->pobierzSwiat()->zwrocIndeks(pozX + 1, pozY + 1)])) {
				Zwierze::Akcja();
			}
		}
		break;
	default:
		break;
	}
}