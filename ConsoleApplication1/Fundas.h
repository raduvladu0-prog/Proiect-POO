#ifndef FUNDAS_H
#define FUNDAS_H

#include "Jucator.h"

class Fundas : public Jucator {
public:
    Fundas(const std::string& nume, int varsta, int rating);
    std::string getPozitie() const override;
};

#endif