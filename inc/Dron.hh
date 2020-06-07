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
#include "Graniastoslup.hh"
#include "InterfejsDrona.hh"

using namespace std;
using namespace drawNS;

class Dron : public Prostopadloscian, public InterfejsDrona {
    /*!
    * \brief Lewa sruba drona
    */
Graniastoslup SrubaL;
/*!
    * \brief Prawa sruba drona
    */
Graniastoslup SrubaP;

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
Dron(double nowa_skala,Wektor3D nowy_srodek, std::shared_ptr<drawNS::Draw3DAPI> gnuplot, Macierz<double,3> mac_orientacji): 
Prostopadloscian(nowa_skala,nowy_srodek,mac_orientacji,gnuplot), 
SrubaL(nowa_skala,{-3,-8,0}, gnuplot, mac_orientacji),
SrubaP(nowa_skala,{3,-8,0}, gnuplot, mac_orientacji)
{
(*this).zeruj_lokalne();

(*this).zeruj_orientacje();

this->srodek=nowy_srodek;

this->lacze=gnuplot;
}

/*!
    * \brief Metoda tworzaca drona
    */
void stworzDrona() override;
/*!
    * \brief Metoda animujaca obrot drona
    */
void animacjaObrotu() override;
/*!
    * \brief Metoda animujaca ruch drona
    */
void animacjaNaprzod() override;
/*!
    * \brief Metoda animujaca ruch srub
    */
void animacjaSruby() override;
/*!
* \brief Metoda wypisujaca wspolrzedne
*/
void wyswietl_wspolrzedne() override;
/*!
* \brief Metoda zwracjaca id drona
*/
uint wez_id() override;
/*!
* \brief Metoda zwracajaca promien kolizji drona
*/
double wez_promien() override;

Wektor3D wez_srodek_drona() override;
};

#endif