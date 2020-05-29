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
    Plaszczyzna Woda({-24,24,24},{24,-24,24}, gnuplot);
    
    Woda.rysuj_plaszczyzne();
    Woda.rysuj_plaszczyzne();
    Dno.rysuj_plaszczyzne();
    Woda.zmien_kolor('1');
    Dno.zmien_kolor('2');

    vector<Wektor3D> wierzcholki_drona;
    wierzcholki_drona.reserve(8);
    wierzcholki_drona = 
    {
    wierzcholki_drona[0] = {-6,8,-4},
    wierzcholki_drona[1] = {6,8,-4},
    wierzcholki_drona[2] = {6,-8,-4},
    wierzcholki_drona[3] = {-6,-8,-4},
    wierzcholki_drona[4] = {-6,8,4},
    wierzcholki_drona[5] = {6,8,4},
    wierzcholki_drona[6] = {6,-8,4},
    wierzcholki_drona[7] = {-6,-8,4},
    };

    Macierz<double,3> bazowa_macierz;
    bazowa_macierz[0]={1,0,0};
    bazowa_macierz[1]={0,1,0};
    bazowa_macierz[2]={0,0,1};

    Dron D1(wierzcholki_drona,{0,0,0},gnuplot, bazowa_macierz);
    D1.rysuj();
    char odczyt;
    do{
        D1.wyswietl_wspolrzedne();
        cout << endl << "Wczytaj swoj ruch: " << endl;
        cin >> odczyt;
        if(odczyt=='w')
        {
            D1.animacjaNaprzod();
            D1.wyswietl_wspolrzedne();
        }
        if(odczyt=='r')
        {
            D1.animacjaObrotu();
            D1.wyswietl_wspolrzedne();
        }
    } while (odczyt != 'k');

    return 0;
}