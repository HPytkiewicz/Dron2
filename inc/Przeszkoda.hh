#ifndef PRZESZKODA_HH
#define PRZESZKODA_HH

#include "InterfejsPrzeszkody.hh"
#include "InterfejsDrona.hh"
#include "Prostopadloscian.hh"

class InterfejsDrona;

class Przeszkoda : public Prostopadloscian, public InterfejsPrzeszkody
{
    public:
    /*!
    * \brief KOnstruktor przyjmujacy za argumenty skale, srodek, macierz orientacji oraz wskaznik na lacze do gnuplota
    * \param skala - skala drona
    * \param nowy_srodek - srodek prostopadloscianu
    * \param mac_orientacji - macierz orientacji prostopadloscianu
    * \param gnuplot - wskaznik na lacze do gnuplota
    */
    Przeszkoda(double skala, Wektor3D nowy_srodek, Macierz<double,3> mac_orientacji, std::shared_ptr<drawNS::Draw3DAPI> gnuplot): 
    Prostopadloscian(skala, nowy_srodek, mac_orientacji,gnuplot) {}
    /*!
    * \brief Metoda zwracjaca promien kolizji przeszkody
    */
    double wez_promien_przeszkody();
    /*!
    * \brief Metoda zwracajaca prawde w przypadku kolizji, falsz kiedy jej nie bylo
    * \param dronpom - wskaznik na drona
    */
    bool czy_kolizja(std::shared_ptr<InterfejsDrona> dronpom) override;
    /*!
    * \brief Metoda stwarzajaca przeszkode, dziedziczona z interfejsu przeszkody
    */
    void stworz_przeszkode() override;
};

#endif