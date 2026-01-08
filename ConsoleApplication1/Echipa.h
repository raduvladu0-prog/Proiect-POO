#ifndef ECHIPA_H
#define ECHIPA_H

#include <string>
#include <vector>
#include "Jucator.h"
#include "Atacant.h"
#include "Fundas.h"
#include "Mijlocas.h"
#include "Portar.h"
using namespace std;
class Echipa {
private:
    string nume;
    vector<Jucator*> jucatori;
    int puncte;

public:
    Echipa();
    ~Echipa();

    void adaugaJucator(Jucator* j);
    void afiseazaEchipa() const;
    int calculeazaRatingEchipa() const;
    void genereazaJucatoriRandom(int nr_jucatori);

    void adaugaPuncte(int p);

    string getNume() const;
    int getPuncte() const;

    static void joacaMeci(Echipa& e1, Echipa& e2);
};

#endif