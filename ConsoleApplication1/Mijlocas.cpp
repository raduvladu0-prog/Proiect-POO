#include "Mijlocas.h"

Mijlocas::Mijlocas(const std::string& nume, int varsta, int rating)
    : Jucator(nume, varsta, rating) {
}

std::string Mijlocas::getPozitie() const {
    return "Mijlocas";
}