#include <iostream>
#include "Jucator.h"
using namespace std;
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
int Jucator::getGoluri()const { return goluri; };
void Jucator::marcheazaGol(){
    goluri++;
}