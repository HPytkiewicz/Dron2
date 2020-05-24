#include "Plaszczyzna.hh"

Plaszczyzna::Plaszczyzna(Wektor3D lewygorny, Wektor3D prawydolny, std::shared_ptr<drawNS::Draw3DAPI> gnuplot)
{
    for(int i = 0; i<abs(prawydolny[0])+abs(lewygorny[0])+1; i++)
    {
        vector<Point3D> v;
        this->wierzcholki_plaszczyzny.push_back(v); 
        for(int j = 0; j<(lewygorny[1])+abs(prawydolny[1]) + 1; j++)
        {
            if(i%2)
                 this->wierzcholki_plaszczyzny[i].push_back(Point3D(i-abs(lewygorny[0]),j-abs(prawydolny[1]),prawydolny[2]+0.5));
            else 
                 this->wierzcholki_plaszczyzny[i].push_back(Point3D(i-abs(lewygorny[0]),j-abs(prawydolny[1]),prawydolny[2]-0.5));
        }
    }
    this->lacze=gnuplot;
}

void Plaszczyzna::rysuj_plaszczyzne()
{
    this->usun_plaszczyzne();
    this->id = this->lacze->draw_surface(this->wierzcholki_plaszczyzny);
}

void Plaszczyzna::ustaw_niebieski()
{
    this->lacze->change_shape_color(this->id,"blue");
}

void Plaszczyzna::usun_plaszczyzne()
{
    this->lacze->erase_shape(this->id);
}