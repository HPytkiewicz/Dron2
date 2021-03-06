#include <stdlib.h>
#include <memory>
#include "Dr3D_gnuplot_api.hh"
#include "Draw3D_api_interface.hh"
#include "Wektor.hh"
#include "Macierz.hh"
#include "Plaszczyzna.hh"
#include "Graniastoslup.hh"
#include "Bryla.hh"
#include "Dron.hh"
#include "InterfejsDrona.hh"
#include "Przeszkoda.hh"
#include "InterfejsPrzeszkody.hh"
#include "MacierzObrotu.hh"
using namespace std;
using namespace drawNS;

void waitKey()
{
    do
    {
        std::cout << "\n Press a key to continue..." << std::endl;
    } while (cin.get() != '\n');
}

void wyswietl_ilosc_obiektow()
{
    cout << "Ilosc aktualnych obiektow: " << Bryla::wez_aktualne_obiekty() << endl;
    cout << "Ilosc wszystkich obiektow: " << Bryla::wez_wszystkie_obiekty() << endl;
}

vector<shared_ptr<InterfejsDrona>> kolekcja_dronow;

int main()
{
    std::shared_ptr<drawNS::Draw3DAPI> gnuplot(new APIGnuPlot3D(-45,45,-45,45,-45,55));
    gnuplot->change_ref_time_ms(0);

    Macierz<double,3> bazowa_macierz;
    bazowa_macierz[0]={1,0,0};
    bazowa_macierz[1]={0,1,0};
    bazowa_macierz[2]={0,0,1};

    vector<std::shared_ptr<InterfejsDrona>> kolekcja_dronow;
    vector<std::shared_ptr<InterfejsPrzeszkody>> kolekcja_przeszkod;
    std::shared_ptr<Plaszczyzna> Dno = std::make_shared<Plaszczyzna>(Wektor3D(-44,44,-44),Wektor3D(44,-44,-44), gnuplot, false);
    std::shared_ptr<Plaszczyzna> Woda = std::make_shared<Plaszczyzna>(Wektor3D(-44,44,44),Wektor3D(44,-44,44), gnuplot, true);
    kolekcja_przeszkod.push_back(Woda);
    kolekcja_przeszkod.push_back(Dno);
    Woda->rysuj();
    Dno->rysuj();
    Woda->ustaw_kolor("blue");
    Dno->ustaw_kolor("black");
    std::shared_ptr<Dron> D1 = std::make_shared<Dron>(1,Wektor3D{0,0,0},gnuplot, bazowa_macierz);
    kolekcja_dronow.push_back(D1);
    kolekcja_przeszkod.push_back(D1);
    D1->zmien_kolor_drona("red");
    std::shared_ptr<Przeszkoda> Blok1 = std::make_shared<Przeszkoda>(0.5,Wektor3D{10,0,25}, MacierzObrotu::X(45), gnuplot);
    kolekcja_przeszkod.push_back(Blok1);
    Blok1->ustaw_kolor("purple");
    std::shared_ptr<Przeszkoda> Blok2 = std::make_shared<Przeszkoda>(1.2,Wektor3D{15,35,-15}, MacierzObrotu::Y(90), gnuplot);
    kolekcja_przeszkod.push_back(Blok2);
    Blok2->ustaw_kolor("purple");
    std::shared_ptr<Przeszkoda> Blok3 = std::make_shared<Przeszkoda>(1,Wektor3D{-25,-25,5}, MacierzObrotu::Z(60), gnuplot);
    kolekcja_przeszkod.push_back(Blok3);
    Blok3->ustaw_kolor("purple");
    for(uint i=0; i<kolekcja_przeszkod.size();i++)
    {
        kolekcja_przeszkod[i]->stworz_przeszkode();
    }
    uint dron_id = 0;
    kolekcja_dronow[dron_id]->stworzDrona();

    
    char odczyt;
    wyswietl_ilosc_obiektow();
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
            std::shared_ptr<Dron> Dpom = std::make_shared<Dron>(skala,nowy_srodek, gnuplot, bazowa_macierz);
            kolekcja_dronow.push_back(Dpom);
            kolekcja_przeszkod.push_back(Dpom);
            Dpom->zmien_kolor_drona("green");
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
            for(uint i=0; i<kolekcja_dronow.size(); i++)
            {
                kolekcja_dronow[i]->zmien_kolor_drona("green");
                kolekcja_dronow[i]->stworzDrona();
            }    
            kolekcja_dronow[dron_id]->zmien_kolor_drona("red");
            kolekcja_dronow[dron_id]->stworzDrona();
        }
        if(odczyt == 'q')
        {
            kolekcja_dronow[dron_id]->wyswietl_wspolrzedne();
            cout << "Numer obecnego drona: " << dron_id << endl << "Srodek drona: " << kolekcja_dronow[dron_id]->wez_srodek_drona() << endl;
        }
        wyswietl_ilosc_obiektow();
    } while (odczyt != 'k');

    return 0;
}