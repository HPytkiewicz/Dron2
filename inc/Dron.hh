#ifndef DRON_HH
#define DRON_HH

#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "Dr3D_gnuplot_api.hh"
#include "MacierzObrotu.hh"
#include "Wektor3D.hh"

using namespace std;
using namespace drawNS;

class Dron : public MacierzObrotu {
public:
vector<Wektor3D> wymiary;
Macierz<double,3> orientacja;

Dron()=delete;
Dron(Wektor3D W0,Wektor3D W1,Wektor3D W2,Wektor3D W3,Wektor3D W4,Wektor3D W5,Wektor3D W6,Wektor3D W7);

void rysuj();
//void obroc(double stopnie);
//void usun();

};

#endif