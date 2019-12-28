#pragma once
#include <vector>
#include <string>

template<typename T>
class Macierz {
  int ile_wierszy;
  int dlugosc_wiersza;
  T *dane;
  T **wiersze;

 public:
  Macierz();
 
  void alokuj(int rozmiar);
  ~Macierz();
  // Usuniety konstruktor kopiujacy i operator przypisania powoduje,
  // ze obiektow tej klasy nie da sie przekazywac przez wartosc.
  // Jest to rowniez sposob dotrzymania zasady trzech.
  void operator=(const Macierz<T>& other_) = delete;
  Macierz(const Macierz<T>& other_) = delete;
  

  void zeruj();
  void wypelnij(std::vector<T> macierz);
  void pokaz() const;

  int getIleWierszy() { return ile_wierszy; }
  T& element(int i, int j) 
  {
	  if (i < ile_wierszy && j < dlugosc_wiersza)
		  return wiersze[i][j];
	  else
		  throw std::out_of_range ("Proba dostepu poza tablice! \n");
  }
  T& wolny(int i) 
  {
    return wiersze[i][dlugosc_wiersza - 1];
  }
  void ZamienWiersze(int pierwszy, int drugi);
  void ZamienKolumny(int pierwszy, int drugi);
};
