#include "Atacant.h"

Atacant::Atacant(const std::string& nume, int varsta, int rating)
    : Jucator(nume, varsta, rating) {
}

std::string Atacant::getPozitie() const {
    return "Atacant";
}

void Atacant::marcheazaGol() {
    goluri++;
}