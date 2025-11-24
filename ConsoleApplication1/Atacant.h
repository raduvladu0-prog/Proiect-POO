#ifndef ATACANT_H
#define ATACANT_H

#include "Jucator.h"

class Atacant : public Jucator {
public:
    Atacant(const std::string& nume, int varsta, int rating);

    std::string getPozitie() const override;
    void marcheazaGol() override;
    int executaPenalty() const;
};


#endif