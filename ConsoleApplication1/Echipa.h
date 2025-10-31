#ifndef Echipa_H
#define Echipa_H
#include <string>
#include "Jucator.h"
#include <vector>
using namespace std;
class Echipa
{
	private:
	string nume;
	vector<Jucator>jucatori;
	int puncte;
public:
	Echipa(const string& n) :nume(n), puncte(0) {}
	void adaugaJucator(const Jucator& jucatori);
	void afiseazaEchipa() const;
	void adaugaPuncte(int p);
	int calculeazaRatingEchipa() const;
	void genereazaJucatoriRandom(int nrJucatori);
	string getNume() const;
	int getPuncte()const;
};
//afisare cea mai buna echipa functie?comparativ cu rating 

#endif