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
	Echipa();
	void adaugaJucator(const Jucator& jucatori);
	void afiseazaEchipa() const;
	void adaugaPuncte(int p);
	int calculeazaRatingEchipa() const;
	void genereazaJucatoriRandom(int nr_jucatori);
	string getNume() const;
	int getPuncte()const;
  static void joacaMeci(Echipa& e1,Echipa &e2);
};


#endif