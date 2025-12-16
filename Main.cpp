#include <iostream>
#include "Matrica.h"

using namespace std;

int main() {
    int r, c;
    cout << "Unesite broj redova za matricu A: ";
    cin >> r;
    cout << "Unesite broj kolona za matricu A: ";
    cin >> c;

    Matrica A(r, c, "MatricaA");

    A.unesiElemente();

    cout << endl;
     
    if (A.getBrKolona() >= 3) {
        double sumaKol1 = A.sumaKolone(0); 
        double sumaKol3 = A.sumaKolone(2); 
        cout << "Suma 1. i 3. kolone: " << sumaKol1 + sumaKol3 << endl;
    }
    else {
        cout << "Matrica nema dovoljno kolona za trazeno sumiranje." << endl;
    }


    if (A.getBrRedova() >= 3) {
        double sumaRed2 = A.sumaReda(1); 
        double sumaRed3 = A.sumaReda(2); 
        cout << "Suma 2. i 3. reda: " << sumaRed2 + sumaRed3 << endl;
    }
    else {
        cout << "Matrica nema dovoljno redova za trazeno sumiranje." << endl;

    }

    A.prikaziMatricu();

    return 0;
}