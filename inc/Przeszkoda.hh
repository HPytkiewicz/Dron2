#ifndef PRZESZKODA_HH
#define PRZESZKODA_HH

#include "InterfejsPrzeszkody.hh"
#include "InterfejsDrona.hh"

class Przeszkoda : public Prostopadloscian, public InterfejsPrzeszkody
{
    public:
    Przeszkoda(double skala, Wektor3D nowy_srodek, Macierz<double,3> mac_orientacji, std::shared_ptr<drawNS::Draw3DAPI> gnuplot): 
    Prostopadloscian(skala, nowy_srodek, mac_orientacji,gnuplot) {}

    double wez_promien_przeszkody();

    bool czy_kolizja(std::shared_ptr<InterfejsDrona> dronpom) override;
};

#endif