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
    std::shared_ptr<drawNS::Draw3DAPI> gnuplot(new APIGnuPlot3D(-40,40,-40,40,-40,40));
    gnuplot->change_ref_time_ms(0);

    Plaszczyzna Dno({-39,39,-39},{39,-39,-39}, gnuplot);
    Plaszczyzna Woda({-39,39,39},{39,-39,39}, gnuplot);
    
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

    Wektor3D bazowy_srodek;
    bazowy_srodek[0]=0;
    bazowy_srodek[1]=0;
    bazowy_srodek[2]=0;

    vector<std::shared_ptr<InterfejsDrona>> kolekcja_dronow;
    std::shared_ptr<InterfejsDrona> D1 = std::make_shared<Dron>(1,bazowy_srodek,gnuplot, bazowa_macierz);
    kolekcja_dronow.push_back(D1);
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
            kolekcja_dronow[dron_id]->animacjaNaprzod();
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
                cout << "Dron " << i << " Id drona: " << kolekcja_dronow[i]->wez_id() << endl;
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
            cout << "Numer obecnego drona: " << dron_id << endl;
            cout << "Promien kolizji drona: " << kolekcja_dronow[dron_id]->wez_promien() << endl;
        }
    } while (odczyt != 'k');

    return 0;
}