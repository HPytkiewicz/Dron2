#ifndef PRZESZKODA_HH
#define PRZESZKODA_HH

#include "Dr3D_gnuplot_api.hh"
#include <iostream>
#include "rozmiar.h"
#include "Prostopadloscian.hh"
#include "MacierzObrotu.hh"
#include "Wektor3D.hh"
#include "InterfejsDrona.hh"

class Przeszkoda 
{
    public:
        virtual bool czy_kolizja(std::shared_ptr<InterfejsDrona> dronpom);
};

#endif