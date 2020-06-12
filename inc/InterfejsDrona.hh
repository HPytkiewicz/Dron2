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
/*!
    * \brief Wirtualna metoda tworzaca drona
    */
virtual void stworzDrona() = 0;
/*!
    * \brief Wirtualna metoda animujaca obrot drona
    */
virtual void animacjaObrotu() = 0;
/*!
    * \brief Wirtualna metoda animujaca ruch drona
    */
virtual void animacjaNaprzod(vector<std::shared_ptr<InterfejsPrzeszkody>> kolekcja_przeszkod, shared_ptr<InterfejsDrona> dronpom) = 0;
/*!
    * \brief Wirtualna metoda animujaca ruch srub
    */
virtual void animacjaSruby() = 0;
/*!
* \brief Wirtualna etoda wypisujaca wspolrzedne
*/
virtual void wyswietl_wspolrzedne() = 0;

virtual uint wez_id() = 0;

virtual double wez_promien() = 0;

virtual Wektor3D wez_srodek_drona() = 0;
};

#endif