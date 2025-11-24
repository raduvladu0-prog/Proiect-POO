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
int Atacant::executaPenalty() const {
    return getRating() + (rand() % 20);
}