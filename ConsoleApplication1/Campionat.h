#ifndef CAMPIONAT_H
#define CAMPIONAT_H

#include <vector>
#include "Echipa.h"
using namespace std;


class Campionat {
private:
    vector<Echipa*> echipe;
    bool meciuriJucate;

public:
    Campionat();
    ~Campionat();

    void genereazaEchipe(int nrEchipe);
    void afiseazaStatistici() const;
    void joacaToateMeciurile();
    void afiseazaClasament() const;
    bool areEchipe() const { return !echipe.empty(); }
    bool auFostJucateMeciurile() const { return meciuriJucate; }
};

#endif