#include "Fundas.h"

Fundas::Fundas(const std::string& nume, int varsta, int rating)
    : Jucator(nume, varsta, rating) {
}

std::string Fundas::getPozitie() const {
    return "Fundas";
}