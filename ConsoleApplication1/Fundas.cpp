#include "Fundas.h"
#include <iostream>

Fundas::Fundas(const string& nume, int varsta, int rating)
    : Jucator(nume, varsta, rating), tackleuriReusite(0) {
}

string Fundas::getPozitie() const {
    return "Fundas";
}

void Fundas::adaugaTackle() {
    tackleuriReusite++;
}

void Fundas::afiseazaInfo()  {
    Jucator::afiseazaInfo(); 
    cout << " | Tackle-uri: " << tackleuriReusite << endl;
}