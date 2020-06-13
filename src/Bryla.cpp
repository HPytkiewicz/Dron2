#include "Bryla.hh"

int Bryla::wszystkie_obiekty = 0;
int Bryla::zniszczone_obiekty = 0;


void Bryla::zeruj_orientacje()
{
    this->orientacja[0]= this->zapasowa_orientacja[0];
    this->orientacja[1]= this->zapasowa_orientacja[1];
    this->orientacja[2]= this->zapasowa_orientacja[2];
}

void Bryla::zmien_kolor(char nowy_kolor)
{
    switch(nowy_kolor){
    case '1':
    this->lacze->change_shape_color(this->id,"blue");
    cout << endl << "Zmieniono kolor obiektu: " << this->id << endl;
    break;
    case '2':
    this->lacze->change_shape_color(this->id,"black");
    cout << endl << "Zmieniono kolor obiektu: " << this->id << endl;
    break;
    case '3':
    this->lacze->change_shape_color(this->id,"white");
    cout << endl << "Zmieniono kolor obiektu: " << this->id << endl;
    break;
    case '4':
    this->lacze->change_shape_color(this->id,"grey");
    cout << endl << "Zmieniono kolor obiektu: " << this->id << endl;
    break;
    case '5':
    this->lacze->change_shape_color(this->id,"light-blue");
    cout << endl << "Zmieniono kolor obiektu: " << this->id << endl;
    break;
    case '6':
    this->lacze->change_shape_color(this->id,"red");
    cout << endl << "Zmieniono kolor obiektu: " << this->id << endl;
    break;
    case '7':
    this->lacze->change_shape_color(this->id,"green");
    cout << endl << "Zmieniono kolor obiektu: " << this->id << endl;
    break;
    case '8':
    this->lacze->change_shape_color(this->id,"yellow");
    cout << endl << "Zmieniono kolor obiektu: " << this->id << endl;
    break;
    case '9':
    this->lacze->change_shape_color(this->id,"orange");
    cout << endl << "Zmieniono kolor obiektu: " << this->id << endl;
    break;
    case '0':
    this->lacze->change_shape_color(this->id,"purple");
    cout << endl << "Zmieniono kolor obiektu: " << this->id << endl;
    break;
    default:
    cout << "Niepoprawny kolor." << endl;
    break;
    }
}