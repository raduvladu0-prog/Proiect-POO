
#include <iostream>
#include <string>
#include "Jucator.h"
#include "Echipa.h"
#include <cmath>
using namespace std;

int main()
{

	
	Echipa e("Gama");
	Echipa e2("Beta");

	e.genereazaJucatoriRandom(11);
	e.afiseazaEchipa();
	cout << "Rating mediu echipa: " << e.calculeazaRatingEchipa() << endl;
	e2.genereazaJucatoriRandom(11);
	e2.afiseazaEchipa();
	cout << "Rating mediu echipa: " << e2.calculeazaRatingEchipa() << endl;
	e.joacaMeci(e, e2);
	
	return 0;

}

 