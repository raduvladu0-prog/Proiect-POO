#ifndef JUCATOR_H
#define JUCATOR_H

#include <string>

class Jucator {
protected:
    std::string nume;
    int varsta;
    int rating;
    int goluri;

public:
    Jucator(const std::string& nume, int varsta, int rating);
    virtual ~Jucator();

    virtual std::string getPozitie() const = 0;

    void afiseazaInfo() const;

    int getRating() const;
    std::string getNume() const;
    int getVarsta() const;
    int getGoluri() const;

    virtual void marcheazaGol();//implementare pentru atacant
};

#endif 