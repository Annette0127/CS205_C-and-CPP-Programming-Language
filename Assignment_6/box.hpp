#ifndef BOX_HPP
#define BOX_HPP

#include <iostream>

class Box {
private:
    int l;
    int b;
    int h;
public:
    //Constructors:
    Box() {
        l = 0;
        b = 0;
        h = 0;
    }

    Box(int length, int breadth, int height) {
        l = length;
        b = breadth;
        h = height;
    }

    Box(const Box &B) {
        l = B.l;
        b = B.b;
        h = B.h;
    }

    //Get methods:
    int getLength() { return l; };

    int getBreadth() { return b; };

    int getHeight() { return h; };

    long long CalculateVolume() {
        long long v;
        v = ((long long) l * b * h);
        return v;
    };

    //Overloading methods:
    bool operator<(Box B) {
        if (this->l < B.l) { return true; }
        else if (this->b < B.b && this->l == B.l) { return true; }
        else if (this->h < B.h && this->b == B.b && this->l == B.l) { return true; }
        else return false;
    };

    friend std::ostream &operator<<(std::ostream &os, const Box &B) {
        return os << B.l << " " << B.b << " " << B.h << std::endl;
    };

};

#endif