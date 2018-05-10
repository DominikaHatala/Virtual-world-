#include "Swiat.h"
#include "Organizm.h"
#include "Antylopa.h"
#include "Jagoda.h"
#include "Lis.h"
#include "Trawa.h"
#include "Guarana.h"
#include "Owca.h"
#include "Mlecz.h"
#include "Zolw.h"
#include "Wilk.h"
#include "Czlowiek.h"
#include <conio.h>
#include <ctime>
#include <algorithm>

int Swiat::pobierzTure() {
	return this->licznikTur;
}

void Swiat::kolejnaTura() {
	std::sort(this->organizmy.begin(), this->organizmy.end(), this->porownajInicjatywa);

	for (int i = 0; i < organizmy.size(); i++) {
		if (this->organizmy[i] != NULL) {
			this->organizmy[i]->ustawWiek(this->organizmy[i]->pobierzWiek() + 1);
			this->organizmy[i]->Akcja();
		}
	}

	this->usunMartwe();
	this->rysujSwiat();
}

void Swiat::rysujSwiat() {
	Organizm * organizm = NULL;

	for (int i = 0; i < plansza; i++) {
		for (int j = 0; j < plansza; j++) {
			for (int k = 0; k < this->organizmy.size(); k++) {
				if (this->organizmy[k]->pobierzPozycjeX() == i && this->organizmy[k]->pobierzPozycjeY() == j) {
					organizm = this->organizmy[k];
					break;
				}
			}

			if (organizm != NULL) {
				organizm->Rysuj();
			}
			else if (i == 0 || i == plansza - 1 || j == 0 || j == plansza - 1 ) {
				std::cout << char(219);
			}
			else {
				std::cout << " ";
			}

			organizm = NULL;
		}

		std::cout << std::endl;
	}
}

void Swiat::dodajOrganizm(char typ, int pozycjaX, int pozycjaY) {
	Organizm * nowyOrganizm = NULL;

	switch (typ) {
	case 'g':
		nowyOrganizm = new Guarana(0, pozycjaX, pozycjaY, this);
		break;
	case 't':
		nowyOrganizm = new Trawa(0, pozycjaX, pozycjaY, this);
		break;
	case 'o':
		nowyOrganizm = new Owca(0, pozycjaX, pozycjaY, this);
		break;
	case 'j':
		nowyOrganizm = new Jagoda(0, pozycjaX, pozycjaY, this);
		break;
	case 'm':
		nowyOrganizm = new Mlecz(0, pozycjaX, pozycjaY, this);
		break;
	case 'w':
		nowyOrganizm = new Wilk(0, pozycjaX, pozycjaY, this);
		break;
	case 'z':
		nowyOrganizm = new Zolw(0, pozycjaX, pozycjaY, this);
		break;
	case 'l':
		nowyOrganizm = new Lis(0, pozycjaX, pozycjaY, this);
		break;
	case 'a':
		nowyOrganizm = new Antylopa(0, pozycjaX, pozycjaY, this);
		break;
	case 'c':
		nowyOrganizm = new Czlowiek(0, pozycjaX, pozycjaY, this);
	default:
		break;
	}

	this->organizmy.push_back(nowyOrganizm);
}

void Swiat::stworzPierwszeOrganizmy() {
	int pozycjaX, pozycjaY, typ;
	this->licznikTur = 0;

	std::srand(time(NULL));

	for (int i = 0; i < organizmyNaPoczatku; i++) {
		pozycjaX = std::rand() % 18 + 1;
		pozycjaY = std::rand() % 18 + 1;
		typ = std::rand() % 9;

		switch (typ)
		{
		case 0:
			dodajOrganizm('o', pozycjaX, pozycjaY);
			break;
		case 1:
			dodajOrganizm('t', pozycjaX, pozycjaY);
			break;
		case 2:
			dodajOrganizm('g', pozycjaX, pozycjaY);
			break;
		case 3:
			dodajOrganizm('j', pozycjaX, pozycjaY);
			break;
		case 4:
			dodajOrganizm('w', pozycjaX, pozycjaY);
			break;
		case 5:
			dodajOrganizm('m', pozycjaX, pozycjaY);
			break;
		case 6:
			dodajOrganizm('z', pozycjaX, pozycjaY);
			break;
		case 7:
			dodajOrganizm('a', pozycjaX, pozycjaY);
			break;
		case 8:
			dodajOrganizm('l', pozycjaX, pozycjaY);
			break;
		default:
			break;
		}
	}

	this->licznikTur++;

	pozycjaX = std::rand() % 18 + 1;
	pozycjaY = std::rand() % 18 + 1;
	dodajOrganizm('c', pozycjaX, pozycjaY);
}

int Swiat::zwrocIndeks(int pozycjaX, int pozycjaY) {
	int busy = -1;

	for (int i = 0; i < this->organizmy.size(); i++) {
		if (this->organizmy[i] != NULL) {
			if (this->organizmy[i]->pobierzPozycjeX() == pozycjaX && this->organizmy[i]->pobierzPozycjeY() == pozycjaY) {
				busy = i;
				break;
			}
		}
	}

	return busy;
}

bool Swiat::porownajSila(Organizm * pierwszy, Organizm * drugi) {
	if (pierwszy->pobierzSile() > drugi->pobierzSile()) {
		return true;
	}

	return false;
}

bool Swiat::porownajInicjatywa(Organizm * pierwszy, Organizm * drugi) {
	if (pierwszy->pobierzInicjatywe() == drugi->pobierzInicjatywe()) {
		return porownajWiekiem(pierwszy, drugi);
	}

	if (pierwszy->pobierzInicjatywe() > drugi->pobierzInicjatywe()) {
		return true;
	}

	return false;
}

bool Swiat::porownajWiekiem(Organizm * pierwszy, Organizm * drugi) {
	if (pierwszy->pobierzWiek() < drugi->pobierzWiek()) {
		return true;
	}

	return false;
}

void Swiat::usunMartwe() {
	for (int i = 0; i < this->organizmy.size(); i++) {
		if (this->organizmy[i] == NULL) {
			this->organizmy.erase(this->organizmy.begin() + i);
			--i;
		}
	}
}
