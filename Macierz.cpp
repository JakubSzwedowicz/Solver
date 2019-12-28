#pragma once
#include <iomanip>
#include <iostream>
#include "Macierz.h"

template class Macierz<double>;
template class Macierz<float>;

template<typename T>
Macierz<T>::Macierz()
{
	dane = nullptr;
	wiersze = nullptr;
	dlugosc_wiersza = 0;
	ile_wierszy = 0;
}
template<typename T>
void Macierz<T>::alokuj(int rozmiar)
{		
	ile_wierszy = rozmiar;
	dlugosc_wiersza = rozmiar + 1;
	dane = new T[rozmiar * dlugosc_wiersza];
	wiersze = new T* [rozmiar];
	for (int i = 0; i < ile_wierszy; ++i)
		wiersze[i] = dane + i * dlugosc_wiersza;
}
template<typename T>
Macierz<T>::~Macierz()
{
	delete[] dane;
	delete[] wiersze;
}
template<typename T>
void Macierz<T>::zeruj() {
  for (int i = 0; i < ile_wierszy*dlugosc_wiersza; ++i) {
    dane[i] = 0;
  }
}
template<typename T>
void Macierz<T>::wypelnij(std::vector<T> macierz)
{
	for (int i = 0; i < ile_wierszy * dlugosc_wiersza; i++)
		dane[i] = macierz[i];
}
template<typename T>
void Macierz<T>::pokaz() const {
  using std::cout;
  using std::endl;
  using std::setw;
  using std::fixed;
  using std::setprecision;
  for (int i = 0; i < ile_wierszy; ++i) {
    for (int j = 0; j < dlugosc_wiersza - 1; ++j) {
      cout << setw(8) << setprecision(4) << fixed << wiersze[i][j];
    }
    cout << "  |" << setw(8) << setprecision(4) << wiersze[i][dlugosc_wiersza - 1] << endl;
  }
}
template<typename T>
void Macierz<T>::ZamienWiersze(int pierwszy, int drugi)
{
	T* temp;
	temp = wiersze[pierwszy];
	wiersze[pierwszy] = wiersze[drugi];
	wiersze[drugi] = temp;
}
template<typename T>
void Macierz<T>::ZamienKolumny(int pierwszy, int drugi)
{
	T temp;
	for (int i = 0; i < ile_wierszy; i++)
	{
		temp = wiersze[i][pierwszy];
		wiersze[i][pierwszy] = wiersze[i][drugi];
		wiersze[i][drugi] = temp;
	}
}

