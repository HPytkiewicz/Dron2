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
/*!
* \brief Wskaznik na lacze do gnuplota
*/
std::shared_ptr<drawNS::Draw3DAPI> lacze;
/*!
* \brief Wektor polozenia srodka bryly
*/
Wektor3D srodek;
/*!
* \brief Macierz orientacji bryly
*/
Macierz<double,3> orientacja;
/*!
* \brief Macierz zapasowa orientacji bryly
*/
Macierz<double,3> zapasowa_orientacja;
/*!
* \brief Kat rotacji wzgledem osi Z
*/
double katZ;
/*!
* \brief Kat rotacji wzgledem osi Y
*/
double katY;
/*!
* \brief Kat rotacji wzgledem osi X
*/
double katX;
/*!
* \brief Id unikalne dla obiektu
*/
uint id;
/*!
* \brief Kolor bryly
*/
string kolor;
/*!
* \brief Statyczna zmienna zawierajaca ilosc wszystkich obiektow
*/
static int wszystkie_obiekty;
/*!
* \brief Statyczna zmienna zawierajaca ilosc zniszczonych obiektow
*/
static int zniszczone_obiekty;

public:
/*!
* \brief Usuniety konstruktor bezparametryczny
*/
Bryla()=delete;
/*!
* \brief Konstruktor bryly przyjmujacy wskzanik na lacze do gnuplota, wektor srodka oraz macierz orientacji
* \param gnuplot - wskaznik na lacze do gnuplota
* \param wsp_srodek - wektor polozenia srodka bryly
* \param mac_orientacji - macierz orientacji bryly
*/
Bryla(std::shared_ptr<drawNS::Draw3DAPI> gnuplot, Wektor3D wsp_srodek, Macierz<double,3> mac_orientacji): lacze(gnuplot), 
srodek(wsp_srodek), zapasowa_orientacja(mac_orientacji), katZ(0), katY(0), katX(0), id(0) {zeruj_orientacje(); ++wszystkie_obiekty; kolor="black";}
/*!
* \brief Konstruktor bryly przyjmujacy wskzanik na lacze do gnuplota, oraz wektor srodka
* \param gnuplot - wskaznik na lacze do gnuplota
* \param wsp_srodek - wektor polozenia srodka bryly
*/
Bryla(std::shared_ptr<drawNS::Draw3DAPI> gnuplot, Wektor3D wsp_srodek): lacze(gnuplot), 
srodek(wsp_srodek), katZ(0), katY(0), katX(0), id(0) 
{orientacja[0]={1,0,0}; orientacja[1]={0,1,0}; orientacja[2]={0,0,1}; zeruj_orientacje(); ++wszystkie_obiekty; kolor="black";}
/*!
* \brief Konstruktor kopiujacy bryly
* \param nowa - bryla ktora inicjuje konstruktor
*/
Bryla(const Bryla &nowa): lacze(nowa.lacze), srodek(nowa.srodek), zapasowa_orientacja(nowa.zapasowa_orientacja), katZ(nowa.katZ),
katY(nowa.katY), katX(nowa.katX), id(nowa.id), kolor(nowa.kolor) {zeruj_orientacje(); ++wszystkie_obiekty;}
/*!
* \brief Destruktor bryly
*/
~Bryla() {--zniszczone_obiekty;}
/*!
* \brief Metoda ustawiajaca srodek bryly na podana wartosc
* \param wsp_srodek - wspolrzedne nowego srodka
*/
void ustaw_srodek(Wektor3D wsp_srodek){srodek = wsp_srodek;}
/*!
* \brief Metoda zwracajaca srodek bryly
*/
Wektor3D wez_srodek() const {return srodek;}
/*!
* \brief Metoda ustawiajaca orientacje na domyslna
*/
void zeruj_orientacje();
/*!
* \brief Metoda ustawiajaca orientacje na podana
* \param mac_orientacji - macierz orientacji przyjmowana jako nowa
*/
void ustaw_orientacje(Macierz<double,3> mac_orientacji) {zapasowa_orientacja = mac_orientacji;}
/*!
* \brief Metoda zwracajaca orientacje bryly
*/
Macierz<double,3> wez_orientacje() const{return orientacja;} 
/*!
* \brief Metoda dodajaca kat do orientacji Z
* \param stopnie - ilosc dodanych stopni
*/
void dodaj_katZ(double stopnie){this->katZ += stopnie;}
/*!
* \brief Metoda dodajaca kat do orientacji X
* \param stopnie - ilosc dodanych stopni
*/
void dodaj_katX(double stopnie){this->katX -= stopnie;}
/*!
* \brief Metoda dodajaca kat do orientacji Y
* \param stopnie - ilosc dodanych stopni
*/
void dodaj_katY(double stopnie){this->katX += stopnie;}
/*!
* \brief Metoda zmieniajaca kolor bryly
* \param nowy_kolor - kolor zmienianej bryly
*/
void ustaw_kolor(string nowy_kolor){this->kolor = nowy_kolor;}
/*!
* \brief Statyczna metoda zwracajaca ilosc wszystkich obiektow w czasie trwania programu
*/
static int wez_wszystkie_obiekty() {return wszystkie_obiekty;}
/*!
* \brief Statyczna metoda zwracajaca ilosc zniszczonych obiektow w czasie trwania programu
*/
static int wez_aktualne_obiekty() {return wszystkie_obiekty - zniszczone_obiekty;}
};

#endif