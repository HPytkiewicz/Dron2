#include "Bryla.hh"

void Bryla::zeruj_orientacje()
{
    this->orientacja[0]= this->zapasowa_orientacja[0];
    this->orientacja[1]= this->zapasowa_orientacja[1];
    this->orientacja[2]= this->zapasowa_orientacja[2];
}

void Bryla::wyswietl_wspolrzedne()
{
    cout << endl << "Orientacja: " << endl << this->wez_orientacje() << endl << "Srodek: " << endl << this->wez_srodek() << endl;
}