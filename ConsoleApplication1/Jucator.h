#ifndef JUCATOR_H
#define JUCATOR_H

#include <string>
#include <iostream>

class Jucator {
protected:
    std::string nume;
    int varsta;
    int rating;
    int goluri;
    int paseGol;

public:
    Jucator(const std::string& nume, int varsta, int rating);
    virtual ~Jucator();

    virtual std::string getPozitie() const = 0; 

    virtual void marcheazaGol();
    void adaugaPasaGol();

    virtual void afiseazaInfo() const;

    int getRating() const;
    std::string getNume() const;
    int getVarsta() const;
    int getGoluri() const;
};

#endif