#include <iostream>
#include <string>
#include "Jucator.h"
#include "Echipa.h"
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(0))); // initializare jucatori random
    vector<Echipa> echipe;
    int optiune;
    int nrEchipe = 0;

    do {
        cout << "\n=== MENIU PRINCIPAL ===\n";
        cout << "1. Genereaza echipe\n";
        cout << "2. Afiseaza echipele si jucatorii\n";
        cout << "3. Joaca toate meciurile (tur-retur)\n";
        cout << "4. Afiseaza clasamentul final\n";
        cout << "0. Iesire\n";
        cout << "Alege o optiune: ";
        cin >> optiune;

        switch (optiune) {
        case 1: { // Genereaza echipe
            cout << "Introdu numarul de echipe (par): ";
            cin >> nrEchipe;

            if (nrEchipe % 2 != 0 || nrEchipe <= 0) {
                cout << "Numarul de echipe trebuie sa fie par si pozitiv!\n";
                break;
            }

            echipe.clear();
            for (int i = 0; i < nrEchipe; i++) {
                Echipa e;                 
                e.genereazaJucatoriRandom(11);
                echipe.push_back(e);
            }
            cout << "Au fost generate " << nrEchipe << " echipe.\n";
            break;
        }

        case 2: { // Afiseaza echipele
            if (echipe.empty()) {
                cout << "Nu exista echipe generate!\n";
                break;
            }
            for (auto& e : echipe)
                e.afiseazaEchipa();
            break;
        }

        case 3: { // Joaca toate meciurile tur-retur
            if (echipe.empty()) {
                cout << "Nu exista echipe generate!\n";
                break;
            }

            cout << "\n=== Incep meciurile (tur-retur) ===\n";
            for (int i = 0; i < nrEchipe; i++) {
                for (int j = i + 1; j < nrEchipe; j++) {
                    cout << "\nMeci: " << echipe[i].getNume()
                        << " vs " << echipe[j].getNume() << endl;
                    Echipa::joacaMeci(echipe[i], echipe[j]);

                    cout << "\nMeci retur: " << echipe[j].getNume()
                        << " vs " << echipe[i].getNume() << endl;
                    Echipa::joacaMeci(echipe[j], echipe[i]);
                }
            }
            cout << "\n=== Toate meciurile s-au terminat ===\n";
            break;
        }

        case 4: { // Clasament final
            if (echipe.empty()) {
                cout << "Nu exista echipe generate!\n";
                break;
            }

            sort(echipe.begin(), echipe.end(), [](const Echipa& a, const Echipa& b) {
                return a.getPuncte() > b.getPuncte();
                });

            cout << "\n=== CLASAMENT FINAL ===\n";
            for (size_t i = 0; i < echipe.size(); ++i) {
                cout << i + 1 << ". " << echipe[i].getNume()
                    << " - " << echipe[i].getPuncte() << " puncte\n";
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

    return 0;
}//functie pentru regenerarea ratingului jucatorilor
// funtie impart generarea echipei
//functie pentru numele jucatorilor sa nu se repete
// functie daca mai multe echipe au acelasi nr de puncte
// functie pt restrangerea main ului  (sa fac o functie din main)
//de implementat
