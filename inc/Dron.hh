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
uint id;
public:
Dron()=delete;
Dron(std::shared_ptr<drawNS::Draw3DAPI> gnuplot);

void rysuj();
void skrec(double stopnie);

void usun();
void ustaw_globalnie();

};

#endif