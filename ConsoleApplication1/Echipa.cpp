#include "Echipa.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <random> 

using namespace std;

Echipa::Echipa() : puncte(0) {
    static vector<string> tari = {
        "Brazilia", "Argentina", "Franta", "Germania", "Spania",
        "Italia", "Anglia", "Portugalia", "Olanda", "Belgia",
        "Croatia", "Uruguay", "Danemarca", "Elvetia", "Polonia",
        "Romania", "Turcia", "Grecia", "Austria", "Maroc"
    };

    static bool init = false;
    if (!init) {
        srand(static_cast<unsigned int>(time(nullptr)));
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
    for (auto j : jucatori) delete j;
    jucatori.clear();
}

void Echipa::adaugaJucator(Jucator* j) {
    jucatori.push_back(j);
}

void Echipa::afiseazaEchipa() const {
    cout << "> ECHIPA: " << nume << " (Rating mediu: " << calculeazaRatingEchipa() << ")" << endl;
    for (auto j : jucatori) {
        j->afiseazaInfo();
    }
}

int Echipa::calculeazaRatingEchipa() const {
    if (jucatori.empty()) return 0;
    int suma = 0;
    for (auto j : jucatori) suma += j->getRating();
    return suma / (int)jucatori.size();
}

void Echipa::genereazaJucatoriRandom(int nr_jucatori_ignorat) {
    static vector<string> prenume = { "Ion","Andrei","Mihai","George","Alex","Vlad","Cristian","Bogdan","Tudor" };
    static vector<string> nume_j = { "Popescu","Ionescu","Georgescu","Dumitrescu","Stan","Radu","Marinescu","Vladu" };

    string numeC;
    numeC = prenume[rand() % prenume.size()] + " " + nume_j[rand() % nume_j.size()];
    adaugaJucator(new Portar(numeC, 18 + rand() % 15, 65 + rand() % 30));
    for (int i = 0; i < 4; i++) {
        numeC = prenume[rand() % prenume.size()] + " " + nume_j[rand() % nume_j.size()];
        adaugaJucator(new Fundas(numeC, 18 + rand() % 15, 60 + rand() % 35));
    }
    for (int i = 0; i < 3; i++) {
        numeC = prenume[rand() % prenume.size()] + " " + nume_j[rand() % nume_j.size()];
        adaugaJucator(new Mijlocas(numeC, 18 + rand() % 15, 60 + rand() % 35));
    }
    for (int i = 0; i < 3; i++) {
        numeC = prenume[rand() % prenume.size()] + " " + nume_j[rand() % nume_j.size()];
        adaugaJucator(new Atacant(numeC, 18 + rand() % 15, 60 + rand() % 35));
    }
}

void Echipa::adaugaPuncte(int p) { puncte += p; }
string Echipa::getNume() const { return nume; }
int Echipa::getPuncte() const { return puncte; }

void Echipa::joacaMeci(Echipa& e1, Echipa& e2) {
    int gol1 = 0, gol2 = 0;
    Jucator* p1 = nullptr, * p2 = nullptr;
    for (auto j : e1.jucatori) if (j->getPozitie() == "Portar") p1 = j;
    for (auto j : e2.jucatori) if (j->getPozitie() == "Portar") p2 = j;

    cout << "[MECI] " << e1.getNume() << " vs " << e2.getNume() << endl;

    for (int faza = 1; faza <= 5; faza++) {
        // --- ATAC ECHIPA 1 ---
        vector<Jucator*> atacanti1;
        for (auto j : e1.jucatori) if (j->getPozitie() == "Atacant") atacanti1.push_back(j);
        Jucator* at1 = atacanti1[rand() % atacanti1.size()];

        cout << " F" << faza << " (" << e1.getNume() << "): ";
        bool blocat1 = false;
        for (auto def : e2.jucatori) {
            if (def->getPozitie() == "Fundas" && (rand() % 100 < 15)) {
                if (Fundas* f = dynamic_cast<Fundas*>(def)) {
                    f->adaugaTackle();
                    cout << "[" << def->getNume() << " tackle]" << endl;
                    blocat1 = true;
                    break;
                }
            }
        }
        if (!blocat1) {
            if (rand() % 100 < p2->getRating()) {
                if (Atacant* a = dynamic_cast<Atacant*>(at1)) {
                    a->marcheazaGol();
                    gol1++;
                    cout << "GOL " << a->getNume() << "!";
                }

                vector<Mijlocas*> mijlocasiEligibili;
                for (auto m : e1.jucatori) {
                    if (Mijlocas* mij = dynamic_cast<Mijlocas*>(m)) {
                        if (abs(mij->getRating() - at1->getRating()) <= 10) {
                            mijlocasiEligibili.push_back(mij);
                        }
                    }
                }
                if (!mijlocasiEligibili.empty()) {
                    Mijlocas* autorAsist = mijlocasiEligibili[rand() % mijlocasiEligibili.size()];
                    autorAsist->adaugaPaseGol();
                    cout << " (Asist: " << autorAsist->getNume() << ")";
                }
                cout << endl;
            }
            else {
                // MODIFICARE: Incrementare penalty-uri/intervenții pentru portarul echipei 2
                if (Portar* ptr = dynamic_cast<Portar*>(p2)) {
                    ptr->incrementeazaPenaltyuriAparate();
                }
                cout << "Apara portarul " << p2->getNume() << "!" << endl;
            }
        }

        // --- ATAC ECHIPA 2 ---
        vector<Jucator*> atacanti2;
        for (auto j : e2.jucatori) if (j->getPozitie() == "Atacant") atacanti2.push_back(j);
        Jucator* at2 = atacanti2[rand() % atacanti2.size()];

        cout << " F" << faza << " (" << e2.getNume() << "): ";
        bool blocat2 = false;
        for (auto def : e1.jucatori) {
            if (def->getPozitie() == "Fundas" && (rand() % 100 < 15)) {
                if (Fundas* f = dynamic_cast<Fundas*>(def)) {
                    f->adaugaTackle();
                    cout << "[" << def->getNume() << " tackle]" << endl;
                    blocat2 = true;
                    break;
                }
            }
        }
        if (!blocat2) {
            if (rand() % 100 < p1->getRating()) {
                if (Atacant* a = dynamic_cast<Atacant*>(at2)) {
                    a->marcheazaGol();
                    gol2++;
                    cout << "GOL " << a->getNume() << "!";
                }

                vector<Mijlocas*> mijlocasiEligibili;
                for (auto m : e2.jucatori) {
                    if (Mijlocas* mij = dynamic_cast<Mijlocas*>(m)) {
                        if (abs(mij->getRating() - at2->getRating()) <= 10) {
                            mijlocasiEligibili.push_back(mij);
                        }
                    }
                }
                if (!mijlocasiEligibili.empty()) {
                    Mijlocas* autorAsist = mijlocasiEligibili[rand() % mijlocasiEligibili.size()];
                    autorAsist->adaugaPaseGol();
                    cout << " (Asist: " << autorAsist->getNume() << ")";
                }
                cout << endl;
            }
            else {
                if (Portar* ptr = dynamic_cast<Portar*>(p1)) {
                    ptr->incrementeazaPenaltyuriAparate();
                }
                cout << "Apara portarul " << p1->getNume() << "!" << endl;
            }
        }
    }
    cout << "REZULTAT FINAL: " << e1.getNume() << " " << gol1 << "-" << gol2 << " " << e2.getNume() << endl;

    if (gol1 > gol2) e1.adaugaPuncte(3);
    else if (gol2 > gol1) e2.adaugaPuncte(3);
    else { e1.adaugaPuncte(1); e2.adaugaPuncte(1); }
}