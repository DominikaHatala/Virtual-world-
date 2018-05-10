#pragma once
#include <vector>
#include <iostream>
#include <Windows.h>

#define organizmyNaPoczatku 15
#define plansza 20

class Organizm;
class Swiat {
protected:
	int licznikTur;

public:
	std::vector<Organizm *> organizmy;
	int pobierzTure();
	void kolejnaTura();
	void rysujSwiat();
	void dodajOrganizm(char typ, int pozycjaX, int pozycjaY);
	void stworzPierwszeOrganizmy();
	int zwrocIndeks(int pozycjaX, int pozycjaY);
	bool porownajSila(Organizm * pierwszy, Organizm * drugi);
	static bool porownajInicjatywa(Organizm * pierwszy, Organizm * drugi);
	static bool porownajWiekiem(Organizm * pierwszy, Organizm * drugi);
	void usunMartwe();
};