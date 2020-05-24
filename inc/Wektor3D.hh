#ifndef WEKTOR3D_HH
#define WEKTOR3D_HH

#include "Wektor.hh"
#include <iostream>

class Wektor3D: public Wektor<double,3>{
public:
Wektor3D(): Wektor<double,3>(){};
Wektor3D(const Wektor & wektor): Wektor<double,3>(wektor){};
Wektor3D(double x, double y, double z) {tab[0]=x; tab[1]=y; tab[2]=z;}
};
#endif