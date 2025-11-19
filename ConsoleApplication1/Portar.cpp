#include "Portar.h"

Portar::Portar(const std::string& nume, int varsta, int rating)
    : Jucator(nume, varsta, rating) {
}

std::string Portar::getPozitie() const {
    return "Portar";
}