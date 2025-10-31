
#include <iostream>
#include <string>
#include "Jucator.h"
#include "Echipa.h"
using namespace std;

int main()
{
	Jucator j1("Ion Popescu", 25, "Atacant", 85);
	j1.afiseazaInfo();
	Echipa e("Gama");
	e.genereazaJucatoriRandom(5);
	e.afiseazaEchipa();
	cout << "Rating mediu echipa: " << e.calculeazaRatingEchipa() << endl;
	return 0;

	

}

 