#ifndef FUNDAS_H
#define FUNDAS_H

#include "Jucator.h"

class Fundas : public Jucator {
private:
    int tackleuriReusite; // Noua variabilă

public:
    Fundas(const std::string& nume, int varsta, int rating);
    std::string getPozitie() const override;

    void adaugaTackle(); // Metodă nouă
    void afiseazaInfo() ; // Suprascriem afișarea pentru a vedea tackle-urile
};

#endif