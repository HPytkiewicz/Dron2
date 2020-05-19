#include "Wektor.hh"
#include "Dr3D_gnuplot_api.hh"

using namespace drawNS;

class Helpers : public Wektor<double, 3>
{

public:
    static Wektor<double,3> Wektor3(double x, double y, double z){
        Wektor<double,3> w = Wektor<double,3>();
        w[0] = x;
        w[1] = y;
        w[2] = z;
        return w;
    }
    Point3D toPoint3D(){
        return Point3D(tab[0],tab[1],tab[2]);
    }
};