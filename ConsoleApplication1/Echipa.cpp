#include "Echipa.h"
#include "Mijlocas.h" 
#include "Portar.h"   
#include "Fundas.h"
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

    if (!tari.empty()) {
        nume = tari.back();
        tari.pop_back();
    }
    else {
        nume = "Echipa Generic";
    }
}

Echipa::~Echipa() {
    for (auto j : jucatori)
        delete j;
}

void Echipa::adaugaJucator(Jucator* j) {
    jucatori.push_back(j);
}

void Echipa::afiseazaEchipa() const {
    cout << "----------------------------------------------------" << endl;
    cout << "ECHIPA: " << nume
        << " | Puncte: " << puncte << endl;
    cout << "----------------------------------------------------" << endl;
    for (auto j : jucatori)
        j->afiseazaInfo();
    cout << endl;
}

int Echipa::calculeazaRatingEchipa() const {
    if (jucatori.empty()) return 0;
    int suma = 0;
    for (auto j : jucatori)
        suma += j->getRating();
    return suma / (int)jucatori.size();
}

Jucator* Echipa::genereazaJucatorRandom() {
    static vector<string> prenume = { "Ion","Andrei","Mihai","George","Alex","Vlad","Cristian","Bogdan","Tudor" };
    static vector<string> nume_j = { "Popescu","Ionescu","Georgescu","Dumitrescu","Stan","Radu","Marinescu","Vladu" };

    string fullName = prenume[rand() % prenume.size()] + " " + nume_j[rand() % nume_j.size()];
    int varsta = 18 + rand() % 20;
    int rating = 60 + rand() % 41;
    int tip = rand() % 4;

    switch (tip) {
    case 0: return new Portar(fullName, varsta, rating);
    case 1: return new Fundas(fullName, varsta, rating);
    case 2: return new Mijlocas(fullName, varsta, rating);
    default: return new Atacant(fullName, varsta, rating);
    }
}

void Echipa::genereazaJucatoriRandom(int nr_jucatori) {
    for (int i = 0; i < nr_jucatori; i++) {
        Jucator* j = genereazaJucatorRandom();
        adaugaJucator(j);
    }
}

void Echipa::adaugaPuncte(int p) { puncte += p; }

string Echipa::getNume() const { return nume; }
int Echipa::getPuncte() const { return puncte; }

void Echipa::joacaMeci(Echipa& e1, Echipa& e2) {
    int golEch1 = 0, golEch2 = 0;

    Jucator* p1Gen = nullptr;
    Jucator* p2Gen = nullptr;

    for (auto j : e1.jucatori) if (j->getPozitie() == "Portar") p1Gen = j;
    for (auto j : e2.jucatori) if (j->getPozitie() == "Portar") p2Gen = j;

    int rP1 = p1Gen ? p1Gen->getRating() : 50;
    int rP2 = p2Gen ? p2Gen->getRating() : 50;

    int pen1 = 0, pen2 = 0;

    // === ECHIPA 1 ATACĂ ===
    for (auto j : e1.jucatori) {
        if (j->getPozitie() == "Atacant") {
            if (golEch1 >= 4) break; // Limită mai mică de goluri per jucător

            // TACKLE - Probabilitate crescută la 50%
            bool opritDeFundas = false;
            for (auto f : e2.jucatori) {
                if (f->getPozitie() == "Fundas") {
                    if (rand() % 100 < 50) {
                        if (Fundas* fundasPtr = dynamic_cast<Fundas*>(f)) {
                            fundasPtr->adaugaTackle();
                            opritDeFundas = true;
                            break;
                        }
                    }
                }
            }
            if (opritDeFundas) continue;

            // PENALTY - Șansă mai mare pentru portar (4/10)
            if (p2Gen && (rand() % 10 < 4) && pen1 < 2) {
                if (Portar* p = dynamic_cast<Portar*>(p2Gen)) {
                    p->incrementeazaPenaltyuriAparate();
                }
                continue;
            }

            // GOL - Prag ridicat la 65
            int sansaGol = (j->getRating() - rP2) + (rand() % 30);
            if (sansaGol > 65) {
                j->marcheazaGol();
                golEch1++;
                std::cout << "   -> Gol " << j->getNume() << " (" << e1.getNume() << ")" << std::endl;

                for (auto m : e1.jucatori) {
                    if (Mijlocas* mij = dynamic_cast<Mijlocas*>(m)) {
                        if (mij->verificaPasaDecisiva(j->getRating())) {
                            mij->adaugaPasaGol();
                            break;
                        }
                    }
                }
            }
        }
    }

    // === ECHIPA 2 ATACĂ ===
    for (auto j : e2.jucatori) {
        if (j->getPozitie() == "Atacant") {
            if (golEch2 >= 4) break;

            // TACKLE
            bool opritDeFundas = false;
            for (auto f : e1.jucatori) {
                if (f->getPozitie() == "Fundas") {
                    if (rand() % 100 < 50) {
                        if (Fundas* fundasPtr = dynamic_cast<Fundas*>(f)) {
                            fundasPtr->adaugaTackle();
                            opritDeFundas = true;
                            break;
                        }
                    }
                }
            }
            if (opritDeFundas) continue;

            // PENALTY
            if (p1Gen && (rand() % 10 < 4) && pen2 < 2) {
                if (Portar* p = dynamic_cast<Portar*>(p1Gen)) {
                    p->incrementeazaPenaltyuriAparate();
                }
                continue;
            }

            // GOL - Prag ridicat la 60
            int sansaGol = (j->getRating() - rP1) + (rand() % 25);
            if (sansaGol > 60) {
                j->marcheazaGol();
                golEch2++;
                std::cout << "   -> Gol " << j->getNume() << " (" << e2.getNume() << ")" << std::endl;

                for (auto m : e2.jucatori) {
                    if (Mijlocas* mij = dynamic_cast<Mijlocas*>(m)) {
                        if (mij->verificaPasaDecisiva(j->getRating())) {
                            mij->adaugaPasaGol();
                            break;
                        }
                    }
                }
            }
        }
    }

    std::cout << "REZULTAT FINAL: " << e1.getNume() << " " << golEch1 << " - " << golEch2 << " " << e2.getNume() << "\n";

    if (golEch1 > golEch2) e1.adaugaPuncte(3);
    else if (golEch2 > golEch1) e2.adaugaPuncte(3);
    else { e1.adaugaPuncte(1); e2.adaugaPuncte(1); }
}