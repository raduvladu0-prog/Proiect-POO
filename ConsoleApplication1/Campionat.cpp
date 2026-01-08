#include "Campionat.h"
#include <iostream>
#include <algorithm>
using namespace std;
Campionat::Campionat() : meciuriJucate(false) {}

Campionat::~Campionat() {
    for (auto e : echipe) delete e;
    echipe.clear();
}

void Campionat::genereazaEchipe(int nrEchipe) {
    for (auto e : echipe) delete e;
    echipe.clear();

    for (int i = 0; i < nrEchipe; i++) {
        Echipa* e = new Echipa();
        e->genereazaJucatoriRandom(11);
        echipe.push_back(e);
    }
    meciuriJucate = false;
   cout << "Au fost generate " << nrEchipe << " echipe.\n";
}

void Campionat::afiseazaStatistici() const {
    for (auto e : echipe)
        e->afiseazaEchipa();
}

void Campionat::joacaToateMeciurile() {
    for (size_t i = 0; i < echipe.size(); i++) {
        for (size_t j = i + 1; j < echipe.size(); j++) {
            cout << "\n--- Meci Tur ---" << endl;
            Echipa::joacaMeci(*echipe[i], *echipe[j]);
            cout << "\n--- Meci Retur ---" << endl;
            Echipa::joacaMeci(*echipe[j], *echipe[i]);
        }
    }
    meciuriJucate = true;
}

void Campionat::afiseazaClasament() const {
    vector<Echipa*> clasament = echipe;
    sort(clasament.begin(), clasament.end(), [](Echipa* a, Echipa* b) {
        return a->getPuncte() > b->getPuncte();
        });

    cout << "\n=== CLASAMENT FINAL ===\n";
    for (size_t i = 0; i < clasament.size(); ++i) {
        cout << i + 1 << ". | " << clasament[i]->getNume() << "\t| " << clasament[i]->getPuncte() << " pct\n";
         
    }
}