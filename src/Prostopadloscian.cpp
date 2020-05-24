#include "Prostopadloscian.hh"

void Prostopadloscian::rysuj()
{
    this->usun();
    (*this).ustaw_globalnie();
    this->id = this->lacze->draw_polyhedron(wierzcholki_globalnie);
}

void Prostopadloscian::usun()
{
    this->lacze->erase_shape(this->id);
}

void Prostopadloscian::ustaw_globalnie()
{
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

void Prostopadloscian::zeruj_lokalne()
{
    this->wierzcholki_lokalnie = {
    wierzcholki_lokalnie[0] = this->zapasowe_lokalne[0],
    wierzcholki_lokalnie[1]=this->zapasowe_lokalne[1],
    wierzcholki_lokalnie[2]=this->zapasowe_lokalne[2],
    wierzcholki_lokalnie[3]=this->zapasowe_lokalne[3],
    wierzcholki_lokalnie[4]=this->zapasowe_lokalne[4],
    wierzcholki_lokalnie[5]=this->zapasowe_lokalne[5],
    wierzcholki_lokalnie[6]=this->zapasowe_lokalne[6],
    wierzcholki_lokalnie[7]=this->zapasowe_lokalne[7],
    };
}

void Prostopadloscian::skrec()
{
    (*this).zeruj_lokalne();
    (*this).zeruj_orientacje();
    auto rot = MacierzObrotu::Z(katZ)*MacierzObrotu::X(katX);
    this->orientacja = this->orientacja * rot;
    for (int i = 0; i < 8; i++)
    {
        (*this).wierzcholki_lokalnie[i] = orientacja * (*this).wierzcholki_lokalnie[i];
    }
}

void Prostopadloscian::naprzod(double odleglosc, double katpom)
{
    this->dodaj_katX(katpom);
    Wektor3D pomoc = {0,odleglosc,0};
    pomoc = this->orientacja * pomoc;
    this->srodek=this->srodek + pomoc;
}