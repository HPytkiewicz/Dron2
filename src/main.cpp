#include "Dr3D_gnuplot_api.hh"
#include "Draw3D_api_interface.hh"
#include "Wektor.hh"
#include "Macierz.hh"
#include "Plaszczyzna.hh"
#include "Graniastoslup.hh"
#include "Dron.hh"
#include "InterfejsDrona.hh"
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

    /*vector<Wektor3D> wierzcholki_drona;
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

    vector<Wektor3D> wierzcholki_drona2;
    wierzcholki_drona2.reserve(8);
    wierzcholki_drona2 = 
    {
    wierzcholki_drona2[0] = {-3,4,-2},
    wierzcholki_drona2[1] = {3,4,-2},
    wierzcholki_drona2[2] = {3,-4,-2},
    wierzcholki_drona2[3] = {-3,-4,-2},
    wierzcholki_drona2[4] = {-3,4,2},
    wierzcholki_drona2[5] = {3,4,2},
    wierzcholki_drona2[6] = {3,-4,2},
    wierzcholki_drona2[7] = {-3,-4,2},
    };
    */
    Macierz<double,3> bazowa_macierz;
    bazowa_macierz[0]={1,0,0};
    bazowa_macierz[1]={0,1,0};
    bazowa_macierz[2]={0,0,1};

    vector<Dron> kolekcja_dronow;
    Dron D1(2,{0,0,0},gnuplot, bazowa_macierz);
    kolekcja_dronow.push_back(D1);
    kolekcja_dronow[0].stworzDrona();
    int id=0;
    
    char odczyt;
    do{
        cout << "Wczytaj swoj ruch (m dla menu): ";
        cin >> odczyt;
        if(odczyt == 'm')
        {
            cout << endl << "Opcje programu: " << endl;
            cout << endl << "m - wyswietl menu " << endl;
            cout << endl << "w - ruch na wprost z podaniem kata wznoszenia/opadania " << endl;
            cout << endl << "r - obrot drona wokol osi Z " << endl;
            cout << endl << "s - stworz nowego drona " << endl;
            cout << endl << "p - przelacz sie na sterowanie innego drona " << endl;
            cout << endl << "q - wyswietl informacje o obecnym dronie " << endl;
        }
        if(odczyt == 'w')
        {
            kolekcja_dronow[id].animacjaNaprzod();
        }
        if(odczyt == 'r')
        {
            kolekcja_dronow[id].animacjaObrotu();
        }
        if(odczyt == 's')
        {
            cout << "Podaj skale drona: " << endl;
            double skala;
            cin >> skala;
            cout << "Podaj nowy srodek: " << endl;
            Wektor3D nowy_srodek;
            cout << "X " << endl;
            cin >> nowy_srodek[0];
            cout << "Y " << endl;
            cin >> nowy_srodek[1];
            cout << "Z " << endl;
            cin >> nowy_srodek[2];
            Dron Dpom(skala,nowy_srodek, gnuplot, bazowa_macierz);
            kolekcja_dronow.push_back(Dpom);
            kolekcja_dronow[id+1].stworzDrona();
        }
        if(odczyt == 'p')
        {
            cout << "Podaj ktorym dronem chcesz sterowac: " << endl;
            int pom;
            cin >> pom;
            id = pom;
        }
        if(odczyt == 'q')
        {
            kolekcja_dronow[id].wyswietl_wspolrzedne();
            cout << "Numer obecnego drona: " << id << endl;
        }
    } while (odczyt != 'k');

    return 0;
}