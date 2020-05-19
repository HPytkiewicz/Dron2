#include "Dr3D_gnuplot_api.hh"
#include "Draw3D_api_interface.hh"
#include "Wektor.hh"
#include "Macierz.hh" 
#include "MacierzObrotu.hh" 
#include "Wektor3D.hh"
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
    auto gnuplot = APIGnuPlot3D(-10, 10, -10, 10, -10, 10, 20);
    gnuplot.change_ref_time_ms(1000);

    // gnuplot.draw_line(Point3D(1,2,3),Point3D(4,5,6));
    // vector<Point3D> p = {Point3D(1,2,3)};
    // vector<vector<Point3D>> robot = {
    //     { Point3D(0,0,0),  Point3D(10,0,0), Point3D(10,10,0), Point3D(0,10,0)  },
    //     { Point3D(0,0,10),  Point3D(10,0,), Point3D(10,10,10), Point3D(0,10,10) },
    // };

    // gnuplot.draw_polyhedron(robot);
    auto v1 = Helpers::Wektor3(0, 10, 0);
    auto v2 = Helpers::Wektor3(0, 0, 10);
    gnuplot.draw_line(Point3D(v1[0], v1[1], v1[2]), Point3D(v2[0], v2[1], v2[2]));
    auto rot = MacierzObrotu::X(90);
 
    // double stopnie = 30;
    //     {1,2},
    //     {3,4}
    // };
    //  Macierz<double,3> temp = {
    //             {1,0,0},
    //             {0,cos(stopnie*PI/180),-sin(stopnie*PI/180)},
    //             {0,sin(stopnie*PI/180), cos(stopnie*PI/180)}
    //         };
    waitKey();
    v1 = rot*v1;
    v2 = rot*v2;
    gnuplot.draw_line(Point3D(v1[0], v1[1], v1[2]), Point3D(v2[0], v2[1], v2[2]));
    waitKey();
    return 0; 
}