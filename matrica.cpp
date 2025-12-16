#include "Matrica.h"
#include <iostream>
#include <cstring>

using namespace std;


void Matrica::alocirajMemoriju(int r, int c, const char* n) {
    brRedova = r;
    brKolona = c;

    
    if (n) {
        naziv = new char[strlen(n) + 1];
        strcpy_s(naziv, strlen(n) + 1 , n);
    }
    else {
        naziv = new char[9];
        strcpy_s(naziv, 9, "BezImena");
    }

    
    elementi = new double* [brRedova];
    for (int i = 0; i < brRedova; i++) {
        elementi[i] = new double[brKolona];
        for (int j = 0; j < brKolona; j++) {
            elementi[i][j] = 0.0;
        }
    }
}


Matrica::Matrica() {
    alocirajMemoriju(20, 20, "Default");
}

Matrica::Matrica(int r, int c, const char* n) {
    alocirajMemoriju(r, c, n);
}

Matrica::Matrica(const Matrica& druga) {
    alocirajMemoriju(druga.brRedova, druga.brKolona, druga.naziv);
    for (int i = 0; i < brRedova; i++) {
        for (int j = 0; j < brKolona; j++) {
            elementi[i][j] = druga.elementi[i][j];
        }
    }
}

Matrica::~Matrica() {
    for (int i = 0; i < brRedova; i++) {
        delete[] elementi[i];
    }
    delete[] elementi;
    delete[] naziv;
}

double Matrica::sumaReda(int r) const {
    if (r < 0 || r >= brRedova) {
        cout << "Greska: Nepostojeci red!" << endl;
        return 0.0;
    }
    double suma = 0;
    for (int j = 0; j < brKolona; j++) {
        suma += elementi[r][j];
    }
    return suma;
}


double Matrica::sumaKolone(int c) const {
    if (c < 0 || c >= brKolona) {
        cout << "Greska: Nepostojeca kolona!" << endl;
        return 0.0;
    }
    double suma = 0;
    for (int i = 0; i < brRedova; i++) {
        suma += elementi[i][c];
    }
    return suma;
}


void Matrica::unesiElemente() {
    cout << "Unos elemenata za matricu '" << naziv << "' (" << brRedova << "x" << brKolona << "):" << endl;
    for (int i = 0; i < brRedova; i++) {
        for (int j = 0; j < brKolona; j++) {
            cout << "Element [" << i + 1 << "," << j + 1 << "]: ";
            cin >> elementi[i][j];
        }
    }
}


void Matrica::prikaziMatricu() const {
    cout << "--- Matrica: " << naziv << " ---" << endl;
    for (int i = 0; i < brRedova; i++) {
        for (int j = 0; j < brKolona; j++) {
            cout << elementi[i][j] << " ";
        }
        cout << endl;
    }
}



Matrica Matrica::proizvod(const Matrica& druga) const {
    if (brKolona != druga.brRedova) {
        cout << "Greska: Dimenzije nisu saglasne za mnozenje!" << endl;
        return Matrica(1, 1, "Greska");
    }

    Matrica rez(brRedova, druga.brKolona, "Proizvod");

    for (int i = 0; i < brRedova; i++) {
        for (int j = 0; j < druga.brKolona; j++) {
            rez.elementi[i][j] = 0;
            for (int k = 0; k < brKolona; k++) {
                rez.elementi[i][j] += elementi[i][k] * druga.elementi[k][j];
            }
        }
    }
    return rez;
}


Matrica Matrica::kroneckerProizvod(const Matrica& druga) const {
    int noviRedovi = brRedova * druga.brRedova;
    int noveKolone = brKolona * druga.brKolona;

    Matrica rez(noviRedovi, noveKolone, "Kronecker");

    for (int i = 0; i < brRedova; i++) {
        for (int j = 0; j < brKolona; j++) {

            for (int k = 0; k < druga.brRedova; k++) {
                for (int l = 0; l < druga.brKolona; l++) {
                    rez.elementi[i * druga.brRedova + k][j * druga.brKolona + l] =
                        elementi[i][j] * druga.elementi[k][l];
                }
            }
        }
    }
    return rez;
}