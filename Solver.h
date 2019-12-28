#pragma once
#include "Macierz.h"


template<typename T>
class Solver {
  Macierz<T>& mat;
  const int n;

  void skalujWiersz(int ktory, T skala);
  void addWiersze(int ktory, int do_ktorego, T skala = 1.0);
  void napraw(int ktory);

 public:
  Solver(Macierz<T>& mat_) : mat(mat_), n(mat.getIleWierszy()) {}

  void rozwiaz();
};
