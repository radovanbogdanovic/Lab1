#ifndef TACKA_H
#define TACKA_H
#include <iostream>

class Tacka {
private:
    double x, y, z;
public:
   
    Tacka() : x(0), y(0), z(0) {}
    Tacka(double x1, double y1, double z1) : x(x1), y(y1), z(z1) {}
    Tacka(const Tacka& t) : x(t.x), y(t.y), z(t.z) {}

    
    double getX() const { return x; }
    double getY() const { return y; }
    double getZ() const { return z; }
    void setX(double v) { x = v; }
    void setY(double v) { y = v; }
    void setZ(double v) { z = v; }

   
    Tacka operator+(const Tacka& t) const {
        return Tacka(x + t.x, y + t.y, z + t.z);
    }

   
    Tacka operator*(const Tacka& t) const {
        return Tacka(x * t.x, y * t.y, z * t.z);
    }

  
    friend std::ostream& operator<<(std::ostream& os, const Tacka& t) {
        os << "(" << t.x << "," << t.y << "," << t.z << ")";
        return os;
    }

  
    friend std::istream& operator>>(std::istream& is, Tacka& t) {
        is >> t.x >> t.y >> t.z;
        return is;
    }
};
#endif