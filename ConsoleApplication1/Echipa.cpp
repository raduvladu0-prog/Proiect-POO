#include "Echipa.h"
#include <iostream>
using namespace std;
// Adaugă jucător în echipă
void Echipa::adaugaJucator(const Jucator& j) {
    jucatori.push_back(j);
}
void Echipa::afiseazaEchipa() const {
    cout << "Echipa: " << nume << " | Puncte: " << puncte << endl;
    for (const auto& j : jucatori)
        j.afiseazaInfo();
    cout << endl;
}
int Echipa::calculeazaRatingEchipa() const {
    if (jucatori.empty()) return 0;
    int suma = 0;
    for (const auto& j : jucatori)
        suma += j.getRating();
    return suma / jucatori.size();
}
void Echipa::genereazaJucatoriRandom(int numarJucatori) {
    static const vector<string> prenume = {
        "Ion", "Andrei", "Mihai", "George", "Alex", "Vlad", "Cristian", "Bogdan","Cristian","Tudor"
    };
    static const vector<string> nume = {
        "Popescu", "Ionescu", "Georgescu", "Dumitrescu", "Stan", "Radu", "Marinescu","Vladu"
    };
    static const vector<string> pozitii = { "Portar", "Fundas", "Mijlocas", "Atacant" };

    for (int i = 0; i < numarJucatori; ++i) {
        string fullName = prenume[rand() % prenume.size()] + " " + nume[rand() % nume.size()];
        int varsta = 18 + rand() % 15;           // 18-32 ani
        string poz = pozitii[rand() % pozitii.size()];
        int rating = 60 + rand() % 41;           // 60-100

        jucatori.emplace_back(fullName, varsta, poz, rating);
    }
}//se poat genera jucatori cu acelasi nume si prenume ?veriface?-de implementat
// generare echipa cu cele mai multe sanse sa castige campionatul 

void Echipa :: adaugaPuncte(int p) { puncte += p; }
string Echipa:: getNume() const { return nume; }
int Echipa :: getPuncte() const { return puncte; }

