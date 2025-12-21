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

    // Identificăm portarii
    Jucator* p1 = nullptr, * p2 = nullptr;
    for (auto j : e1.jucatori) if (j->getPozitie() == "Portar") p1 = j;
    for (auto j : e2.jucatori) if (j->getPozitie() == "Portar") p2 = j;

    // Simulăm 5 faze de atac per meci (pentru a asigura volum de goluri)
    for (int faza = 1; faza <= 5; faza++) {

        // --- ECHIPA 1 ATACĂ ---
        // Alegem un atacant aleatoriu care participă la fază
        std::vector<Jucator*> atacanțiE1;
        for (auto j : e1.jucatori) if (j->getPozitie() == "Atacant") atacanțiE1.push_back(j);

        if (!atacanțiE1.empty()) {
            Jucator* atacantCurent = atacanțiE1[rand() % atacanțiE1.size()];
            int rAtac = atacantCurent->getRating() + (rand() % 21 - 10);

            // Verificăm dacă fundașii E2 opresc faza (TACKLE)
            bool fazaOprita = false;
            for (auto def : e2.jucatori) {
                if (def->getPozitie() == "Fundas" && (rand() % 100 < 30)) { // 30% șansă de tackle per fundaș
                    if (Fundas* fPtr = dynamic_cast<Fundas*>(def)) {
                        fPtr->adaugaTackle();
                        std::cout << "    [!] Tackle reusit: " << def->getNume() << " il deposedeaza pe " << atacantCurent->getNume() << "\n";
                        fazaOprita = true;
                        break;
                    }
                }
            }

            if (!fazaOprita) {
                // Dacă trece de fundași, portarul are o ultimă șansă (PARADĂ)
                int rPortar2 = (p2 ? p2->getRating() : 50) + (rand() % 21 - 10);

                if (rPortar2 > rAtac + 10 && (rand() % 100 < 40)) {
                    std::cout << "    [!] Parada uimitoare: " << (p2 ? p2->getNume() : "Portarul") << " apara!\n";
                }
                else {
                    // GOL!
                    atacantCurent->marcheazaGol();
                    golEch1++;
                    std::cout << "    [GOL] " << atacantCurent->getNume() << " inscrie pentru " << e1.getNume() << "!\n";

                    // Căutăm un mijlocaș pentru assist
                    for (auto m : e1.jucatori) {
                        if (Mijlocas* mij = dynamic_cast<Mijlocas*>(m)) {
                            if (mij->verificaPasaDecisiva(atacantCurent->getRating())) {
                                mij->adaugaPasaGol();
                                break;
                            }
                        }
                    }
                }
            }
        }

        // --- ECHIPA 2 ATACĂ ---
        std::vector<Jucator*> atacanțiE2;
        for (auto j : e2.jucatori) if (j->getPozitie() == "Atacant") atacanțiE2.push_back(j);

        if (!atacanțiE2.empty()) {
            Jucator* atacantCurent = atacanțiE2[rand() % atacanțiE2.size()];
            int rAtac = atacantCurent->getRating() + (rand() % 21 - 10);

            bool fazaOprita = false;
            for (auto def : e1.jucatori) {
                if (def->getPozitie() == "Fundas" && (rand() % 100 < 30)) {
                    if (Fundas* fPtr = dynamic_cast<Fundas*>(def)) {
                        fPtr->adaugaTackle();
                        std::cout << "    [!] Tackle reusit: " << def->getNume() << " il deposedeaza pe " << atacantCurent->getNume() << "\n";
                        fazaOprita = true;
                        break;
                    }
                }
            }

            if (!fazaOprita) {
                int rPortar1 = (p1 ? p1->getRating() : 50) + (rand() % 21 - 10);
                if (rPortar1 > rAtac + 10 && (rand() % 100 < 40)) {
                    std::cout << "    [!] Parada uimitoare: " << (p1 ? p1->getNume() : "Portarul") << " apara!\n";
                }
                else {
                    atacantCurent->marcheazaGol();
                    golEch2++;
                    std::cout << "    [GOL] " << atacantCurent->getNume() << " inscrie pentru " << e2.getNume() << "!\n";

                    for (auto m : e2.jucatori) {
                        if (Mijlocas* mij = dynamic_cast<Mijlocas*>(m)) {
                            if (mij->verificaPasaDecisiva(atacantCurent->getRating())) {
                                mij->adaugaPasaGol();
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    std::cout << "\n>>> REZULTAT FINAL: " << e1.getNume() << " " << golEch1 << " - " << golEch2 << " " << e2.getNume() << " <<<\n";

    if (golEch1 > golEch2) e1.adaugaPuncte(3);
    else if (golEch2 > golEch1) e2.adaugaPuncte(3);
    else { e1.adaugaPuncte(1); e2.adaugaPuncte(1); }
}