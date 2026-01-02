#include "Jucator.h"

Jucator::Jucator(const std::string& nume, int varsta, int rating)
    : nume(nume), varsta(varsta), rating(rating), goluri(0){
}

Jucator::~Jucator() {}

void Jucator::afiseazaInfo()  {
    std::cout << "    " << nume << " | " << getPozitie() << " | Rating: " << rating;
 
}

int Jucator::getRating() const { return rating; }
std::string Jucator::getNume() const { return nume; }
int Jucator::getVarsta() const { return varsta; }
int Jucator::getGoluri() const { return goluri; }

void Jucator::marcheazaGol() { goluri++; }
