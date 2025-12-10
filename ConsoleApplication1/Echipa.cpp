#include "Echipa.h"
#include "Mijlocas.h" 
#include "Portar.h"   
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
    return suma / jucatori.size();
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

    // Identificam portarii
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
            if (golEch1 >= 5) break;

            // PENALTY
            if (p2Gen && p2Gen->getRating() > j->getRating() && (rand() % 10 < 3) && pen1 < 2) {
                std::cout << "   ! Penalty aparat de " << p2Gen->getNume() << std::endl;
                pen1++;
                if (Portar* p = dynamic_cast<Portar*>(p2Gen)) {
                    p->incrementeazaPenaltyuriAparate();
                }
                continue;
            }

            // GOL
            int sansaGol = (j->getRating() - rP2) + (rand() % 40);
            if (sansaGol > 20) {
                j->marcheazaGol();
                golEch1++;
                std::cout << "   -> Gol " << j->getNume() << " pt " << e1.getNume() << std::endl;

                // ASSIST
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
            if (golEch2 >= 5) break;

            if (p1Gen && p1Gen->getRating() > j->getRating() && (rand() % 10 < 3) && pen2 < 2) {
                std::cout << "   ! Penalty aparat de " << p1Gen->getNume() << std::endl;
                pen2++;
                if (Portar* p = dynamic_cast<Portar*>(p1Gen)) {
                    p->incrementeazaPenaltyuriAparate();
                }
                continue;
            }

            int sansaGol = (j->getRating() - rP1) + (rand() % 40);
            if (sansaGol > 20) {
                j->marcheazaGol();
                golEch2++;
                std::cout << "   -> Gol " << j->getNume() << " pt " << e2.getNume() << std::endl;

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

    // SCOR FINAL
    std::cout << "REZULTAT FINAL: " << e1.getNume() << " " << golEch1 << " - " << golEch2 << " " << e2.getNume() << "\n";

    // Update Puncte
    if (golEch1 > golEch2) e1.adaugaPuncte(3);
    else if (golEch2 > golEch1) e2.adaugaPuncte(3);
    else { e1.adaugaPuncte(1); e2.adaugaPuncte(1); }

    // NU se mai actualizeaza golaverajul
}