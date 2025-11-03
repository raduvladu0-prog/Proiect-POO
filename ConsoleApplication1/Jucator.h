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
    int goluri=0;

public:
   Jucator(const string& nume, int varsta, const string& pozitie, int rating)
        : nume(nume), varsta(varsta), pozitie(pozitie), rating(rating) {
    }
    void afiseazaInfo() const;
    int getRating() const;
    string getNume() const;
    int getVarsta() const;
    string getPozitie() const;
    int getGoluri()const;
    void marcheazaGol();
     
};//inca un atribut pentru goluri marcate -de implementat-
// cel mai bun jucator al campionatului (gol averaj -de implementat )

#endif
