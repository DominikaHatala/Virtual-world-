#pragma once
#include <iostream>

class Swiat;
class Organizm {
private:
	char typ;
	int sila;
	int inicjatywa;
	int wiek;
	int pozycjaX;
	int pozycjaY;
	Swiat * swiat;

public:
	Organizm();
	Organizm(char typ, int sila, int inicjatywa, int wiek, int pozycjaX, int pozycjaY, Swiat * swiat);
	virtual void Akcja() {};
	virtual void Kolizja(Organizm * ofiara) {};

	void ustawTyp(char typ);
	void ustawSile(int sila);
	void ustawInicjatywe(int inicjatywa);
	void ustawWiek(int wiek);
	void ustawPozycjeX(int pozycjaX);
	void ustawPozycjeY(int pozycjaY);
	void ustawSwiat(Swiat * world);

	char pobierzTyp();
	int pobierzSile();
	int pobierzInicjatywe();
	int pobierzWiek();
	int pobierzPozycjeX();
	int pobierzPozycjeY();
	Swiat * pobierzSwiat();

	virtual void Rysuj() {};

	void stworzNowyOrganizm(int pozycjaX, int pozycjaY);
};