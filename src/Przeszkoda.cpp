#include "Przeszkoda.hh"

bool Przeszkoda::czy_kolizja(std::shared_ptr<InterfejsDrona> dronpom)
{
    double odleglosc;
    odleglosc = (this->srodek + dronpom->wez_srodek_drona()).dlugosc();
    return true;
}