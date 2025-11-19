#ifndef Portar_H    
#define Portar_H

#include "Jucator.h"

class Portar : public Jucator {
public:
    Portar(const std::string& nume, int varsta, int rating);

    std::string getPozitie() const override;//nu modific nimic legat de nume rating etc..
};

#endif // PORTAR_H