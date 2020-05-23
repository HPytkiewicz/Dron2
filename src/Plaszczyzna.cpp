#include "Plaszczyzna.hh"

void Plaszczyzna::rysuj_plaszczyzne()
{
    vector<vector<Point3D>> pomoc;
    pomoc.reserve(4);
    pomoc = {
    {
        Point3D(-15,-15,this->wspolrzednaZ),
        Point3D(-15,15,this->wspolrzednaZ),
    },
    {
        Point3D(15,-15,this->wspolrzednaZ),
        Point3D(15,15,this->wspolrzednaZ),
    }};
    this->id = this->lacze->draw_surface(pomoc);
}

void Plaszczyzna::ustaw_niebieski()
{
    this->lacze->change_shape_color(this->id,"blue");
}