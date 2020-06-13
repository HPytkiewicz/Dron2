#include <iostream>
#include <cmath>
#include "Dron.hh"


using namespace std;
using namespace drawNS;

void Dron::stworzDrona()
{
    this->rysuj();
    double x = -1*abs(this->zapasowe_lokalne[0][0]*2)/3;
    double y = -1*abs(this->zapasowe_lokalne[0][1]);
    double z = abs(this->zapasowe_lokalne[0][2])/2;
    this->SrubaL.ustaw_srodek({-x,y,z});
    this->SrubaP.ustaw_srodek({x,y,z});
    this->SrubaL.ustaw_srodek(this->srodek + this->orientacja*this->SrubaL.wez_srodek());
    this->SrubaP.ustaw_srodek(this->srodek + this->orientacja*this->SrubaP.wez_srodek());
    this->SrubaL.rysuj();
    this->SrubaP.rysuj();
}

void Dron::animacjaNaprzod(vector<std::shared_ptr<InterfejsPrzeszkody>> kolekcja_przeszkod, shared_ptr<InterfejsDrona> dronpom)
{
    cout << endl << "Dziala " << endl;
    double kat, odleglosc;
    do{
    cout << "Podaj kat przechylenia: " << endl;
    cin >> kat;
    cout << "Podaj odleglosc ruchu: " << endl;
    cin >> odleglosc;
    }while(!cin.good());
    if(kat!=0)
    {
    for(int i=0; i<90; i++)
    {
        this->naprzod(0, kat/90);
        this->animacjaSruby();
        this->skrec();
        this->rysuj();
        usleep(1);
    }
    }
    bool kolizja = false;
    uint i=0;
    do
    {
        
        i++;
        this->naprzod(odleglosc/(2*abs(odleglosc)), 0);
        this->animacjaSruby();
        this->skrec();
        this->rysuj();
        for(uint j=0; j<kolekcja_przeszkod.size();++j)
        {
            cout << endl <<"Sprawdzana przeszkoda nr: " << j << endl;
            if(kolekcja_przeszkod[j]->czy_kolizja(dronpom))
            {
                kolizja = true;
                cout << " Napotkano kolizje " << endl;
            }
        }
        usleep(1);
    }while(i<2*abs(odleglosc) && !kolizja);
    if(kat!=0)
    {
    for(int i=0; i<90; i++)
    {
        this->naprzod(0, -1*kat/90);
        this->animacjaSruby();
        this->skrec();
        this->rysuj();
        usleep(1);
    }
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
        {
            this->dodaj_katZ(1);
        }
        else if(kat<0)
        {
            this->dodaj_katZ(-1);
        }
        else
        {
            this->dodaj_katZ(0);
        }
        this->skrec();
        this->animacjaSruby();
        this->rysuj();
        usleep(1);
    }
}

void Dron::animacjaSruby()
{
    double x = -1*abs(this->zapasowe_lokalne[0][0]*2)/3;
    double y = -1*abs(this->zapasowe_lokalne[0][1]);
    double z = abs(this->zapasowe_lokalne[0][2])/2;
    this->SrubaL.ustaw_srodek({-x,y,z});
    this->SrubaP.ustaw_srodek({x,y,z});
    this->SrubaL.ustaw_srodek(this->srodek + this->orientacja*this->SrubaL.wez_srodek());
    this->SrubaP.ustaw_srodek(this->srodek + this->orientacja*this->SrubaP.wez_srodek());
    this->SrubaL.dodaj_katX(10);
    this->SrubaL.skrec();
    this->SrubaP.dodaj_katX(10);
    this->SrubaP.skrec();
    this->SrubaL.rysuj();
    this->SrubaP.rysuj();
}

void Dron::wyswietl_wspolrzedne()
{
    cout << endl << "Orientacja: " << endl << this->wez_orientacje() << endl << "Srodek: " << endl << this->wez_srodek() << endl;
}

uint Dron::wez_id()
{
    return this->id;
}

double Dron::wez_promien()
{
    return sqrt(pow(this->zapasowe_lokalne[0][0],2)+pow(this->zapasowe_lokalne[0][1],2)+pow(this->zapasowe_lokalne[0][2],2));
}

Wektor3D Dron::wez_srodek_drona()
{
    return this->srodek;
}

bool Dron::czy_kolizja(std::shared_ptr<InterfejsDrona> dronpom)
{
    if(this->wez_srodek_drona() == dronpom->wez_srodek_drona())
        return false;
    double odleglosc = (this->srodek - dronpom->wez_srodek_drona()).dlugosc();
    if(dronpom->wez_promien() + this->wez_promien() >= odleglosc)
            return true;
    return false;
}

void Dron::stworz_przeszkode() 
{
    this->stworzDrona();
}

void Dron::zmien_kolor_drona(string nowy_kolor)
{
    this->ustaw_kolor(nowy_kolor);
    this->SrubaL.ustaw_kolor(nowy_kolor);
    this->SrubaP.ustaw_kolor(nowy_kolor);
}