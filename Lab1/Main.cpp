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

    A.prikaziMatricu();
     
    if (A.getBrKolona() >= 3) {
        double sumaKol1 = A.sumaKolone(0); 
        double sumaKol3 = A.sumaKolone(2); 
        cout << "Suma 1. kolone: " << sumaKol1 << endl;
        cout << "Suma 3. kolone: " << sumaKol3 << endl;
        cout << "Ukupna suma (1. i 3. kolone): " << sumaKol1 + sumaKol3 << endl;
    }
    else {
        cout << "Matrica nema dovoljno kolona za trazeno sumiranje (treba bar 3)." << endl;
    }

    cout << "-------------------------" << endl;

    if (A.getBrRedova() >= 3) {
        double sumaRed2 = A.sumaReda(1); 
        double sumaRed3 = A.sumaReda(2); 
        cout << "Suma 2. reda: " << sumaRed2 << endl;
        cout << "Suma 3. reda: " << sumaRed3 << endl;
        cout << "Ukupna suma (2. i 3. reda): " << sumaRed2 + sumaRed3 << endl;
    }
    else {
        cout << "Matrica nema dovoljno redova za trazeno sumiranje (treba bar 3)." << endl;
    }

    cout << endl;
    cout << "--- Testiranje Kronekerovog proizvoda (opciono za demonstraciju) ---" << endl;
 
    Matrica B(2, 2, "MatricaB");
 
    cout << "Unesite malu 2x2 matricu B za test proizvoda:" << endl;
    B.unesiElemente();

    Matrica K = A.kroneckerProizvod(B);
    K.prikaziMatricu();

    return 0;
}