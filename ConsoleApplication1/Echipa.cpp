#include "Echipa.h"
#include <iostream>
#include <algorithm>
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
void Echipa::genereazaJucatoriRandom(int nr_jucatori) {
    static const vector<string> prenume = {
        "Ion", "Andrei", "Mihai", "George", "Alex", "Vlad", "Cristian", "Bogdan","Cristian","Tudor"
    };
    static const vector<string> nume = {
        "Popescu", "Ionescu", "Georgescu", "Dumitrescu", "Stan", "Radu", "Marinescu","Vladu"
    };

    // 1 portar
    {
        string fullName = prenume[rand() % prenume.size()] + " " + nume[rand() % nume.size()];
        int varsta = 18 + rand() % 15;
        int rating = 60 + rand() % 41;
        jucatori.emplace_back(fullName, varsta, "Portar", rating);
    }

    // 4 fundasi
    for (int i = 0; i < 4; ++i) {
        string fullName = prenume[rand() % prenume.size()] + " " + nume[rand() % nume.size()];
        int varsta = 18 + rand() % 15;
        int rating = 60 + rand() % 41;
        jucatori.emplace_back(fullName, varsta, "Fundas", rating);
    }

    // 3 mijlocasi
    for (int i = 0; i < 3; ++i) {
        string fullName = prenume[rand() % prenume.size()] + " " + nume[rand() % nume.size()];
        int varsta = 18 + rand() % 15;
        int rating = 60 + rand() % 41;
        jucatori.emplace_back(fullName, varsta, "Mijlocas", rating);
    }

    // 3 atacanti
    for (int i = 0; i < 3; ++i) {
        string fullName = prenume[rand() % prenume.size()] + " " + nume[rand() % nume.size()];
        int varsta = 18 + rand() % 15;
        int rating = 60 + rand() % 41;
        jucatori.emplace_back(fullName, varsta, "Atacant", rating);
    }
}

void Echipa :: adaugaPuncte(int p) { puncte += p; }
string Echipa:: getNume() const { return nume; }
int Echipa :: getPuncte() const { return puncte; }

void Echipa::joacaMeci(Echipa& e1, Echipa& e2) {
    int golEch1 = 0, golEch2 = 0;
    int ratingPortar1 = 0, ratingPortar2 = 0;
    // găsim portarii
    for (auto& j : e1.jucatori) {
        if (j.getPozitie() == "Portar") { ratingPortar1 = j.getRating(); break; }
    }
    for (auto& j : e2.jucatori) {
        if (j.getPozitie() == "Portar") { ratingPortar2 = j.getRating(); break; }
    }
    // goluri echipa 1
    for (auto& j : e1.jucatori) {
        if (j.getPozitie() =="Atacant" && j.getRating() > ratingPortar2) {
            int gol = ceil((j.getRating() - ratingPortar2) / 20.0);
            for (int k = 0; k < gol; k++) j.marcheazaGol();
            golEch1 += gol;
            if (gol==1)cout << j.getNume() << " a marcat " << gol << " gol pentru " << e1.getNume() << endl;
            else cout << j.getNume() << " a marcat " << gol << " goluri pentru " << e1.getNume() << endl;
        }
    }
    // goluri echipa 2
    for (auto& j : e2.jucatori) {
        if (j.getPozitie() == "Atacant" && j.getRating() > ratingPortar1) {
            int gol = ceil((j.getRating() - ratingPortar1) / 20.0);
            for (int k = 0; k < gol; k++) j.marcheazaGol();
            golEch2 += gol;
            if (gol==1) cout << j.getNume() << " a marcat " << gol << " gol pentru " << e2.getNume() << endl;
            else cout << j.getNume() << " a marcat " << gol << " goluri pentru " << e2.getNume() << endl;
        }
    }
    
    cout << "\nScor final: " << e1.getNume() << " " << golEch1
        << " - " << golEch2 << " " << e2.getNume() << endl;
    // puncte
    if (golEch1 > golEch2) e1.adaugaPuncte(3);
    else if (golEch2 > golEch1) e2.adaugaPuncte(3);
    else { e1.adaugaPuncte(1); e2.adaugaPuncte(1); }
}
Echipa::Echipa() {
    static vector<string> tari = {
        "Brazilia", "Argentina", "Franta", "Germania", "Spania",
        "Italia", "Anglia", "Portugalia", "Olanda", "Belgia",
        "Croatia", "Uruguay", "Danemarca", "Elvetia", "Polonia",
        "SUA", "Japonia", "Coreea de Sud", "Maroc", "Mexic",
        "Nigeria", "Suedia", "Norvegia", "Serbia", "Romania",
        "Turcia", "Grecia", "Cehia", "Austria", "Columbia"
    };

    static bool initializat = false;
    if (!initializat) {
        srand(time(0));
        random_shuffle(tari.begin(), tari.end());
        initializat = true;
    }

    if (!tari.empty()) {
        nume = tari.back();
        tari.pop_back(); // asigură că nu se repetă țările
    }
    else {
        nume = "Echipa generica"; // fallback
    }

    puncte = 0;
}

