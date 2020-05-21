#include <iostream>
#include "Dron.hh"


using namespace std;
using namespace drawNS;

Dron::Dron(Wektor3D W0,Wektor3D W1,Wektor3D W2,Wektor3D W3,Wektor3D W4,Wektor3D W5,Wektor3D W6,Wektor3D W7){
wymiary.reserve(8);

this->wymiary = {
    wymiary[0]=W0,
    wymiary[1]=W1,
    wymiary[2]=W2,
    wymiary[3]=W3,
    wymiary[4]=W4,
    wymiary[5]=W5,
    wymiary[6]=W6,
    wymiary[7]=W7,
};


this->orientacja[0]={1,0,0};
this->orientacja[1]={0,1,0};
this->orientacja[2]={0,0,1};

};

void Dron::rysuj(){
    vector<vector<Point3D>> pomoc = {
        {
            Point3D((*this).wymiary[0][0], (*this).wymiary[0][1], (*this).wymiary[0][2]),
            Point3D((*this).wymiary[1][0], (*this).wymiary[1][1], (*this).wymiary[1][2]),
            Point3D((*this).wymiary[2][0], (*this).wymiary[2][1], (*this).wymiary[2][2]),
            Point3D((*this).wymiary[3][0], (*this).wymiary[3][1], (*this).wymiary[3][2]),
        },
        {
            Point3D((*this).wymiary[4][0], (*this).wymiary[4][1], (*this).wymiary[4][2]),
            Point3D((*this).wymiary[5][0], (*this).wymiary[5][1], (*this).wymiary[5][2]),
            Point3D((*this).wymiary[6][0], (*this).wymiary[6][1], (*this).wymiary[6][2]),
            Point3D((*this).wymiary[7][0], (*this).wymiary[7][1], (*this).wymiary[7][2]),
        }};

    gnuplot->draw_polyhedron(pomoc);
    }
}