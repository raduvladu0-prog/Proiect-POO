#include "Mijlocas.h"
#include <cmath> // pentru abs

Mijlocas::Mijlocas(const std::string& nume, int varsta, int rating)
    : Jucator(nume, varsta, rating) {
}

std::string Mijlocas::getPozitie() const {
    return "Mijlocas";
}

bool Mijlocas::verificaPasaDecisiva(int ratingAtacant) const {
    // Dacă rating-urile sunt apropiate (diferență <= 15), considerăm că există chimie
    return std::abs(this->rating - ratingAtacant) <= 15;
}