#ifndef FUNDAS_H
#define FUNDAS_H
using namespace std;

#include "Jucator.h"

class Fundas : public Jucator {
private:
    int tackleuriReusite; 

public:
    Fundas(const string& nume, int varsta, int rating);
    string getPozitie() const override;

    void adaugaTackle(); 
    void afiseazaInfo() ;
};

#endif