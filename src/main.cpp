#include <stdlib.h>
#include <memory>
#include "Dr3D_gnuplot_api.hh"
#include "Draw3D_api_interface.hh"
#include "Wektor.hh"
#include "Macierz.hh"
#include "Plaszczyzna.hh"
#include "Graniastoslup.hh"
#include "Dron.hh"
#include "InterfejsDrona.hh"
#include "Przeszkoda.hh"
#include "InterfejsPrzeszkody.hh"
using namespace std;
using namespace drawNS;

void waitKey()
{
    do
    {
        std::cout << "\n Press a key to continue..." << std::endl;
    } while (cin.get() != '\n');
}

vector<shared_ptr<InterfejsDrona>> kolekcja_dronow;

int main()
{
    std::shared_ptr<drawNS::Draw3DAPI> gnuplot(new APIGnuPlot3D(-45,45,-45,45,-45,45));
    gnuplot->change_ref_time_ms(0);

    Plaszczyzna Dno({-44,44,-44},{44,-44,-44}, gnuplot);
    Plaszczyzna Woda({-44,44,44},{44,-44,44}, gnuplot);
    
    Woda.rysuj_plaszczyzne();
    Woda.rysuj_plaszczyzne();
    Dno.rysuj_plaszczyzne();
    Woda.zmien_kolor('1');
    Dno.zmien_kolor('2');

    Macierz<double,3> bazowa_macierz;
    bazowa_macierz[0]={1,0,0};
    bazowa_macierz[1]={0,1,0};
    bazowa_macierz[2]={0,0,1};

    Wektor3D bazowy_srodek;
    bazowy_srodek[0]=0;
    bazowy_srodek[1]=0;
    bazowy_srodek[2]=0;

    Macierz<double,3> macierz_przeszkody1;
    macierz_przeszkody1[0]={1,0,0};
    macierz_przeszkody1[1]={0,0,-1};
    macierz_przeszkody1[2]={0,1,0};

    Wektor3D srodek_przeszkody1;
    srodek_przeszkody1[0]=0;
    srodek_przeszkody1[1]=35;
    srodek_przeszkody1[2]=0;

    Macierz<double,3> macierz_przeszkody2;
    macierz_przeszkody2[0]={1,0,0};
    macierz_przeszkody2[1]={0,1,0};
    macierz_przeszkody2[2]={0,0,1};

    Wektor3D srodek_przeszkody2;
    srodek_przeszkody2[0]=0;
    srodek_przeszkody2[1]=20;
    srodek_przeszkody2[2]=0;

    Macierz<double,3> macierz_przeszkody3;
    macierz_przeszkody3[0]={1,0,0};
    macierz_przeszkody3[1]={0,1,0};
    macierz_przeszkody3[2]={0,0,1};

    Wektor3D srodek_przeszkody2;
    srodek_przeszkody2[0]=0;
    srodek_przeszkody2[1]=20;
    srodek_przeszkody2[2]=0;

    vector<std::shared_ptr<InterfejsDrona>> kolekcja_dronow;
    vector<Przeszkoda> kolekcja_przeszkod;
    std::shared_ptr<InterfejsDrona> D1 = std::make_shared<Dron>(1,bazowy_srodek,gnuplot, bazowa_macierz);
    kolekcja_dronow.push_back(D1);
    Przeszkoda Blok1(0.5,srodek_przeszkody1, macierz_przeszkody1, gnuplot);
    kolekcja_przeszkod.push_back(Blok1);
    Przeszkoda Blok2(0.5,srodek_przeszkody2, macierz_przeszkody2, gnuplot);
    kolekcja_przeszkod.push_back(Blok2);
    Przeszkoda Blok3(1.5,srodek_przeszkody3, macierz_przeszkody3, gnuplot);
    kolekcja_przeszkod.push_back(Blok3);
    for(uint i=0; i<kolekcja_przeszkod.size();i++)
    {
        kolekcja_przeszkod[i].skrec();
        kolekcja_przeszkod[i].rysuj();
    }
    uint dron_id = 0;
    kolekcja_dronow[dron_id]->stworzDrona();

    
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
            kolekcja_dronow[dron_id]->animacjaNaprzod(kolekcja_przeszkod, kolekcja_dronow[dron_id]);
        }
        if(odczyt == 'r')
        {
            kolekcja_dronow[dron_id]->animacjaObrotu();
        }
        if(odczyt == 's')
        {
            for(uint i=0; i<kolekcja_dronow.size(); i++)
            {
                cout << "Dron " << i << " Id drona: " << kolekcja_dronow[i]->wez_id() << endl;
            }
            double skala;
            cout << "Podaj skale drona: " << endl;
            do{
            cin >> skala;
            }while(skala<=0);
            cout << "Podaj nowy srodek: " << endl;
            Wektor3D nowy_srodek;
            cout << "X " << endl;
            cin >> nowy_srodek[0];
            cout << "Y " << endl;
            cin >> nowy_srodek[1];
            cout << "Z " << endl;
            cin >> nowy_srodek[2];
            std::shared_ptr<InterfejsDrona> Dpom = std::make_shared<Dron>(skala,nowy_srodek, gnuplot, bazowa_macierz);
            kolekcja_dronow.push_back(Dpom);
            kolekcja_dronow.back()->stworzDrona();
        }
        if(odczyt == 'p')
        {
            for(uint i=0; i<kolekcja_dronow.size(); i++)
            {
                cout << "Dron " << i << " Id drona: " << kolekcja_dronow[i]->wez_id() << " Srodek drona: " << kolekcja_dronow[i]->wez_srodek_drona() << endl;
            }
            cout << "Podaj ktorym dronem chcesz sterowac: " << endl;
            uint pom;
            do{
            cin >> pom;
            }while(pom<0 || pom>kolekcja_dronow.size()-1);
            dron_id = pom;
        }
        if(odczyt == 'q')
        {
            kolekcja_dronow[dron_id]->wyswietl_wspolrzedne();
            cout << "Numer obecnego drona: " << dron_id << endl << "Srodek drona: " << kolekcja_dronow[dron_id]->wez_srodek_drona() << endl;
        }
    } while (odczyt != 'k');

    return 0;
}