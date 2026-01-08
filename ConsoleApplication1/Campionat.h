#ifndef CAMPIONAT_H
#define CAMPIONAT_H

#include <vector>
#include <string>
#include "Echipa.h"
using namespace std;
class Campionat {
private:
   vector<Echipa*> echipe;
    bool meciuriJucate;

public:
    Campionat();
    ~Campionat();

    void genereazaEchipe(int nr);
    void afiseazaStatistici() const;
    void simuleazaCampionat();
    void afiseazaClasament() const;

   
    void pornesteAplicatie();

    bool areEchipe() const { return !echipe.empty(); }
};

#endif