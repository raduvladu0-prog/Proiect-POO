#include "Portar.h"
#include <iostream>

Portar::Portar(const std::string& nume, int varsta, int rating)
    : Jucator(nume, varsta, rating), penaltyuriAparate(0) {
}

std::string Portar::getPozitie() const {
    return "Portar";
}

void Portar::incrementeazaPenaltyuriAparate() {
    penaltyuriAparate++;
}

void Portar::afiseazaInfo()  {
    Jucator::afiseazaInfo(); // Afișează nume, poziție, rating
    std::cout << " | Pen. Aparate: " << penaltyuriAparate << std::endl;
}