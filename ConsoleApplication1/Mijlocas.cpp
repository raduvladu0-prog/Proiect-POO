#include "Mijlocas.h"
#include <cstdlib> // pentru abs()

Mijlocas::Mijlocas(const std::string& nume, int varsta, int rating)
    : Jucator(nume, varsta, rating) {
}

std::string Mijlocas::getPozitie() const {
    return "Mijlocas";
}

bool Mijlocas::verificaPasaDecisiva(int ratingAtacant) const {
    return std::abs(this->rating - ratingAtacant) <= 5;
}