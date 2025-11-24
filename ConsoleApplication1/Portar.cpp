#include "Portar.h"
#include <cstdlib>
Portar::Portar(const std::string& nume, int varsta, int rating)
    : Jucator(nume, varsta, rating) {
}


std::string Portar::getPozitie() const {
    return "Portar";
}
bool Portar::aparaPenalty(int fortaSut) const {
    int sansaPortar = getRating() + (rand() % 30);
    int sansaAtacant = fortaSut + (rand() % 30);

    return sansaPortar > sansaAtacant;
}