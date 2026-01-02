#include "Mijlocas.h"
#include <cmath> // pentru abs

Mijlocas::Mijlocas(const std::string& nume, int varsta, int rating)
    : Jucator(nume, varsta, rating), paseGol(0) {
} 
   
std::string Mijlocas::getPozitie() const {
    return "Mijlocas";
}
void Mijlocas::adaugaPaseGol() {
    paseGol++;
}
int Mijlocas::getPaseGol() const {
    return paseGol;
}
bool Mijlocas::verificaPasaDecisiva(int ratingAtacant) const {
    // Dacă rating-urile sunt apropiate (diferență <= 30), considerăm că există chimie
    return std::abs(this->rating - ratingAtacant) <=50;
}
void Mijlocas::afiseazaInfo()  {
    Jucator::afiseazaInfo();
    std::cout << " | Assist-uri: " << paseGol << std::endl;
}