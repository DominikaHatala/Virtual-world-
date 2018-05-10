#include "Roslina.h"
#include "Mlecz.h"
#include <iostream>

void Mlecz::Rysuj() {
	std::cout << "M";
}

void Mlecz::Akcja() {
	for (int i = 0; i < 3; i++)
	{
		Roslina::Akcja();
	}
}