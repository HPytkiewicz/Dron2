#ifndef PLASZCZYZNA_HH
#define PLASZCZYZNA_HH

#include <iostream>
#include <cmath>
#include "Dr3D_gnuplot_api.hh"
#include "Wektor3D.hh"

using namespace std;
using namespace drawNS;

class Plaszczyzna
{   
    /*!
    * \brief Macierz punktow 3D na ktorej rozpieta jest plaszczyzna
    */
    vector<vector<Point3D>> wierzcholki_plaszczyzny;
    /*!
    * \brief Wskaznik na lacze do gnuplota
    */
    std::shared_ptr<drawNS::Draw3DAPI> lacze;
    /*!
    * \brief Id plaszczyzny
    */
    uint id;
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
    Plaszczyzna(Wektor3D lewygorny, Wektor3D prawydolny, std::shared_ptr<drawNS::Draw3DAPI> gnuplot);
    /*!
    * \brief Metoda zmieniajaca kolor plaszczyzny na niebieski
    */
    void ustaw_niebieski();
    /*!
    * \brief Metoda rysujaca plaszczyzne
    */
    void rysuj_plaszczyzne();
    /*!
    * \brief Metoda usuwajaca narysowana plaszczyzne
    */
    void usun_plaszczyzne();
};

#endif 