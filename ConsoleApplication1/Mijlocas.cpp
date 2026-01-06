#include "Mijlocas.h"
#include <cmath> 
using namespace std;

Mijlocas::Mijlocas(const string& nume, int varsta, int rating)
    : Jucator(nume, varsta, rating), paseGol(0) {
} 
   
string Mijlocas::getPozitie() const {
    return "Mijlocas";
}
void Mijlocas::adaugaPaseGol() {
    paseGol++;
}
int Mijlocas::getPaseGol() const {
    return paseGol;
}
bool Mijlocas::verificaPasaDecisiva(int ratingAtacant) const {
   
    return std::abs(this->rating - ratingAtacant) <=50;
}
void Mijlocas::afiseazaInfo()  {
    Jucator::afiseazaInfo();
    cout << " | Assist-uri: " << paseGol << endl;
}