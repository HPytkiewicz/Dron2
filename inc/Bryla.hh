#ifndef BRYLA_HH
#define BRYLA_HH

#include <iostream>
#include "Wektor3D.hh"
#include "Wektor.hh"
#include "Macierz.hh"
#include "Dr3D_gnuplot_api.hh"


using namespace std;
using namespace drawNS;

class Bryla
{
protected:
std::shared_ptr<drawNS::Draw3DAPI> lacze;
Wektor3D srodek;
Macierz<double,3> orientacja;
double katZ;
double katX;
uint id;

public:
Bryla()=delete;
Bryla(std::shared_ptr<drawNS::Draw3DAPI> gnuplot, Wektor3D wsp_srodek): lacze(gnuplot), 
srodek(wsp_srodek) {katZ=0; katX=0; id=0; zeruj_orientacje();}

void ustaw_srodek(Wektor3D wsp_srodek){srodek = wsp_srodek;}
Wektor3D wez_srodek(){return srodek;}

void zeruj_orientacje();
void ustaw_orientacje(Macierz<double,3> wsp_orientacja) {orientacja = wsp_orientacja;}
Macierz<double,3> wez_orientacje(){return orientacja;}
//Wektor3D wez_srodek() {return srodek;}
void dodaj_katZ(double stopnie){this->katZ += stopnie;}
void dodaj_katX(double stopnie){this->katX -= stopnie;}
//void wez_polozenie();

};

#endif