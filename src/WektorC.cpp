#include "Wektor.cpp"

#include <iostream>
#include <iomanip>

template class Wektor<double, 2>;
template Wektor<double,2> operator *(double a, const Wektor<double,2> &Wektor2);
template std::ostream & operator <<(std::ostream &Strm, const Wektor<double, 2> &wektor);
template std::istream & operator >>(std::istream &Strm, Wektor<double, 2> &wektor);


template class Wektor<double, 3>;
template Wektor<double,3> operator *(double a, const Wektor<double,3> &Wektor2);
template std::ostream & operator <<(std::ostream &Strm, const Wektor<double, 3> &wektor);
template std::istream & operator >>(std::istream &Strm, Wektor<double, 3> &wektor);

