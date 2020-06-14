#ifndef PLASZCZYZNA_HH
#define PLASZCZYZNA_HH

#include <iostream>
#include <cmath>
#include "Dr3D_gnuplot_api.hh"
#include "Wektor.hh"
#include "Macierz.hh"
#include "Bryla.hh"
#include "InterfejsPrzeszkody.hh"

using namespace std;
using namespace drawNS;

class Plaszczyzna : public InterfejsPrzeszkody, public Bryla
{   
    /*!
    * \brief Macierz punktow 3D na ktorej rozpieta jest plaszczyzna
    */
    vector<vector<Point3D>> wierzcholki_plaszczyzny;
    /*!
    * \brief Zmienna mowiaca o tym czy dron moze do polowy przeniknac przez plaszczyzne
    */
    bool przenikalnosc;
    /*!
    * \brief Wspolrzedna Z plaszczyzny
    */
    double wysokosc;
    public:
    /*!
    * \brief Usuniety konstruktor bezparametryczny
    */
    Plaszczyzna() = delete;
    /*!
    * \brief Konstruktor przyjmujacy punkty w lewym gornym i prawym dolnym rogu plaszczyzny (patrzac z gory), wskaznik na lacze do gnuplota i przenikalnosc
    * \param lewygorny - wektor polozenia lewego gornego rogu plaszczyzny
    * \param prawydolny - wektor polozenia prawego dolnego rogu plaszczyzny
    * \param gnuplot - Wskaznik na lacze do gnuplota
    * \param nowa_przenikalnosc - zmienna logiczna okreslajaca przenikalnosc plaszczyzny
    */
    Plaszczyzna(Wektor3D lewygorny, Wektor3D prawydolny, std::shared_ptr<drawNS::Draw3DAPI> gnuplot, bool nowa_przenikalnosc);
    /*!
    * \brief Metoda rysujaca plaszczyzne
    */
    void rysuj();
    /*!
    * \brief Metoda usuwajaca narysowana plaszczyzne
    */
    void usun();
   /*!
    * \brief Metoda zwracajaca prawde w wypadku kolizji, falsz w przypadku jej braku
    * \param dronpom - wskaznik na drona
    */
    bool czy_kolizja(std::shared_ptr<InterfejsDrona> dronpom) override;
    /*!
    * \brief Metoda tworzaca plaszczyzne, dziedziczona z interfejsu przeszkody
    */
    void stworz_przeszkode() override;
};

#endif 