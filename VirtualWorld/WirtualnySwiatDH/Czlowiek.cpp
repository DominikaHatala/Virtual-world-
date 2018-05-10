#include "Czlowiek.h"
#include "Swiat.h"
#include <iostream>
#include <conio.h>
#include <string>

void Czlowiek::Rysuj() {
	std::cout << "C";
}

void Czlowiek::Akcja() {
	std::cout.flush();
	std::cout << "Poruszaj sie strzalkami.\n";
	std::cout << "Aktywacja specjalnej umiejetnosci: s.\n";
	std::cout << "Zakonczenie gry : q.\n";

	if (!this->czyUmiejetnosc)
	{
		std::cout << "Specjalna umiejetnosc nie zostala aktywowana.\n";
	}
	else
	{
		std::cout << "Specjalna umiejetnosc jest aktywna przez: " << this->licznikSpecjalnejUmiejetnosci << " tur.\n";
	}

	try {
		Poruszanie();
	}
	catch(std::string wyjatek)
	{
		std::cout << "Wyjatek: " << wyjatek << std::endl;
	}
}

void Czlowiek::Poruszanie()
{
	bool specjalnaUmiejetnosc = this->czyUmiejetnosc;
	char strzalka = _getch();
	int pozX = this->pobierzPozycjeX();
	int pozY = this->pobierzPozycjeY();
	strzalka = _getch();

	if (strzalka == 0x48 || strzalka == 0x50 || strzalka == 0x4b || strzalka == 0x4d || strzalka == 'q' || strzalka == 's' || strzalka == (char)13) {
		if (strzalka != 0) {
			
			switch (strzalka)
			{
			case 0x48:
				pozX--;
				break;
			case 0x50:
				pozX++;
				break;
			case 0x4b:
				pozY--;
				break;
			case 0x4d:
				pozY++;
				break;
			case 's':
				if (!specjalnaUmiejetnosc) {
					if (this->wlaczSpecjalnaUmiejetnosc == 0) {
						this->czyUmiejetnosc = true;
					}
					else if (this->pobierzSwiat()->pobierzTure() - this->wlaczSpecjalnaUmiejetnosc >= 5)
					{
						this->czyUmiejetnosc = true;
					}
				}
				break;
			case 'q':
				exit(1);
				break;
			default:
				break;
			}
		}
	}
	else 
	{
		std::string wyjatek = "Wcisnales zly przycisk!";
		throw wyjatek;
	}

	this->SpecjalnaUmiejetnosc();

	Organizm * ofiara = NULL;

	int index = this->pobierzSwiat()->zwrocIndeks(pozX, pozY);

	if (index == -1) {
		this->ustawPozycjeX(pozX);
		this->ustawPozycjeY(pozY);
	}
	else if (this->pobierzSwiat()->organizmy[index]->pobierzTyp() != 'c') {
		ofiara = this->pobierzSwiat()->organizmy[index];
		this->Kolizja(ofiara);
	}

	

}
void Czlowiek::Kolizja(Organizm* ofiara)
{
	if (!this->czyUmiejetnosc)
	{
		Zwierze::Kolizja(ofiara);
	}
	else if (ofiara->pobierzTyp() == 'g')
	{
		ofiara->Kolizja(this);
	}
	else
	{
		std::cout << "Czlowiek jest niesmiertelny.\n";
	}
}


void Czlowiek::SpecjalnaUmiejetnosc() {
	if (this->czyUmiejetnosc) {
		if (this->licznikSpecjalnejUmiejetnosci == 0)
		{
			this->czyUmiejetnosc = false;
			this->wlaczSpecjalnaUmiejetnosc = this->pobierzSwiat()->pobierzTure();
			this->licznikSpecjalnejUmiejetnosci = 5;
		}
		else {
			this->licznikSpecjalnejUmiejetnosci--;
		}
	}

}

