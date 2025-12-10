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

void Portar::afiseazaInfo() const {
    std::cout << "    " << getNume()
        << " | " << getPozitie()
        << " | Rating: " << getRating()
        << " | Pen. Aparate: " << penaltyuriAparate
        << " | G: " << getGoluri() << std::endl;
}