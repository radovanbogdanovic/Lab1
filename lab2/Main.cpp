#include <iostream>
#include "matrica.h"
#include "tacka.h"

using namespace std;

int main() {
    int m, n;
    cout << "Unesite dimenzije redova i kolona: ";
    cin >> m >> n;

    Matrica* A = new Matrica(m, n, "Matrica_A");

    cout << "Unesite tacke (x y z) za svaku celiju:\n";
    cin >> *A;

    cout << *A;

    int k, l;
    cout << "\nUnesite indekse kolona za sumiranje (k l): ";
    cin >> k >> l;

    if (k >= 0 && k < A->getBrKolona() && l >= 0 && l < A->getBrKolona()) {
        Tacka* sK1 = new Tacka(A->sumaKolone(k));
        Tacka* sK2 = new Tacka(A->sumaKolone(l));
        Tacka* sumaK = new Tacka(*sK1 + *sK2);
        
        cout << "Suma kolona " << k << " i " << l << " je: " << *sumaK << endl;
        
        delete sK1;
        delete sK2;
        delete sumaK;
    }
    else {
        cout << "Unesen je nepostojeci broj kolone. \n";
    }

    int p, q;
    cout << "\nUnesite indekse redova za sumiranje (p q): ";
    cin >> p >> q;

    if (p >= 0 && p < A->getBrRedova() && q >= 0 && q < A->getBrRedova()) {
        Tacka* sumaR = new Tacka(A->sumaReda(p) + A->sumaReda(q));
        cout << "Suma redova " << p << " i " << q << " je: " << *sumaR << endl;
        delete sumaR;
    }
    else {
        cout << "Unesen je nepostojeci broj reda. \n";
    }
    

    A->povecajKomponente();
    cout << " \nMatrica A kod koje je svaki element uvecan za 1 \n" << *A << endl;

    A->normalizuj(0, 10, 0, 10, 0, 10);
    cout << "\nMatrica A normalizovana \n" << *A << endl;

    Tacka* t00 = new Tacka(A->getTacka(0, 0));
    cout << "\nTacka na (0,0) je: " << *t00 << endl;
    delete t00;

    delete A;

    return 0;
}