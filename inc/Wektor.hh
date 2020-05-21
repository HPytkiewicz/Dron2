#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include <iostream>

template<class TYP, int ROZMIAR>

class Wektor {
protected:
  TYP tab[ROZMIAR];
  
  public:
  Wektor<TYP,ROZMIAR>() {for(TYP &ElemTab: tab) ElemTab =0;};
  Wektor<TYP,ROZMIAR>(double x, double y, double z){
    this->tab[0]=x;
    this->tab[1]=y;
    this->tab[2]=z;
  }
  
  const TYP & operator[] (int index) const;
  TYP & operator[] (int index);

  Wektor<TYP,ROZMIAR> operator + (Wektor<TYP,ROZMIAR> const &wektor) const;
  Wektor<TYP,ROZMIAR> operator - (Wektor<TYP,ROZMIAR> const &wektor) const;
  TYP operator * (Wektor<TYP,ROZMIAR> const &wektor) const;
  Wektor<TYP,ROZMIAR> operator * (TYP a) const;
  Wektor<TYP,ROZMIAR> operator / (TYP a) const;

  double dlugosc() const;

  bool operator == (const Wektor<TYP,ROZMIAR> &Wektor2) const;
  bool operator != (const Wektor<TYP,ROZMIAR> &Wektor2) const;
};

template<class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> operator * (TYP a, const Wektor<TYP,ROZMIAR> &Wektor2);

template<class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &strm, Wektor<TYP,ROZMIAR> &wektor);

template<class TYP, int ROZMIAR>
std::ostream& operator << (std::ostream &strm, const Wektor<TYP,ROZMIAR> &wektor);

#endif
