#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH

#include <iostream>
#include "Dr3D_gnuplot_api.hh"
#include "Bryla.hh"
#include "MacierzObrotu.hh"

using namespace std;
using namespace drawNS;

class Prostopadloscian : public Bryla, public MacierzObrotu
{
    protected:
    /*!
    * \brief Wektor wektorow 3d zawierajacy informacje o wierzcholkach lokalnych prostopadloscianu
    */
    vector<Wektor3D> wierzcholki_lokalnie;
    /*!
    * \brief Wektor wektorow 3d zawierajacy zapasowe wierzcholki lokalne
    */
    vector<Wektor3D> zapasowe_lokalne;
    /*!
    * \brief Wektor wektorow 3d zawierajacy informacje o wierzcholkach globalnych prostopadloscianu
    */
    vector<vector<Point3D>> wierzcholki_globalnie;
    public: 
    /*!
    * \brief Usuniety konstruktor bezparametryczny
    */
    Prostopadloscian()=delete;
    /*!
    * \brief KOnstruktor przyjmujacy za argumenty wierzcholki i srodek prostopadloscianu oraz wskaznik na lacze do gnuplota
    */
    Prostopadloscian(vector<Wektor3D> nowe_wierzcholki, Wektor3D nowy_srodek, std::shared_ptr<drawNS::Draw3DAPI> gnuplot):
    Bryla(gnuplot, nowy_srodek)
    {
        wierzcholki_lokalnie.reserve(8);
        wierzcholki_globalnie.reserve(8);
        wierzcholki_lokalnie = nowe_wierzcholki;
        zapasowe_lokalne = nowe_wierzcholki;
    }

    /*!
    * \brief KOnstruktor przyjmujacy srodek prostopadloscianu oraz wskaznik na lacze do gnuplota, uzywany do tymczasowego tworzenia srub
    */
    Prostopadloscian(Wektor3D nowy_srodek, std::shared_ptr<drawNS::Draw3DAPI> gnuplot): Bryla(gnuplot, nowy_srodek)
    {
        vector<Wektor3D> wierzcholki_sruby;
        wierzcholki_sruby.reserve(8);
        wierzcholki_globalnie.reserve(8);
        wierzcholki_sruby = 
        {
        wierzcholki_sruby[0] = {-1,1.5,-1},
        wierzcholki_sruby[1] = {1,1.5,-1},
        wierzcholki_sruby[2] = {1,-1.5,-1},
        wierzcholki_sruby[3] = {-1,-1.5,-1},
        wierzcholki_sruby[4] = {-1,1.5,1},
        wierzcholki_sruby[5] = {1,1.5,1},
        wierzcholki_sruby[6] = {1,-1.5,1},
        wierzcholki_sruby[0] = {-1,-1.5,1},
        };
    wierzcholki_lokalnie = wierzcholki_sruby;
    zapasowe_lokalne = wierzcholki_sruby;
    dodaj_katY(90);
}   
    /*!
    * \brief Metoda rysujaca prostopadlsocian
    */
    void rysuj();
    /*!
    * \brief Metoda usuwajaca narysowany prostopadlsocian
    */
    void usun();
    /*!
    * \brief Metoda ustawiajaca wierzcholki globalne bazujac na lokalnych
    */
    void ustaw_globalnie();
    /*!
    * \brief Metoda przywracjaca wierzcholka lokalne jej oryginalne wartosci
    */
    void zeruj_lokalne();

    /*!
    * \brief Metoda obracjaca bryle wedlug jej orientacji
    */
    void skrec();
    /*!
    * \brief Metoda ustawiajaca srodek prostopadloscianu na podany
    * \param nowy_srodek - nowy srodek prostopadlsocianu
    */
    void ustaw_srodek(Wektor3D nowy_srodek);
    /*!
    * \brief Metoda przesuwajaca srodek prostopadloscianu
    * \param odleglosc - odleglosc przesuwania
    * \param katpom - kat pomocniczy obracajacy prostopadlsocian wedlug osi X
    */
    void naprzod(double odleglosc, double katpom);
};

#endif