#include "Plaszczyzna.hh"

Plaszczyzna::Plaszczyzna(Wektor3D lewygorny, Wektor3D prawydolny, std::shared_ptr<drawNS::Draw3DAPI> gnuplot)
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
    this->lacze=gnuplot;
}

void Plaszczyzna::rysuj_plaszczyzne()
{
    this->id = this->lacze->draw_surface(this->wierzcholki_plaszczyzny);
    cout << endl << "Narysowano plaszczyzne: " << this->id << endl;
}

void Plaszczyzna::usun_plaszczyzne()
{
    this->lacze->erase_shape(this->id);
    cout << endl << "Usunieto plaszczyzne: " << this->id << endl;
}

void Plaszczyzna::zmien_kolor(char nowy_kolor)
{
    /*cout << endl << "Oznaczenia kolorow:" << endl;
    cout << "1 - niebieski" << endl;
    cout << "2 - czarny" << endl;
    cout << "3 - bialy" << endl;
    cout << "4 - szary" << endl;
    cout << "5 - jasno niebieski" << endl;
    cout << "6 - czerwony" << endl;
    cout << "7 - zielony" << endl;
    cout << "8 - zolty" << endl;
    cout << "9 - pomaranczowy" << endl;
    cout << "0 - fioletowy" << endl; */
    switch(nowy_kolor){
    case '1':
    this->lacze->change_shape_color(this->id,"blue");
    cout << endl << "Zmieniono kolor plaszczyzny: " << this->id << endl;
    break;
    case '2':
    this->lacze->change_shape_color(this->id,"black");
    cout << endl << "Zmieniono kolor plaszczyzny: " << this->id << endl;
    break;
    case '3':
    this->lacze->change_shape_color(this->id,"white");
    cout << endl << "Zmieniono kolor plaszczyzny: " << this->id << endl;
    break;
    case '4':
    this->lacze->change_shape_color(this->id,"grey");
    cout << endl << "Zmieniono kolor plaszczyzny: " << this->id << endl;
    break;
    case '5':
    this->lacze->change_shape_color(this->id,"light-blue");
    cout << endl << "Zmieniono kolor plaszczyzny: " << this->id << endl;
    break;
    case '6':
    this->lacze->change_shape_color(this->id,"red");
    cout << endl << "Zmieniono kolor plaszczyzny: " << this->id << endl;
    break;
    case '7':
    this->lacze->change_shape_color(this->id,"green");
    cout << endl << "Zmieniono kolor plaszczyzny: " << this->id << endl;
    break;
    case '8':
    this->lacze->change_shape_color(this->id,"yellow");
    cout << endl << "Zmieniono kolor plaszczyzny: " << this->id << endl;
    break;
    case '9':
    this->lacze->change_shape_color(this->id,"orange");
    cout << endl << "Zmieniono kolor plaszczyzny: " << this->id << endl;
    break;
    case '0':
    this->lacze->change_shape_color(this->id,"purple");
    cout << endl << "Zmieniono kolor plaszczyzny: " << this->id << endl;
    break;
    default:
    cout << "Niepoprawny kolor." << endl;
    break;
    }
}