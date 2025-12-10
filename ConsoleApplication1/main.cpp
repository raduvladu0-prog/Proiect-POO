#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "Echipa.h"

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    vector<Echipa*> echipe;
    int optiune;
    int nrEchipe = 0;
    bool meciuriJucate = false;

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
            cout << "Introdu numarul de echipe (par): ";
            cin >> nrEchipe;

            if (nrEchipe <= 0 || nrEchipe % 2 != 0) {
                cout << "Numarul de echipe trebuie sa fie par si pozitiv!\n";
                break;
            }

            for (auto e : echipe) delete e;
            echipe.clear();

            for (int i = 0; i < nrEchipe; i++) {
                Echipa* e = new Echipa();
                e->genereazaJucatoriRandom(11);
                echipe.push_back(e);
            }

            meciuriJucate = false;
            cout << "Au fost generate " << nrEchipe << " echipe.\n";
            break;
        }

        case 2: {
            if (echipe.empty()) {
                cout << "Nu exista echipe generate!\n";
                break;
            }

            cout << "\n--- STATISTICI CURENTE ---\n";
            for (auto e : echipe)
                e->afiseazaEchipa();
            break;
        }

        case 3: {
            if (echipe.empty()) {
                cout << "Nu exista echipe generate!\n";
                break;
            }

            cout << "\n=== Incep meciurile (tur-retur) ===\n";

            for (int i = 0; i < nrEchipe; i++) {
                for (int j = i + 1; j < nrEchipe; j++) {

                    cout << "\n--- Meci Tur ---" << endl;
                    Echipa::joacaMeci(*echipe[i], *echipe[j]);

                    cout << "\n--- Meci Retur ---" << endl;
                    Echipa::joacaMeci(*echipe[j], *echipe[i]);
                }
            }
            meciuriJucate = true;
            cout << "\n=== Toate meciurile s-au terminat. Verifica clasamentul! ===\n";
            break;
        }

        case 4: {
            if (echipe.empty()) {
                cout << "Nu exista echipe generate!\n";
                break;
            }
            if (!meciuriJucate) {
                cout << "ATENTIE: Meciurile nu au fost jucate inca! Clasamentul este initial.\n";
            }

            // SORTARE DOAR DUPA PUNCTE
            sort(echipe.begin(), echipe.end(),
                [](Echipa* a, Echipa* b) {
                    return a->getPuncte() > b->getPuncte();
                });

            cout << "\n=== CLASAMENT FINAL (Doar Puncte) ===\n";
            cout << "Loc | Echipa       | Puncte \n";
            cout << "---------------------------\n";
            for (size_t i = 0; i < echipe.size(); ++i) {
                cout << i + 1 << ".  | "
                    << echipe[i]->getNume() << "\t| "
                    << echipe[i]->getPuncte() << "\n";
            }

            break;
        }

        case 0:
            cout << "Iesire din program.\n";
            break;

        default:
            cout << "Optiune invalida!\n";
        }

    } while (optiune != 0);

    for (auto e : echipe) delete e;

    return 0;
}