#include <iostream>
#include "Jucator.h"
using namespace std;
Jucator::Jucator(const string& nume, int varsta, const string& pozitie, int rating)
    : nume(nume), varsta(varsta), pozitie(pozitie), rating(rating) {
}
void Jucator::afiseazaInfo() const {
    cout << "Jucator: " << nume
        << " | Varsta: " << varsta
        << " | Pozitie: " << pozitie
        << " | Rating: " << rating << endl;
}

string Jucator ::  getNume() const { return nume; }
int Jucator::getVarsta() const { return varsta; }
string Jucator:: getPozitie() const { return pozitie; }
int Jucator::getRating() const { return rating; }