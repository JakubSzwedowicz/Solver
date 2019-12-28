#pragma once
#include "Solver.h"
#include <iostream>

//template class Solver<int>; //Rozwiazanie aby definicje byly w .cpp https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl
template class Solver<double>;
template class Solver<float>;

template<typename T>
void Solver<T>::skalujWiersz(int ktory, T skala) {
  // mnozy kazdy element wiersza przez skalar
  for (int i = 0; i < n + 1; ++i) {
    mat.element(ktory, i) *= skala;
  }
}

template<typename T>
void Solver<T>::addWiersze(int ktory, int do_ktorego, T skala) {
  // dodaje pierwszy rzad do drugiego, mnozac wczesniej jego wartosci przez skalar
  for (int i = 0; i < n + 1; ++i) {
    mat.element(do_ktorego, i) += skala * mat.element(ktory, i);
  }
}

template<typename T>
void Solver<T>::napraw(int ktory)
{
	T wyraz = mat.element(ktory, ktory);
	for (int i = ktory; i < mat.getIleWierszy() - 1 && wyraz == 0; i++)
	{
		if (mat.element(i + 1, ktory) != 0)
		{
			mat.ZamienWiersze(ktory, i + 1);
			wyraz = mat.element(ktory, ktory);
		}
		else if (mat.element(ktory, i + 1) != 0)
		{
			mat.ZamienKolumny(ktory, i + 1);
			wyraz = mat.element(ktory, ktory);
		}
	}
	if(wyraz == 0)
		throw "Nie mozna zamienic wierszy i wystepuje dzielenie przez 0! \n";	
}

template<typename T>
void Solver<T>::rozwiaz() 
{
	T pierwszy;
	// rozwiazuj kazda kolumne z osobna
	for (int i = 0; i < n; ++i) 
	{
		// znormalizuj dany wiersz (na diagonalnej musza byc same 1)
		pierwszy = mat.element(i, i);
		if (pierwszy == 0)
		{
			napraw(i);
			std::cout << std::endl;
			pierwszy = mat.element(i, i);
		}
		skalujWiersz(i, 1.0 / pierwszy);
		// uzyj i-tego wiersza do wyeliminowania wszystkich pozostalych
		for (int j = 0; j < n; ++j)
		{
			if (i == j) continue; // nie wyeliminuj siebie
			// przemnoz wiersz przez te wartosc, by wyeliminowac element na i-tym miejscu
			T skala = -1.0 * mat.element(j, i);
			addWiersze(i, j, skala);
		}
	}
}