#ifndef MIJLOCAS_H
#define MIJLOCAS_H

#include "Jucator.h"

class Mijlocas : public Jucator {
public:
    Mijlocas(const std::string& nume, int varsta, int rating);

    std::string getPozitie() const override;

    // Functia ceruta: returneaza true daca ratingurile sunt apropiate
    bool verificaPasaDecisiva(int ratingAtacant) const;
};

#endif