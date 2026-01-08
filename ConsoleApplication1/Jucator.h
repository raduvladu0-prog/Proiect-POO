#ifndef JUCATOR_H
#define JUCATOR_H

#include <string>
#include <iostream>
using namespace std;

class Jucator {
protected:
    string nume;
    int varsta;
    int rating;

public:
    Jucator(const string& nume, int varsta, int rating);
    virtual ~Jucator() = default;

    virtual string getPozitie() const = 0;
    virtual void afiseazaInfo()=0;

    int getRating() const;
    string getNume() const;
    int getVarsta() const;
};

#endif