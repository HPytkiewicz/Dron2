#ifndef INTERPRZESZKODA_HH
#define INTERPRZESZKODA_HH

#include "Dr3D_gnuplot_api.hh"
#include <iostream>
#include <string>
#include <stdlib.h>
#include "rozmiar.h"
#include "MacierzObrotu.hh"
#include "Wektor3D.hh"
#include "InterfejsDrona.hh"

class InterfejsDrona;

class InterfejsPrzeszkody 
{
    public:
    virtual bool czy_kolizja(std::shared_ptr<InterfejsDrona> dronpom) = 0;

    virtual void stworz_przeszkode() = 0;
};

#endif