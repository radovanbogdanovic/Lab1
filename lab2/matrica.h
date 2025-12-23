#ifndef MATRICA_H
#define MATRICA_H

#include "tacka.h"
#include <iostream>

class Matrica {
private:
    Tacka** elementi;
    int brRedova;
    int brKolona;
    char* naziv;

    void alocirajMemoriju(int r, int c, const char* n);

public:
    Matrica();
    Matrica(int r, int c, const char* n = "NovaMatrica");
    Matrica(const Matrica& druga);
    ~Matrica();

    Matrica& operator=(const Matrica& druga);

    inline int getBrRedova() const { return brRedova; }
    inline int getBrKolona() const { return brKolona; }
    inline const char* getNaziv() const { return naziv; }

    Tacka sumaReda(int r) const;
    Tacka sumaKolone(int c) const;

    void povecajKomponente();
    void normalizuj(double minX, double maxX, double minY, double maxY, double minZ, double maxZ);
    Tacka getTacka(int r, int c) const;

    Matrica kroneckerProizvod(const Matrica& druga) const;
    Matrica proizvod(const Matrica& druga) const;

    friend std::ostream& operator<<(std::ostream& os, const Matrica& m);
    friend std::istream& operator>>(std::istream& is, Matrica& m);
};

#endif