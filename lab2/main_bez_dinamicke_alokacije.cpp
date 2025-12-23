#include <iostream>
#include "matrica.h"
#include "tacka.h"

using namespace std;

int main() {
    int m, n;
    cout << "Unesite dimenzije redova i kolona: ";
    cin >> m >> n;


    Matrica A(m, n, "Matrica_A");

   
    cout << "Unesite tacke (x y z) za svaku celiju:\n";
    cin >> A;

    cout << A;

    int k, l;
    cout << "\nUnesite indekse kolona za sumiranje (k l): ";
    cin >> k >> l;

  
    if (k >= 0 && k < A.getBrKolona() && l >= 0 && l < A.getBrKolona()) {
        Tacka sumaK = A.sumaKolone(k) + A.sumaKolone(l);
        cout << "Suma kolona " << k << " i " << l << " je: " << sumaK << endl;
    }
    else {
        cout << "GRESKA: Jedna od izabranih kolona ne postoji!" << endl;
    }


    int p, q;
    cout << "\nUnesite indekse redova za sumiranje (p q): ";
    cin >> p >> q;

    if (p >= 0 && p < A.getBrRedova() && q >= 0 && q < A.getBrRedova()) {
        Tacka sumaR = A.sumaReda(p) + A.sumaReda(q);
        cout << "Suma redova " << p << " i " << q << " je: " << sumaR << endl;
    }
    else {
        cout << "GRESKA: Jedan od izabranih redova ne postoji!" << endl;
    }

    cout << "\nPovecavamo komponente za 1..." << endl;
    A.povecajKomponente();
    cout << A; 

    cout << "\nNormalizacija (primer granica 0-10 za sve ose)..." << endl;
    A.normalizuj(0, 10, 0, 10, 0, 10);

    cout << A;

    cout << "\nTacka na (0,0) je: " << A.getTacka(0, 0) << endl;

    return 0;
}