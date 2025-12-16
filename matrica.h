#ifndef MATRICA_H
#define MATRICA_H

#include <iostream>

class Matrica {
private:
    double** elementi;
    int brRedova;
    int brKolona;
    char* naziv;  

 
    void alocirajMemoriju(int r, int c, const char* n);

public:

    Matrica();
    Matrica(int r, int c, const char* n = "NovaMatrica");
    Matrica(const Matrica& druga);

    
    ~Matrica();

    
    inline int getBrRedova() const { return brRedova; }
    inline int getBrKolona() const { return brKolona; }

   
    inline const char* getNaziv() const { return naziv; }

  
    double sumaReda(int r) const;
    double sumaKolone(int c) const;
    void unesiElemente();
    void prikaziMatricu() const;

  
    Matrica kroneckerProizvod(const Matrica& druga) const;
    Matrica proizvod(const Matrica& druga) const;
};

#endif