#ifndef Jucator_H
#define Jucator_H

#include <string>
using namespace std;

class Jucator {
private:
    string nume;
    int varsta;
    string pozitie;
    int rating; // 1 - 100

public:
    Jucator(const string& nume, int varsta, const string& pozitie, int rating);
    void afiseazaInfo() const;
    int getRating() const;
    string getNume() const;
    int getVarsta() const;
    string getPozitie() const;
};

#endif
