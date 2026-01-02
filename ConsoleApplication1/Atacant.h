#ifndef ATACANT_H
#define ATACANT_H

#include "Jucator.h"

class Atacant : public Jucator {
private:
    int goluri;
public:
    Atacant(const std::string& nume, int varsta, int rating);

    std::string getPozitie() const override;
    int getGoluri() ;
    void marcheazaGol();
    void afiseazaInfo(); 
};

#endif