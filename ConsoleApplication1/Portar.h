#ifndef PORTAR_H
#define PORTAR_H

#include "Jucator.h"

class Portar : public Jucator {
private:
    int penaltyuriAparate;

public:
    Portar(const std::string& nume, int varsta, int rating);

    std::string getPozitie() const override;

    void incrementeazaPenaltyuriAparate();
    void afiseazaInfo();
};

#endif