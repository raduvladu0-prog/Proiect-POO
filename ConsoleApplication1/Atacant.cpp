    #include "Atacant.h"
    #include <iostream>
    Atacant::Atacant(const std::string& nume, int varsta, int rating)
        : Jucator(nume, varsta, rating), goluri(0){
    }

    std::string Atacant::getPozitie() const {
        return "Atacant";
    }

    void Atacant::marcheazaGol() {
        goluri++;
    }
    int Atacant::getGoluri()
    {
        return goluri;
    }
    void Atacant::afiseazaInfo()  {
        Jucator::afiseazaInfo();
        std::cout << " | Goluri: " << goluri << std::endl;
    }