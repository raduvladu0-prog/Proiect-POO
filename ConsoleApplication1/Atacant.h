#ifndef ATACANT_H
#define ATACANT_H

#include "Jucator.h"
using namespace std;

class Atacant : public Jucator {
private:
    int goluri;
public:
    Atacant(const string& nume, int varsta, int rating);

    string getPozitie() const override;
    int getGoluri() const;
    void marcheazaGol();
    void afiseazaInfo() override;
};

#endif