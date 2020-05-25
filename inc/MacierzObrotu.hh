#ifndef MACIERZOB_HH
#define MACIERZOB_HH

#include "Macierz.hh"
#include <cmath>
#define PI 3.14159265

class MacierzObrotu
{
    public:
    /*!
    * \brief Statyczna metoda tworzaca macierz obrotu osi X
    * \param stopnie - wartosc obrotu macierzy
    */
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
    /*!
    * \brief Statyczna metoda tworzaca macierz obrotu osi Y
    * \param stopnie - wartosc obrotu macierzy
    */
        static Macierz<double,3> Y(double stopnie){

            Macierz<double,3> m = Macierz<double,3>();
            m[0][0] = cos(stopnie*PI/180);
            m[0][1] = 0;
            m[0][2] = sin(stopnie*PI/180);
            m[1][0] = 0;
            m[1][1] = 1;
            m[1][2] = 0;
            m[2][0] = -sin(stopnie*PI/180);
            m[2][1] = 0;
            m[2][2] = cos(stopnie*PI/180);

            return m;
        }
    /*!
    * \brief Statyczna metoda tworzaca macierz obrotu osi Z
    * \param stopnie - wartosc obrotu macierzy
    */
        static Macierz<double,3> Z(double stopnie){

            Macierz<double,3> m = Macierz<double,3>();
            m[0][0] = cos(stopnie*PI/180);
            m[0][1] = -sin(stopnie*PI/180);
            m[0][2] = 0;
            m[1][0] = sin(stopnie*PI/180);
            m[1][1] = cos(stopnie*PI/180);
            m[1][2] = 0;
            m[2][0] = 0;
            m[2][1] = 0;
            m[2][2] = 1;

            return m;
        }
};
#endif