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
    * \brief Id plaszczyzny
    */
    bool przenikalnosc;

    double wysokosc;
    public:
    /*!
    * \brief Usuniety konstruktor bezparametryczny
    */
    Plaszczyzna() = delete;
    /*!
    * \brief Konstruktor przyjmujacy punkty w lewym gornym i prawym dolnym rogu plaszczyzny (patrzac z gory) i wskaznik na lacze do gnuplota
    * \param lewygorny - wektor polozenia lewego gornego rogu plaszczyzny
    * \param prawydolny - wektor polozenia prawego dolnego rogu plaszczyzny
    * \param gnuplot - Wskaznik na lacze do gnuplota
    */
    Plaszczyzna(Wektor3D lewygorny, Wektor3D prawydolny, std::shared_ptr<drawNS::Draw3DAPI> gnuplot, bool nowa_przenikalnosc);
    //Bryla(gnuplot, Wektor3D(0,0,lewygorny[2]), Macierz<double,3>({1,0,0},{0,1,0},{0,0,1}))
    /*!
    * \brief Metoda zmieniajaca kolor plaszczyzny 
    * \param nowy_kolor - kolor przyjmowany przez plaszczyzne
    */
    //void zmien_kolor(char nowy_kolor);
    /*!
    * \brief Metoda rysujaca plaszczyzne
    */
    void rysuj();
    /*!
    * \brief Metoda usuwajaca narysowana plaszczyzne
    */
    void usun();

    bool czy_kolizja(std::shared_ptr<InterfejsDrona> dronpom) override;

    void stworz_przeszkode() override;
};

#endif 