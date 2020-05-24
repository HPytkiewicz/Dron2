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
    vector<vector<Point3D>> wierzcholki_plaszczyzny;
    std::shared_ptr<drawNS::Draw3DAPI> lacze;
    uint id;
    public:
    Plaszczyzna() = delete;
    Plaszczyzna(Wektor3D lewygorny, Wektor3D prawydolny, std::shared_ptr<drawNS::Draw3DAPI> gnuplot);

    void ustaw_niebieski();
    void rysuj_plaszczyzne();
    void usun_plaszczyzne();
};

#endif 