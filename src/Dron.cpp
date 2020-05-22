#include <iostream>
#include "Dron.hh"


using namespace std;
using namespace drawNS;

Dron::Dron(std::shared_ptr<drawNS::Draw3DAPI> gnuplot){
wierzcholki_lokalnie.reserve(8);

this->wierzcholki_lokalnie = {
    wierzcholki_lokalnie[0]={-4,6,-3},
    wierzcholki_lokalnie[1]={4,6,-3},
    wierzcholki_lokalnie[2]={4,-6,-3},
    wierzcholki_lokalnie[3]={-4,-6,-3},
    wierzcholki_lokalnie[4]={-4,6,3},
    wierzcholki_lokalnie[5]={4,6,3},
    wierzcholki_lokalnie[6]={4,-6,3},
    wierzcholki_lokalnie[7]={-4,-6,3},
};


this->orientacja[0]={1,0,0};
this->orientacja[1]={0,1,0};
this->orientacja[2]={0,0,1};

this->srodek={0,0,0};

this->lacze=gnuplot;
}

void Dron::rysuj()
{
    (*this).usun();
    (*this).ustaw_globalnie();
    id = lacze->draw_polyhedron(wierzcholki_globalnie);
}

void Dron::skrec(double stopnie)
{
auto rot = MacierzObrotu::X(stopnie);
for (int i = 0; i < 8; i++)
    {
        (*this).wierzcholki_lokalnie[i] = rot * (*this).wierzcholki_lokalnie[i];
    }
}

void Dron::usun()
{
    lacze->erase_shape((*this).id);
}

void Dron::ustaw_globalnie()
{
 wierzcholki_globalnie.reserve(8);
    this->wierzcholki_globalnie = {
        {
            Point3D((*this).wierzcholki_lokalnie[0][0]+srodek[0], (*this).wierzcholki_lokalnie[0][1]+srodek[1], (*this).wierzcholki_lokalnie[0][2]+srodek[2]),
            Point3D((*this).wierzcholki_lokalnie[1][0]+srodek[0], (*this).wierzcholki_lokalnie[1][1]+srodek[1], (*this).wierzcholki_lokalnie[1][2]+srodek[2]),
            Point3D((*this).wierzcholki_lokalnie[2][0]+srodek[0], (*this).wierzcholki_lokalnie[2][1]+srodek[1], (*this).wierzcholki_lokalnie[2][2]+srodek[2]),
            Point3D((*this).wierzcholki_lokalnie[3][0]+srodek[0], (*this).wierzcholki_lokalnie[3][1]+srodek[1], (*this).wierzcholki_lokalnie[3][2]+srodek[2]),
        },
        {
            Point3D((*this).wierzcholki_lokalnie[4][0]+srodek[0], (*this).wierzcholki_lokalnie[4][1]+srodek[1], (*this).wierzcholki_lokalnie[4][2]+srodek[2]),
            Point3D((*this).wierzcholki_lokalnie[5][0]+srodek[0], (*this).wierzcholki_lokalnie[5][1]+srodek[1], (*this).wierzcholki_lokalnie[5][2]+srodek[2]),
            Point3D((*this).wierzcholki_lokalnie[6][0]+srodek[0], (*this).wierzcholki_lokalnie[6][1]+srodek[1], (*this).wierzcholki_lokalnie[6][2]+srodek[2]),
            Point3D((*this).wierzcholki_lokalnie[7][0]+srodek[0], (*this).wierzcholki_lokalnie[7][1]+srodek[1], (*this).wierzcholki_lokalnie[7][2]+srodek[2]),
        }};     
}
