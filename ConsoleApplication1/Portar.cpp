#include "Portar.h"
#include <iostream>
using namespace std;

Portar::Portar(const string& nume, int varsta, int rating)
    : Jucator(nume, varsta, rating), penaltyuriAparate(0) {
}

std::string Portar::getPozitie() const {
    return "Portar";
}

void Portar::incrementeazaPenaltyuriAparate() {
    penaltyuriAparate++;
}

void Portar::afiseazaInfo()  {
    Jucator::afiseazaInfo(); 
   cout << " | Pen. Aparate: " << penaltyuriAparate <<endl;
}