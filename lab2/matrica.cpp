#include "matrica.h"
#include <iostream>
#include <cstring>

using namespace std;

void Matrica::alocirajMemoriju(int r, int c, const char* n) {
    brRedova = r;
    brKolona = c;
    if (n) {
        naziv = new char[strlen(n) + 1];
        strcpy_s(naziv, strlen(n) + 1, n);
    }
    else {
        naziv = new char[9];
        strcpy_s(naziv, 9, "BezImena");
    }
    elementi = new Tacka * [brRedova];
    for (int i = 0; i < brRedova; i++) {
        elementi[i] = new Tacka[brKolona];
    }
}

Matrica::Matrica() { alocirajMemoriju(5, 5, "Default"); }

Matrica::Matrica(int r, int c, const char* n) { alocirajMemoriju(r, c, n); }

Matrica::Matrica(const Matrica& druga) {
    alocirajMemoriju(druga.brRedova, druga.brKolona, druga.naziv);
    for (int i = 0; i < brRedova; i++)
        for (int j = 0; j < brKolona; j++)
            elementi[i][j] = druga.elementi[i][j];
}

Matrica::~Matrica() {
    for (int i = 0; i < brRedova; i++) delete[] elementi[i];
    delete[] elementi;
    delete[] naziv;
}

Matrica& Matrica::operator=(const Matrica& druga) {
    if (this != &druga) {
        for (int i = 0; i < brRedova; i++) delete[] elementi[i];
        delete[] elementi;
        delete[] naziv;
        alocirajMemoriju(druga.brRedova, druga.brKolona, druga.naziv);
        for (int i = 0; i < brRedova; i++)
            for (int j = 0; j < brKolona; j++)
                elementi[i][j] = druga.elementi[i][j];
    }
    return *this;
}

Tacka Matrica::sumaReda(int r) const {
    Tacka suma(0, 0, 0);
    if (r >= 0 && r < brRedova) {
        for (int j = 0; j < brKolona; j++) suma = suma + elementi[r][j];
    }
    return suma;
}

Tacka Matrica::sumaKolone(int c) const {
    Tacka suma(0, 0, 0);
    if (c >= 0 && c < brKolona) {
        for (int i = 0; i < brRedova; i++) {
            suma = suma + elementi[i][c];
        }
    }
    return suma;
}

void Matrica::povecajKomponente() {
    Tacka jedinica(1, 1, 1);
    for (int i = 0; i < brRedova; i++)
        for (int j = 0; j < brKolona; j++)
            elementi[i][j] = elementi[i][j] + jedinica;
}

void Matrica::normalizuj(double minX, double maxX, double minY, double maxY, double minZ, double maxZ) {
    for (int i = 0; i < brRedova; i++) {
        for (int j = 0; j < brKolona; j++) {
            if (elementi[i][j].getX() < minX) elementi[i][j].setX(minX);
            if (elementi[i][j].getX() > maxX) elementi[i][j].setX(maxX);
            if (elementi[i][j].getY() < minY) elementi[i][j].setY(minY);
            if (elementi[i][j].getY() > maxY) elementi[i][j].setY(maxY);
            if (elementi[i][j].getZ() < minZ) elementi[i][j].setZ(minZ);
            if (elementi[i][j].getZ() > maxZ) elementi[i][j].setZ(maxZ);
        }
    }
}

Tacka Matrica::getTacka(int r, int c) const {
    if (r >= 0 && r < brRedova && c >= 0 && c < brKolona) return elementi[r][c];
    return Tacka(0, 0, 0);
}

Matrica Matrica::proizvod(const Matrica& druga) const {
    if (brKolona != druga.brRedova) return Matrica(1, 1, "Greska");
    Matrica rez(brRedova, druga.brKolona, "Proizvod");
    for (int i = 0; i < brRedova; i++) {
        for (int j = 0; j < druga.brKolona; j++) {
            Tacka s(0, 0, 0);
            for (int k = 0; k < brKolona; k++) s = s + (elementi[i][k] * druga.elementi[k][j]);
            rez.elementi[i][j] = s;
        }
    }
    return rez;
}

Matrica Matrica::kroneckerProizvod(const Matrica& druga) const {
    Matrica rez(brRedova * druga.brRedova, brKolona * druga.brKolona, "Kronecker");
    for (int i = 0; i < brRedova; i++) {
        for (int j = 0; j < brKolona; j++) {
            for (int k = 0; k < druga.brRedova; k++) {
                for (int l = 0; l < druga.brKolona; l++) {
                    rez.elementi[i * druga.brRedova + k][j * druga.brKolona + l] = elementi[i][j] * druga.elementi[k][l];
                }
            }
        }
    }
    return rez;
}

ostream& operator<<(ostream& os, const Matrica& m) {
    os << "Matrica [" << m.naziv << "] (" << m.brRedova << "x" << m.brKolona << "):\n";
    for (int i = 0; i < m.brRedova; i++) {
        for (int j = 0; j < m.brKolona; j++) {
            os << "(" << m.elementi[i][j].getX() << "," << m.elementi[i][j].getY() << "," << m.elementi[i][j].getZ() << ") ";
        }
        os << endl;
    }
    return os;
}

istream& operator>>(istream& is, Matrica& m) {
    for (int i = 0; i < m.brRedova; i++) {
        for (int j = 0; j < m.brKolona; j++) {
            double tx, ty, tz;
            is >> tx >> ty >> tz;
            m.elementi[i][j] = Tacka(tx, ty, tz);
        }
    }
    return is;
}