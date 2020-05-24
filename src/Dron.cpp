#include <iostream>
#include <cmath>
#include "Dron.hh"


using namespace std;
using namespace drawNS;

void Dron::animacjaNaprzod()
{
    double kat, odleglosc;
    do{
    cout << "Podaj kat przechylenia: " << endl;
    cin >> kat;
    cout << "Podaj odleglosc ruchu: " << endl;
    cin >> odleglosc;
    }while(!cin.good());
    for(int i=0; i<60; i++)
    {
        this->naprzod(odleglosc/60, kat/60);
        this->skrec();
        this->rysuj();
        usleep(100);
    }
}

void Dron::animacjaObrotu()
{
    double kat;
    do{
        cout << "Podaj kat obrotu: " << endl;
        cin >> kat;
    }while(!cin.good());
    for(int i=0; i < abs(kat); i++)
    {
        if(kat>0)
            this->dodaj_katZ(1);
        else if(kat<0)
            this->dodaj_katZ(-1);
        else
            this->dodaj_katZ(0);
        this->skrec();
        this->rysuj();
        usleep(100);
    }
}
