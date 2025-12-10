#include "Jucator.h"

Jucator::Jucator(const std::string& nume, int varsta, int rating)
    : nume(nume), varsta(varsta), rating(rating), goluri(0), paseGol(0) {
}

Jucator::~Jucator() {}

void Jucator::afiseazaInfo() const {
    std::cout << "    " << nume
        << " | " << getPozitie()
        << " | Rating: " << rating
        << " | G: " << goluri
        << " | A: " << paseGol << std::endl;
}

int Jucator::getRating() const { return rating; }
std::string Jucator::getNume() const { return nume; }
int Jucator::getVarsta() const { return varsta; }
int Jucator::getGoluri() const { return goluri; }

void Jucator::marcheazaGol() { goluri++; }
void Jucator::adaugaPasaGol() { paseGol++; }