#ifndef INTERFEJSDRON_HH
#define INTERFEJSDRON_HH

#include <iostream>
#include "Wektor3D.hh"
#include "rozmiar.h"
#include <unistd.h>
#include "Dr3D_gnuplot_api.hh"
#include "InterfejsPrzeszkody.hh"

using namespace std;
using namespace drawNS;

class InterfejsPrzeszkody;

class InterfejsDrona {
public:
virtual void stworzDrona() = 0;

virtual void animacjaObrotu() = 0;

virtual void animacjaNaprzod(vector<std::shared_ptr<InterfejsPrzeszkody>> kolekcja_przeszkod, shared_ptr<InterfejsDrona> dronpom) = 0;

virtual void animacjaSruby() = 0;

virtual void wyswietl_wspolrzedne() = 0;

virtual uint wez_id() = 0;

virtual double wez_promien() = 0;

virtual Wektor3D wez_srodek_drona() = 0;

virtual void zmien_kolor_drona(string nowy_kolor) = 0;
};

#endif