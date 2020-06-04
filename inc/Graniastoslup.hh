#ifndef GRANIASTOSLUP_HH
#define GRANIASTOSLUP_HH

#include <iostream>
#include "Dr3D_gnuplot_api.hh"
#include "Bryla.hh"
#include "MacierzObrotu.hh"

using namespace std;
using namespace drawNS;

class Graniastoslup : public Bryla, public MacierzObrotu
{
    protected:
    /*!
    * \brief Wektor wektorow 3d zawierajacy informacje o wierzcholkach lokalnych graniastoslupu
    */
    vector<Wektor3D> wierzcholki_lokalnie;
    /*!
    * \brief Wektor wektorow 3d zawierajacy zapasowe wierzcholki lokalne
    */
    vector<Wektor3D> zapasowe_lokalne;
    /*!
    * \brief Wektor wektorow 3d zawierajacy informacje o wierzcholkach globalnych graniastoslupu
    */
    vector<vector<Point3D>> wierzcholki_globalnie;
    public: 
    /*!
    * \brief Usuniety konstruktor bezparametryczny
    */
    Graniastoslup()=delete;
    /*!
    * \brief KOnstruktor przyjmujacy za argumenty wierzcholki i srodek graniastoslupu oraz wskaznik na lacze do gnuplota
    */
    Graniastoslup(vector<Wektor3D> nowe_wierzcholki, Wektor3D nowy_srodek, Macierz<double,3> mac_orientacji, std::shared_ptr<drawNS::Draw3DAPI> gnuplot):
    Bryla(gnuplot, nowy_srodek, mac_orientacji)
    {
        wierzcholki_lokalnie.reserve(12);
        wierzcholki_globalnie.reserve(12);
        wierzcholki_lokalnie = nowe_wierzcholki;
        zapasowe_lokalne = nowe_wierzcholki;
    }

    /*!
    * \brief KOnstruktor przyjmujacy srodek graniastoslupu oraz wskaznik na lacze do gnuplota, uzywany do tymczasowego tworzenia srub
    */
    Graniastoslup(double skala,Wektor3D nowy_srodek, std::shared_ptr<drawNS::Draw3DAPI> gnuplot, Macierz<double,3> mac_orientacji): 
    Bryla(gnuplot, nowy_srodek, mac_orientacji)
    {
        vector<Wektor3D> wierzcholki_sruby;
        wierzcholki_sruby.reserve(12);
        wierzcholki_globalnie.reserve(12);
        wierzcholki_sruby = 
        {
        wierzcholki_sruby[0] = {0.8,1.6,-2},
        wierzcholki_sruby[1] = {1.6,0,-1.6},
        wierzcholki_sruby[2] = {0.8,-1.6,-1.6},
        wierzcholki_sruby[3] = {-0.8,-1.6,-1.6},
        wierzcholki_sruby[4] = {-1.6,0,-1.6},
        wierzcholki_sruby[5] = {-0.8,1.6,-1.6},
        wierzcholki_sruby[6] = {0.8,1.6,1.6},
        wierzcholki_sruby[7] = {1.6,0,1.6},
        wierzcholki_sruby[8] = {0.8,-1.6,1.6},
        wierzcholki_sruby[9] = {-0.8,-1.6,1.6},
        wierzcholki_sruby[10] = {-1.6,0,1.6},
        wierzcholki_sruby[11] = {-0.8,1.6,1.6},
        };
        for(int i=0;i<12;i++)
            wierzcholki_sruby[i] = wierzcholki_sruby[i]*skala;
    wierzcholki_lokalnie = wierzcholki_sruby;
    zapasowe_lokalne = wierzcholki_sruby;
    dodaj_katY(90);
    Macierz<double,3> macierzpom;
    macierzpom[0]= {0,-1,0};
    macierzpom[1]= {1,0,0};
    macierzpom[2]= {0,0,1};
    ustaw_orientacje(macierzpom);

    }   
    /*!
    * \brief Metoda rysujaca graniastoslup
    */
    void rysuj();
    /*!
    * \brief Metoda usuwajaca narysowany graniastoslup
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
    * \brief Metoda ustawiajaca srodek graniastoslupu na podany
    * \param nowy_srodek - nowy srodek graniastoslupu
    */
    void ustaw_srodek(Wektor3D nowy_srodek);
    /*!
    * \brief Metoda przesuwajaca srodek graniastoslupu
    * \param odleglosc - odleglosc przesuwania
    * \param katpom - kat pomocniczy obracajacy graniastoslup wedlug osi X
    */
    void naprzod(double odleglosc, double katpom);
};

#endif