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
    /*!
    * \brief Lewa sruba drona
    */
Prostopadloscian SrubaL;
/*!
    * \brief Prawa sruba drona
    */
Prostopadloscian SrubaP;

Macierz<double,3> bazowa_macierz;

public:
/*!
    * \brief Usuniety konstruktor bezparametryczny
    */
Dron()=delete;
/*!
    * \brief Konstruktor przyjmujacy wierzcholki ciala drona, jego srodek oraz wskaznik na lacze do gnuplota
    * \param nowe_wierzcholki - wierzcholki ciala drona
    * \param nowy_srodek - wspolrzedne srodka drona
    * \param gnuplot - wskaznik na lacze do gnuplota
    */
Dron(vector<Wektor3D> nowe_wierzcholki, Wektor3D nowy_srodek, std::shared_ptr<drawNS::Draw3DAPI> gnuplot, Macierz<double,3> mac_orientacji): 
Prostopadloscian(nowe_wierzcholki,nowy_srodek,mac_orientacji,gnuplot), 
SrubaL({-3,-9.5,0}, gnuplot, mac_orientacji), SrubaP({3,-9.5,0}, gnuplot, mac_orientacji)
{
(*this).zeruj_lokalne();

(*this).zeruj_orientacje();

this->srodek={0,0,0};

this->lacze=gnuplot;
}

/*!
    * \brief Metoda animujaca obrot drona
    */
void animacjaObrotu();
/*!
    * \brief Metoda animujaca ruch drona
    */
void animacjaNaprzod();
/*!
    * \brief Metoda animujaca ruch srub
    */
void animacjaSruby();

};

#endif