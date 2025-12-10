#ifndef ECHIPA_H
#define ECHIPA_H

#include <string>
#include <vector>
#include "Jucator.h"
#include "Atacant.h"
#include "Fundas.h"
#include "Mijlocas.h"
#include "Portar.h"

class Echipa {
private:
    std::string nume;
    std::vector<Jucator*> jucatori;
    int puncte;

    Jucator* genereazaJucatorRandom();

public:
    Echipa();
    ~Echipa();

    void adaugaJucator(Jucator* j);
    void afiseazaEchipa() const;
    int calculeazaRatingEchipa() const;
    void genereazaJucatoriRandom(int nr_jucatori);

    void adaugaPuncte(int p);

    std::string getNume() const;
    int getPuncte() const;

    static void joacaMeci(Echipa& e1, Echipa& e2);
};

#endif