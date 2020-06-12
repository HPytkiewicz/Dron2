#include "Bryla.hh"

int Bryla::wszystkie_obiekty = 0;
int Bryla::zniszczone_obiekty = 0;


void Bryla::zeruj_orientacje()
{
    this->orientacja[0]= this->zapasowa_orientacja[0];
    this->orientacja[1]= this->zapasowa_orientacja[1];
    this->orientacja[2]= this->zapasowa_orientacja[2];
}
