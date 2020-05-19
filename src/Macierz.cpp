
#include "Macierz.hh"
#include <iomanip>

// Odwolanie sie do indexu macierzy
template<class TYP, int ROZMIAR>
const Wektor<TYP,ROZMIAR>  & Macierz<TYP,ROZMIAR>::operator[] (int index) const{

  if (index < 0 || index >= ROZMIAR) 
  {
    std::cerr << ERROROUTOFBOUNDS << std::endl;
    exit(1);
  }
  return this->tab[index];
}

// Odwolanie sie do indexu macierzy
template<class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> & Macierz<TYP,ROZMIAR>::operator[] (int index){

  if (index < 0 || index >= ROZMIAR) 
  {
    std::cerr << ERROROUTOFBOUNDS << std::endl;
    exit(1);
  }
  return this->tab[index];
}

// Dodawanie macierzy
template<class TYP, int ROZMIAR>
Macierz<TYP,ROZMIAR> Macierz<TYP,ROZMIAR>::operator +(const Macierz<TYP,ROZMIAR> & macierz) const{
  Macierz<TYP,ROZMIAR> pomocnicza;
  for(int i =0; i< ROZMIAR; i++)
    pomocnicza[i]=(*this)[i] + macierz[i];
  return pomocnicza;
}

// Odejmowanie macierzy
template<class TYP, int ROZMIAR>
Macierz<TYP,ROZMIAR> Macierz<TYP,ROZMIAR>::operator -(const Macierz<TYP,ROZMIAR> & macierz) const
{
  Macierz<TYP,ROZMIAR> pomocnicza;
  for (int i = 0; i < ROZMIAR; i++)    
  {
    pomocnicza[i] = (*this)[i] - macierz[i];
  }
  return pomocnicza;
}

// Mnozenie macierzy i liczby
template<class TYP, int ROZMIAR>
Macierz<TYP,ROZMIAR> Macierz<TYP,ROZMIAR>::operator *(double a) const 
{
  Macierz<TYP,ROZMIAR> pomocnicza;
  TYP pomocTYP(a);
  for (int i = 0; i < ROZMIAR; i++)    
  {
    pomocnicza[i] = (*this)[i] * pomocTYP;
  }
  return pomocnicza;
}

// Porownywanie macierzy (czy sa rowne)
template<class TYP, int ROZMIAR>
bool Macierz<TYP,ROZMIAR>::operator == (const Macierz<TYP,ROZMIAR> & Macierz2) const
{
  for (int i = 0; i < ROZMIAR; i++)    
  {
    if ((*this)[i] != Macierz2[i])
      return false;
  }
  return true;
}

// Porownywanie macierzy (czy nie sa rowne)
template<class TYP, int ROZMIAR>
bool Macierz<TYP,ROZMIAR>::operator != (const Macierz<TYP,ROZMIAR> & Macierz2) const
{
  return !(*this==Macierz2);
}

// Transopnuje macierz
template<class TYP, int ROZMIAR>
Macierz<TYP,ROZMIAR> Macierz<TYP,ROZMIAR>::transponuj() const
{
  Macierz<TYP,ROZMIAR> wynikowa;
  for (int j = 0; j < ROZMIAR; j++)
    for (int i = 0; i < ROZMIAR; i++)
        wynikowa[j][i]= (*this)[i][j];
  
  return wynikowa;
}

/*
// Oblicza dopelnienie macierzy
template<class TYP, int ROZMIAR>
TYP Macierz<TYP,ROZMIAR>::dopelnienie(int x, int y) const{
  Macierz<TYP,4> wynikowa;
  
  int nr_kolumny_mac = 0;
  for(int i=0; i<ROZMIAR; ++i){
    for (int nr_kolumny_dop = 0; nr_kolumny_dop < ROZMIAR-1; nr_kolumny_dop++)
      {
       int nr_kolumny_mac = 0;
       nr_kolumny_mac += (nr_kolumny_mac == i ? 1 : 0);  
         for (int nr_wiersza = 0; nr_wiersza < ROZMIAR-1; nr_wiersza++)
	   wynikowa[nr_wiersza][nr_kolumny_dop] = (*this)[nr_wiersza+1][nr_kolumny_mac];
       nr_kolumny_mac++;
      }
  }
  
  return wynikowa.wyznacznik();
}
// Oblicza macierz odwrotna
template<class TYP, int ROZMIAR>
Macierz<TYP,ROZMIAR> Macierz<TYP,ROZMIAR>::odwroc() const{
  Macierz macierzpom;
  double wyznacznik=(*this).wyznacznik(sarrus);
  if(wyznacznik != 0){
    for(int j=0; j<ROZMIAR; j++)
      for(int i=0; i<ROZMIAR; i++){
	macierzpom[i][j]=(*this).dopelnienie(i,j) / wyznacznik;
	if(!((i+j)%2)) macierzpom[i][j]=macierzpom[i][j]*(-1);
      }
  }else{
    exit(0);
  }
  return macierzpom.transponuj();
}
*/
// Mnozenie macierzy i wektora
template<class TYP, int ROZMIAR>
 Wektor<TYP,ROZMIAR> Macierz<TYP,ROZMIAR>::operator *(const Wektor<TYP,ROZMIAR> & wektor) const
{
  Wektor<TYP,ROZMIAR> wynik;
  for (int i = 0; i < ROZMIAR; i++)    
  {
    for (int j = 0; j < ROZMIAR; j++)    
    {
      wynik[i] += (*this)[j][i] * wektor[j];
    }
  }
  return wynik;
}


