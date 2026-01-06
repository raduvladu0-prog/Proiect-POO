#include "Jucator.h"
using namespace std;
Jucator::Jucator(const string& nume, int varsta, int rating)
    : nume(nume), varsta(varsta), rating(rating) {
}

Jucator::~Jucator() {}

void Jucator::afiseazaInfo() {
   cout << "    " << nume << " | " << getPozitie() << " | Rating: " << rating;
}

int Jucator::getRating() const { return rating; }
string Jucator::getNume() const { return nume; }
int Jucator::getVarsta() const { return varsta; }