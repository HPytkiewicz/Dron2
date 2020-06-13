#include "Plaszczyzna.hh"
#include "rozmiar.h"

Plaszczyzna::Plaszczyzna(Wektor3D lewygorny, Wektor3D prawydolny, std::shared_ptr<drawNS::Draw3DAPI> gnuplot, bool nowa_przenikalnosc):
Bryla(gnuplot, Wektor3D(0,0,lewygorny[2]))
{
    for(int i = 0; i<abs(prawydolny[0])+abs(lewygorny[0])+1; i+=5)
    {
        vector<Point3D> v;
        this->wierzcholki_plaszczyzny.push_back(v); 
        for(int j = 0; j<abs(lewygorny[1])+abs(prawydolny[1]) + 1; j+=5)
        {
            if(i%2)
                 this->wierzcholki_plaszczyzny[i/5].push_back(Point3D(i-abs(lewygorny[0]),j-abs(prawydolny[1]),prawydolny[2]+0.5));
            else 
                 this->wierzcholki_plaszczyzny[i/5].push_back(Point3D(i-abs(lewygorny[0]),j-abs(prawydolny[1]),prawydolny[2]-0.5));
        }
    }
    this->przenikalnosc=nowa_przenikalnosc;
    this->lacze=gnuplot;
    this->wysokosc=lewygorny[2];
}

void Plaszczyzna::rysuj()
{
    this->usun();
    this->id = this->lacze->draw_surface(wierzcholki_plaszczyzny, kolor);
}

void Plaszczyzna::usun()
{
    this->lacze->erase_shape(this->id);
    cout << endl << "Usunieto plaszczyzne: " << this->id << endl;
}

bool Plaszczyzna::czy_kolizja(std::shared_ptr<InterfejsDrona> dronpom)
{
    if(this->przenikalnosc)
    {
        if(dronpom->wez_srodek_drona()[2] <= this->wysokosc)
            return false;
        return true;
    }
    if(dronpom->wez_srodek_drona()[2] <= this->wysokosc - dronpom->wez_srodek_drona()[2]/2)
        return true;
    return false;

}

void Plaszczyzna::stworz_przeszkode()
{
    this->rysuj();
}