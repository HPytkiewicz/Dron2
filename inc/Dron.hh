#ifndef DRON_HH
#define DRON_HH

#include <iostream>
#include <cmath>
#include <unistd.h>
#include "Wektor.hh"
#include "Macierz.hh"
#include "Dr3D_gnuplot_api.hh"
#include "MacierzObrotu.hh"
#include "Wektor3D.hh"
#include "Prostopadloscian.hh"

using namespace std;
using namespace drawNS;

class Dron : public Prostopadloscian {

public:
Dron()=delete;
Dron(vector<Wektor3D> nowe_wierzcholki, Wektor3D nowy_srodek, std::shared_ptr<drawNS::Draw3DAPI> gnuplot): Prostopadloscian(nowe_wierzcholki, 
nowy_srodek, gnuplot)
{
(*this).zeruj_lokalne();

(*this).zeruj_orientacje();

this->srodek={0,0,0};

this->lacze=gnuplot;
}

void animacjaObrotu();
void animacjaNaprzod();

};

#endif