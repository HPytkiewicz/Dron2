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
vector<Wektor3D> wierzcholki_lokalnie;
vector<vector<Point3D>> wierzcholki_globalnie;
Wektor3D srodek;
Macierz<double,3> orientacja;
std::shared_ptr<drawNS::Draw3DAPI> lacze;
double katZ=0;
double katX=0;
uint id;
public:
Dron()=delete;
Dron(std::shared_ptr<drawNS::Draw3DAPI> gnuplot);

void rysuj();
void skrec();
void przechyl();
void naprzod(double odleglosc);

void usun();
void ustaw_globalnie();
void zeruj_orientacje();
void zeruj_lokalne();

Macierz<double,3> wez_orientacje() {cout << this->katZ << " " << this->katX << endl;return orientacja;}
Wektor3D wez_srodek() {return srodek;}
void dodaj_katZ(double stopnie){this->katZ += stopnie;}
void dodaj_katX(double stopnie){this->katX += stopnie;}
void wez_polozenie();

};

#endif