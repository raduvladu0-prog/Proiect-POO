#include "Echipa.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>

using namespace std;

Echipa::Echipa() : puncte(0) {
    static vector<string> tari = {
        "Brazilia","Argentina","Franta","Germania","Spania",
        "Italia","Anglia","Portugalia","Olanda","Belgia",
        "Croatia","Uruguay","Danemarca","Elvetia","Polonia",
        "SUA","Japonia","Coreea de Sud","Maroc","Mexic",
        "Nigeria","Suedia","Norvegia","Serbia","Romania",
        "Turcia","Grecia","Cehia","Austria","Columbia"
    };

    static bool init = false;
    if (!init) {
        srand(static_cast<unsigned int>(time(nullptr)));
        random_shuffle(tari.begin(), tari.end());
        init = true;
    }

    nume = tari.back();
    tari.pop_back();
}

Echipa::~Echipa() {
    for (auto j : jucatori)
        delete j;
}

void Echipa::adaugaJucator(Jucator* j) {
    jucatori.push_back(j);
}

void Echipa::afiseazaEchipa() const {
    cout << "Echipa: " << nume << " | Puncte: " << puncte << endl;
    for (auto j : jucatori)
        j->afiseazaInfo();
}

int Echipa::calculeazaRatingEchipa() const {
    if (jucatori.empty()) return 0;
    int suma = 0;
    for (auto j : jucatori)
        suma += j->getRating();
    return suma / jucatori.size();
}

Jucator* Echipa::genereazaJucatorRandom() {
    static vector<string> prenume = { "Ion","Andrei","Mihai","George","Alex","Vlad","Cristian","Bogdan","Tudor" };
    static vector<string> nume_j = { "Popescu","Ionescu","Georgescu","Dumitrescu","Stan","Radu","Marinescu","Vladu" };

    string fullName = prenume[rand() % prenume.size()] + " " + nume_j[rand() % nume_j.size()];
    int varsta = 18 + rand() % 15;
    int rating = 60 + rand() % 41;
    int tip = rand() % 4;

    switch (tip) {
    case 0: return new Portar(fullName, varsta, rating);
    case 1: return new Fundas(fullName, varsta, rating);
    case 2: return new Mijlocas(fullName, varsta, rating);
    default: return new Atacant(fullName, varsta, rating);  //new-returnez pointeri obiecte care vor fi stocate in vectorul de echipe
    }
    
}

void Echipa::genereazaJucatoriRandom(int nr_jucatori) {
    for (int i = 0; i < nr_jucatori; i++) {
        Jucator* j = genereazaJucatorRandom();
        adaugaJucator(j);
        cout << j->getNume() << " (" << j->getPozitie() << ", Rating: " << j->getRating() << ")" << endl;
          
    }
}

void Echipa::adaugaPuncte(int p) { puncte += p; }
string Echipa::getNume() const { return nume; }
int Echipa::getPuncte() const { return puncte; }

void Echipa::joacaMeci(Echipa& e1, Echipa& e2) {
    int golEch1 = 0, golEch2 = 0;
    int ratingPortar1 = 0, ratingPortar2 = 0;

    Jucator* portar1 = nullptr;
    Jucator* portar2 = nullptr;

    // găsim portarii
    for (auto j : e1.jucatori)
        if (j->getPozitie() == "Portar") { portar1 = j; ratingPortar1 = j->getRating(); break; }
    for (auto j : e2.jucatori)
        if (j->getPozitie() == "Portar") { portar2 = j; ratingPortar2 = j->getRating(); break; }

    // contor penalty-uri
    int penaltyEch1 = 0, penaltyEch2 = 0;

    // === Atacanții echipei 1 ===
    for (auto j : e1.jucatori) {
        if (j->getPozitie() == "Atacant") {
            if (golEch1 >= 4) break;

            // penalty: maxim 3 pe echipă
            if (portar2 && portar2->getRating() > j->getRating() && penaltyEch1 < 3) {
                cout << portar2->getNume() << " a aparat penalty-ul executat de "
                    << j->getNume() << "!\n";
                penaltyEch1++;
                continue;
            }

            int gol = ceil((j->getRating() - ratingPortar2) / 20.0);
            if (golEch1 + gol > 4) gol = 4 - golEch1;
            if (gol <= 0) continue;

            for (int k = 0; k < gol; k++) j->marcheazaGol();
            golEch1 += gol;

            cout << j->getNume() << " a marcat " << gol
                << (gol == 1 ? " gol" : " goluri")
                << " pentru " << e1.getNume() << endl;
        }
    }

    // === Atacanții echipei 2 ===
    for (auto j : e2.jucatori) {
        if (j->getPozitie() == "Atacant") {
            if (golEch2 >= 4) break;

            if (portar1 && portar1->getRating() > j->getRating() && penaltyEch2 < 3) {
                cout << portar1->getNume() << " a aparat penalty-ul executat de "
                    << j->getNume() << "!\n";
                penaltyEch2++;
                continue;
            }

            int gol = ceil((j->getRating() - ratingPortar1) / 20.0);
            if (golEch2 + gol > 4) gol = 4 - golEch2;
            if (gol <= 0) continue;

            for (int k = 0; k < gol; k++) j->marcheazaGol();
            golEch2 += gol;

            cout << j->getNume() << " a marcat " << gol
                << (gol == 1 ? " gol" : " goluri")
                << " pentru " << e2.getNume() << endl;
        }
    }

    // === Scor final ===
    cout << "\nScor final: " << e1.getNume() << " " << golEch1
        << " - " << golEch2 << " " << e2.getNume() << endl;

    if (golEch1 > golEch2) e1.adaugaPuncte(3);
    else if (golEch2 > golEch1) e2.adaugaPuncte(3);
    else { e1.adaugaPuncte(1); e2.adaugaPuncte(1); }
}
