#include <iostream>
#include<Windows.h>
#include "Swiat.h"
using namespace std;


int main() {
	SetConsoleTitle(TEXT("DOMINIKA HATA£A 160470 WETI INF GR 2"));

	Swiat * swiat = new Swiat();
	swiat->stworzPierwszeOrganizmy();
	swiat->rysujSwiat();

	while (cin.get() == '\n') {
		system("cls");
		swiat->kolejnaTura();
	}

	return 0;
}
