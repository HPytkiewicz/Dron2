#include "Graniastoslup.hh"

void Graniastoslup::rysuj()
{
    this->usun();
    (*this).ustaw_globalnie();
    this->id = this->lacze->draw_polyhedron(wierzcholki_globalnie, kolor);
}

void Graniastoslup::usun()
{
    this->lacze->erase_shape(this->id);
}

void Graniastoslup::ustaw_globalnie()
{
    this->wierzcholki_globalnie = {
        {
            Point3D((*this).wierzcholki_lokalnie[0][0]+srodek[0], (*this).wierzcholki_lokalnie[0][1]+srodek[1], (*this).wierzcholki_lokalnie[0][2]+srodek[2]),
            Point3D((*this).wierzcholki_lokalnie[1][0]+srodek[0], (*this).wierzcholki_lokalnie[1][1]+srodek[1], (*this).wierzcholki_lokalnie[1][2]+srodek[2]),
            Point3D((*this).wierzcholki_lokalnie[2][0]+srodek[0], (*this).wierzcholki_lokalnie[2][1]+srodek[1], (*this).wierzcholki_lokalnie[2][2]+srodek[2]),
            Point3D((*this).wierzcholki_lokalnie[3][0]+srodek[0], (*this).wierzcholki_lokalnie[3][1]+srodek[1], (*this).wierzcholki_lokalnie[3][2]+srodek[2]),
            Point3D((*this).wierzcholki_lokalnie[4][0]+srodek[0], (*this).wierzcholki_lokalnie[4][1]+srodek[1], (*this).wierzcholki_lokalnie[4][2]+srodek[2]),
            Point3D((*this).wierzcholki_lokalnie[5][0]+srodek[0], (*this).wierzcholki_lokalnie[5][1]+srodek[1], (*this).wierzcholki_lokalnie[5][2]+srodek[2]),
        },
        {
            Point3D((*this).wierzcholki_lokalnie[6][0]+srodek[0], (*this).wierzcholki_lokalnie[6][1]+srodek[1], (*this).wierzcholki_lokalnie[6][2]+srodek[2]),
            Point3D((*this).wierzcholki_lokalnie[7][0]+srodek[0], (*this).wierzcholki_lokalnie[7][1]+srodek[1], (*this).wierzcholki_lokalnie[7][2]+srodek[2]),
            Point3D((*this).wierzcholki_lokalnie[8][0]+srodek[0], (*this).wierzcholki_lokalnie[8][1]+srodek[1], (*this).wierzcholki_lokalnie[8][2]+srodek[2]),
            Point3D((*this).wierzcholki_lokalnie[9][0]+srodek[0], (*this).wierzcholki_lokalnie[9][1]+srodek[1], (*this).wierzcholki_lokalnie[9][2]+srodek[2]),
            Point3D((*this).wierzcholki_lokalnie[10][0]+srodek[0], (*this).wierzcholki_lokalnie[10][1]+srodek[1], (*this).wierzcholki_lokalnie[10][2]+srodek[2]),
            Point3D((*this).wierzcholki_lokalnie[11][0]+srodek[0], (*this).wierzcholki_lokalnie[11][1]+srodek[1], (*this).wierzcholki_lokalnie[11][2]+srodek[2]),
        }};     
}

void Graniastoslup::zeruj_lokalne()
{
    for(int i=0; i<12; i++)
    this->wierzcholki_lokalnie[i] = this->zapasowe_lokalne[i];
}

void Graniastoslup::skrec()
{
    (*this).zeruj_lokalne();
    (*this).zeruj_orientacje();
    auto rot = MacierzObrotu::Z(katZ)*MacierzObrotu::Y(katY)*MacierzObrotu::X(katX);
    this->orientacja = this->orientacja * rot;
    for (int i = 0; i < 12; i++)
    {
        (*this).wierzcholki_lokalnie[i] = orientacja * (*this).wierzcholki_lokalnie[i];
    }
}

void Graniastoslup::naprzod(double odleglosc, double katpom)
{
    this->dodaj_katX(katpom);
    Wektor3D pomoc = {0,odleglosc,0};
    pomoc = this->orientacja * pomoc;
    this->srodek=this->srodek + pomoc;
}

void Graniastoslup::ustaw_srodek(Wektor3D nowy_srodek)
{
    this->srodek = nowy_srodek;
}