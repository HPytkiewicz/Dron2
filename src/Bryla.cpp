#include "Bryla.hh"

void Bryla::zeruj_orientacje()
{
    this->orientacja[0]={1,0,0};
    this->orientacja[1]={0,1,0};
    this->orientacja[2]={0,0,1};
}

/*void Bryla::wez_polozenie()
{
    cout << endl << "Orientacja: " << endl << (*this).wez_orientacje() << endl << "Srodek: " << endl << (*this).wez_srodek() << endl;
}*/