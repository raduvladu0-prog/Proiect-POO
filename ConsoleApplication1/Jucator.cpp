#include "Jucator.h"
#include <iostream>

Jucator::Jucator(const std::string& nume, int varsta, int rating)
    : nume(nume), varsta(varsta), rating(rating), goluri(0), paseGol(0) { // <--- Initializare paseGol
}

Jucator::~Jucator() {}

void Jucator::afiseazaInfo() const {
    std::cout << "Jucator: " << nume
        << " | Varsta: " << varsta
        << " | Pozitie: " << getPozitie()
        << " | Rating: " << rating
        << " | Goluri: " << goluri
        << " | Pase Gol: " << paseGol << std::endl; // <--- Afisare pase
}

int Jucator::getRating() const { return rating; }
std::string Jucator::getNume() const { return nume; }
int Jucator::getVarsta() const { return varsta; }
int Jucator::getGoluri() const { return goluri; }
int Jucator::getPaseGol() const { return paseGol; } // <--- Implementare getter

void Jucator::marcheazaGol() { goluri++; }
void Jucator::adaugaPasaGol() { paseGol++; } // <--- Implementare incrementare