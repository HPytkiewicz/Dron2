#include <iostream>
#include "Wektor3D.hh"
#include "Dr3D_gnuplot_api.hh"

using namespace std;
using namespace drawNS;

class Plaszczyzna 
{
    double wspolrzednaZ;
    std::shared_ptr<drawNS::Draw3DAPI> lacze;
    uint id;
    public:
    Plaszczyzna()=delete;
    Plaszczyzna(double wysokosc, std::shared_ptr<drawNS::Draw3DAPI> gnuplot): wspolrzednaZ(wysokosc), lacze(gnuplot){}

    void ustaw_niebieski();
    void rysuj_plaszczyzne();
};