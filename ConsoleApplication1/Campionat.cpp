#include "Campionat.h"
#include <iostream>
#include <algorithm>
using namespace std;

Campionat::Campionat() : echipe(), meciuriJucate(false) {}

Campionat::~Campionat() {
    for (auto e : echipe) delete e;
    echipe.clear();
}

void Campionat::genereazaEchipe(int nr) {
    if (nr <= 0 || nr % 2 != 0) {
        cout << "Numarul de echipe trebuie sa fie par si pozitiv!\n";
        return;
    }

    for (auto e : echipe) delete e;
    echipe.clear();

    for (int i = 0; i < nr; i++) {
        Echipa* e = new Echipa();
        e->genereazaJucatoriRandom(11);
        echipe.push_back(e);
    }
    meciuriJucate = false;
    cout << "Au fost generate " << nr << " echipe.\n";
}

void Campionat::afiseazaStatistici() const {
    cout << "\n--- STATISTICI CURENTE ---\n";
    for (auto e : echipe) e->afiseazaEchipa();
}

void Campionat::simuleazaCampionat() {
    cout << "\n=== Incep meciurile (tur-retur) ===\n";
    int n = (int)echipe.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << "\n--- Meci Tur ---" << endl;
            Echipa::joacaMeci(*echipe[i], *echipe[j]);

            cout << "\n--- Meci Retur ---" << endl;
            Echipa::joacaMeci(*echipe[j], *echipe[i]);
        }
    }
    meciuriJucate = true;
    cout << "\n=== Toate meciurile s-au terminat! ===\n";
}

void Campionat::afiseazaClasament() const {
    if (!meciuriJucate) {
        cout << "ATENTIE: Meciurile nu au fost jucate inca!\n";
    }

    vector<Echipa*> copieClasament = echipe;
    sort(copieClasament.begin(), copieClasament.end(), [](Echipa* a, Echipa* b) {
        return a->getPuncte() > b->getPuncte();
        });

    cout << "\n=== CLASAMENT FINAL ===\n";
    cout << "Loc | Echipa       | Puncte \n";
    cout << "---------------------------\n";
    for (int i = 0; i < (int)copieClasament.size(); ++i) {
        cout << i + 1 << ".  | " << copieClasament[i]->getNume() << "\t| " << copieClasament[i]->getPuncte() << "\n";
    }
}

void Campionat::pornesteAplicatie() {
    int optiune;
    do {
        cout << "\n=== MENIU CAMPIONAT ===\n";
        cout << "1. Genereaza echipe\n";
        cout << "2. Afiseaza echipele si jucatorii (Statistici)\n";
        cout << "3. Joaca toate meciurile (tur-retur)\n";
        cout << "4. Afiseaza clasamentul final\n";
        cout << "0. Iesire\n";
        cout << "Alege o optiune: ";
        cin >> optiune;

        switch (optiune) {
        case 1: {
            int nr;
            cout << "Introdu numarul de echipe (par): ";
            cin >> nr;
            genereazaEchipe(nr);
            break;
        }
        case 2:
            if (areEchipe()) afiseazaStatistici();
            else cout << "Nu exista echipe generate!\n";
            break;
        case 3:
            if (areEchipe()) simuleazaCampionat();
            else cout << "Nu exista echipe generate!\n";
            break;
        case 4:
            if (areEchipe()) afiseazaClasament();
            else cout << "Nu exista echipe generate!\n";
            break;
        case 0:
            cout << "Iesire din program.\n";
            break;
        default:
            cout << "Optiune invalida!\n";
        }
    } while (optiune != 0);
}