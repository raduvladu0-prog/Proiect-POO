#include "Fundas.h"
#include <iostream>

Fundas::Fundas(const std::string& nume, int varsta, int rating)
    : Jucator(nume, varsta, rating), tackleuriReusite(0) {
}

std::string Fundas::getPozitie() const {
    return "Fundas";
}

void Fundas::adaugaTackle() {
    tackleuriReusite++;
}

void Fundas::afiseazaInfo()  {
    Jucator::afiseazaInfo(); 
    std::cout << " | Tackle-uri: " << tackleuriReusite << std::endl;
}