// Mnozenie dwoch macierzy
template<class TYP, int ROZMIAR>
Macierz<TYP,ROZMIAR> Macierz<TYP,ROZMIAR>::operator *(const Macierz<TYP,ROZMIAR> &macierz) const
{
  Macierz<TYP,ROZMIAR> wynik;
  Macierz<TYP,ROZMIAR> pomoc((*this).transponuj());
  for(int i=0; i<ROZMIAR; ++i)
    for(int j=0; j<ROZMIAR; ++j)
      wynik[j][i] += pomoc[j] * macierz[i];
  return wynik;
}

// Mnozenie liczby rzeczywistej i macierzy (odwrotna kolejnosc)
template<class TYP, int ROZMIAR>
Macierz<TYP,ROZMIAR> operator *(double a, const Macierz<TYP,ROZMIAR> macierz)
{
  return macierz*a;
}


// Obliczenie wyznacznika macierzy
template<class TYP, int ROZMIAR>
TYP Macierz<TYP,ROZMIAR>::wyznacznik() const{

    TYP wynik(1);
    Macierz<TYP,ROZMIAR> pomocnicza(*this);

    for(int i=0; i<ROZMIAR-1; i++){
      bool flag = false;
      int j = i;
      while(!flag && j < ROZMIAR)
	{
	  if(pomocnicza[i][j] != 0)
	    {
	      if(i!=j){
		pomocnicza = pomocnicza.ZmianaKolumn(i,j);
		wynik = wynik * (-1);
	      }
	      flag = true;
	    }
	  j++;
	}
      if(!flag){
	wynik = 0;
	return wynik;
      }
      for (int x = i+1; x < ROZMIAR; x++)
	pomocnicza[x]=pomocnicza[x] - pomocnicza[i] * pomocnicza[x][i] / pomocnicza[i][i];
    }
    for(int i=0; i<ROZMIAR; i++)
      wynik = wynik * pomocnicza[i][i];
    return wynik;

}

template<class TYP, int ROZMIAR>
Macierz<TYP,ROZMIAR> Macierz<TYP,ROZMIAR>::ZmianaKolumn(int wektor1, int wektor2) const
{
  Macierz<TYP,ROZMIAR> Wynikowa(*this);
  if (wektor1 < 0 || wektor1 >= ROZMIAR || wektor2 < 0 || wektor2 >= ROZMIAR)
  {
    std::cerr << ERROROUTOFBOUNDS << std::endl;
    exit(1);
  }
 
  Wektor<TYP,ROZMIAR> pomocniczy(Wynikowa[wektor1]);
  Wynikowa[wektor1] = Wynikowa[wektor2];
  Wynikowa[wektor2] = pomocniczy;
  return Wynikowa;
}

// Wczytanie macierzy
template<class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &strm, Macierz<TYP,ROZMIAR> &macierz)
{
  for (int i = 0; i < ROZMIAR; i++)
  { 
    strm>>macierz[i];
  }
  return strm;
}

// Wypisanie macierzy
template<class TYP, int ROZMIAR>
std::ostream& operator << (std::ostream &strm, const Macierz<TYP,ROZMIAR> &macierz)
{
  for (int i = 0; i < ROZMIAR; i++)
  {
     for (int j = 0; j < ROZMIAR; j++)
     {
       strm << std::setw(SKIP) << macierz.transponuj()[i][j];
     }
   strm  << std::endl;
  }
  return strm;
}
