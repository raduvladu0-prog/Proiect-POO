#ifndef MIJLOCAS_H
#define MIJLOCAS_H

#include "Jucator.h"

class Mijlocas : public Jucator {
protected:
    int paseGol;
public:
    Mijlocas(const std::string& nume, int varsta, int rating);
    int getPaseGol() const;
    void adaugaPaseGol();
    std::string getPozitie() const override;
    bool verificaPasaDecisiva(int ratingAtacant) const;
    void afiseazaInfo();
};

#endif