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
    vector<Wektor3D> wierzcholki_lokalnie;
    vector<Wektor3D> zapasowe_lokalne;
    vector<vector<Point3D>> wierzcholki_globalnie;
    public: 
    Prostopadloscian()=delete;
    Prostopadloscian(vector<Wektor3D> nowe_wierzcholki, Wektor3D nowy_srodek, std::shared_ptr<drawNS::Draw3DAPI> gnuplot):
    Bryla(gnuplot, nowy_srodek)
    {
        wierzcholki_lokalnie.reserve(8);
        wierzcholki_globalnie.reserve(8);
        wierzcholki_lokalnie = nowe_wierzcholki;
        zapasowe_lokalne = nowe_wierzcholki;
    }

    void rysuj();

    void usun();
    void ustaw_globalnie();
    void zeruj_lokalne();

    void skrec();
    void naprzod(double odleglosc, double katpom);
};

#endif