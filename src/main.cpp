#include "Dr3D_gnuplot_api.hh"
#include "Draw3D_api_interface.hh"
#include "Wektor.hh"
#include "Macierz.hh"
#include "MacierzObrotu.hh"
using namespace std;
using namespace drawNS;
#define PI 3.14159
void waitKey()
{
    do
    {
        std::cout << "\n Press a key to continue..." << std::endl;
    } while (std::cin.get() != '\n');
}

int main()
{
    auto gnuplot = APIGnuPlot3D(-10, 10, -10, 10, -10, 10, 200);

    // gnuplot.draw_line(Point3D(1,2,3),Point3D(4,5,6));
    // vector<Point3D> p = {Point3D(1,2,3)};
    // vector<vector<Point3D>> robot = {
    //     { Point3D(0,0,0),  Point3D(10,0,0), Point3D(10,10,0), Point3D(0,10,0)  },
    //     { Point3D(0,0,10),  Point3D(10,0,), Point3D(10,10,10), Point3D(0,10,10) },
    // };

    // gnuplot.draw_polyhedron(robot);
    //auto v1 = Helpers::Wektor3(0, 10, 0);
    //auto v2 = Helpers::Wektor3(0, 0, 10);
    //gnuplot.draw_line(Point3D(v1[0], v1[1], v1[2]), Point3D(v2[0], v2[1], v2[2]));
    //auto rot = MacierzObrotu::X(90);

    //waitKey();
    //v1 = rot*v1;
    //v2 = rot*v2;
    //gnuplot.draw_line(Point3D(v1[0], v1[1], v1[2]), Point3D(v2[0], v2[1], v2[2]));
    //waitKey();

    vector<Wektor<double, 3>> macierzWierzch1;
    macierzWierzch1.reserve(8);
    macierzWierzch1[0] = {-5, -5, -5};
    macierzWierzch1[1] = {5, -5, -5};
    macierzWierzch1[2] = {5, 5, -5};
    macierzWierzch1[3] = {-5, 5, -5};
    macierzWierzch1[4] = {-5, -5, 5};
    macierzWierzch1[5] = {5, -5, 5};
    macierzWierzch1[6] = {5, 5, 5};
    macierzWierzch1[7] = {-5, 5, 5};

    vector<vector<Point3D>> robot = {
        {
            Point3D(macierzWierzch1[0][0], macierzWierzch1[0][1], macierzWierzch1[0][2]),
            Point3D(macierzWierzch1[1][0], macierzWierzch1[1][1], macierzWierzch1[1][2]),
            Point3D(macierzWierzch1[2][0], macierzWierzch1[2][1], macierzWierzch1[2][2]),
            Point3D(macierzWierzch1[3][0], macierzWierzch1[3][1], macierzWierzch1[3][2]),
        },
        {
            Point3D(macierzWierzch1[4][0], macierzWierzch1[4][1], macierzWierzch1[4][2]),
            Point3D(macierzWierzch1[5][0], macierzWierzch1[5][1], macierzWierzch1[5][2]),
            Point3D(macierzWierzch1[6][0], macierzWierzch1[6][1], macierzWierzch1[6][2]),
            Point3D(macierzWierzch1[7][0], macierzWierzch1[7][1], macierzWierzch1[7][2]),
        }};
     cout << macierzWierzch1[7][0] << macierzWierzch1[7][1] << macierzWierzch1[7][2] <<endl;
    // uint id = gnuplot.draw_polyhedron(robot);
     
     waitKey();
    
    auto rot = MacierzObrotu::X(45);
    for (int i = 0; i < 8; i++)
    {
        cout<< "Przed" << macierzWierzch1[i] << endl;
        cout<< "Po" << rot * macierzWierzch1[i] << endl;
        macierzWierzch1[i] = rot * macierzWierzch1[i];
        cout<< "PoPrzypisaniu" << macierzWierzch1[i] << endl;
    }

    robot = {
        {
            Point3D(macierzWierzch1[0][0], macierzWierzch1[0][1], macierzWierzch1[0][2]),
            Point3D(macierzWierzch1[1][0], macierzWierzch1[1][1], macierzWierzch1[1][2]),
            Point3D(macierzWierzch1[2][0], macierzWierzch1[2][1], macierzWierzch1[2][2]),
            Point3D(macierzWierzch1[3][0], macierzWierzch1[3][1], macierzWierzch1[3][2]),
        }, 
        {
            Point3D(macierzWierzch1[4][0], macierzWierzch1[4][1], macierzWierzch1[4][2]),
            Point3D(macierzWierzch1[5][0], macierzWierzch1[5][1], macierzWierzch1[5][2]),
            Point3D(macierzWierzch1[6][0], macierzWierzch1[6][1], macierzWierzch1[6][2]),
            Point3D(macierzWierzch1[7][0], macierzWierzch1[7][1], macierzWierzch1[7][2]),
        }};
    gnuplot.draw_polyhedron(robot);
    //gnuplot.draw_polyhedron(robot);

    waitKey();

    /*
    gnuplot.draw_line(Point3D(macierzWierzch2[0][0],macierzWierzch2[0][1],macierzWierzch2[0][2]),
    Point3D(macierzWierzch2[1][0],macierzWierzch2[1][1],macierzWierzch2[1][2]));
    waitKey();

    auto rot = MacierzObrotu::X(20);
    //for(int i=0;i<2;i++)
    //{
    macierzWierzch2[1]=rot*macierzWierzch2[1];
    //}

    cout << "Macierz rotacji: " << endl << rot << endl;

    gnuplot.draw_line(Point3D(macierzWierzch2[0][0],macierzWierzch2[0][1],macierzWierzch2[0][2]),
    Point3D(macierzWierzch2[1][0],macierzWierzch2[1][1],macierzWierzch2[1][2]));
    waitKey();
    */
    return 0;
}