#include "Macierz.hh"
#include <cmath>
#define PI 3.14159

class MacierzObrotu
{
    public:
        static Macierz<double,3> X(double stopnie){

            Macierz<double,3> m = Macierz<double,3>();
            m[0][0] = 1;
            m[0][1] = 0;
            m[0][2] = 0;
            m[1][0] = 0;
            m[1][1] = cos(stopnie*PI/180);
            m[1][2] = -sin(stopnie*PI/180);
            m[2][0] = 0;
            m[2][1] = sin(stopnie*PI/180);
            m[2][2] = cos(stopnie*PI/180);

            return m;
        }
};