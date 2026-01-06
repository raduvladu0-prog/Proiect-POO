#ifndef MIJLOCAS_H
#define MIJLOCAS_H
using namespace std;
#include "Jucator.h"

class Mijlocas : public Jucator {
protected:
    int paseGol;
public:
    Mijlocas(const string& nume, int varsta, int rating);
    int getPaseGol() const;
    void adaugaPaseGol();
    string getPozitie() const ;
    bool verificaPasaDecisiva(int ratingAtacant) const;
    void afiseazaInfo();
};

#endif