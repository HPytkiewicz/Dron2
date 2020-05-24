#include "Dr3D_gnuplot_api.hh"
#include "Draw3D_api_interface.hh"
#include "Wektor.hh"
#include "Macierz.hh"
#include "Plaszczyzna.hh"
#include "Dron.hh"
using namespace std;
using namespace drawNS;

void waitKey()
{
    do
    {
        std::cout << "\n Press a key to continue..." << std::endl;
    } while (cin.get() != '\n');
}

int main()
{
    std::shared_ptr<drawNS::Draw3DAPI> gnuplot(new APIGnuPlot3D(-25,25,-25,25,-25,25));
    gnuplot->change_ref_time_ms(0);

    Plaszczyzna Dno({-24,24,-24},{24,-24,-24}, gnuplot);
    Plaszczyzna Woda({-24,24,24},{24,-24,24},gnuplot);
    
    Dno.rysuj_plaszczyzne(); 
    Woda.rysuj_plaszczyzne();
    Woda.ustaw_niebieski();

    cout << " Dziala " << endl;
    vector<Wektor3D> wierzcholki_drona;
    wierzcholki_drona.reserve(8);
    wierzcholki_drona = 
    {
    wierzcholki_drona[0] = {0,0,0},
    wierzcholki_drona[1] = {0,6,0},
    wierzcholki_drona[2] = {6,6,0},
    wierzcholki_drona[3] = {6,0,0},
    wierzcholki_drona[4] = {0,0,6},
    wierzcholki_drona[5] = {0,6,6},
    wierzcholki_drona[6] = {6,6,6},
    wierzcholki_drona[7] = {6,0,6},
    };

    cout << " Dziala " << endl;
    cout << " Dziala " << endl;
    cout << "Wierzcholek 1: " << wierzcholki_drona[1]<< endl;
    Dron D1(wierzcholki_drona,{0,0,0},gnuplot);
    D1.rysuj();
    char odczyt;
    do{
        //D1.wez_polozenie();
        cout << endl << "Wczytaj swoj ruch: " << endl;
        cin >> odczyt;
        if(odczyt=='w')
        {
            D1.animacjaNaprzod();
            //D1.wez_polozenie();
        }
        if(odczyt=='r')
        {
            D1.animacjaObrotu();
            //D1.wez_polozenie();
        }
        gnuplot->redraw();
    } while (odczyt != 'k');
    //D1.wez_polozenie(); 

    return 0;
}