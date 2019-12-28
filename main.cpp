#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <typeinfo>
#include <sstream>
#include <algorithm>
#include "Macierz.h"
#include "Solver.h"
#include "GlobalneFunkcje.h"


//#define _CRTDBG_MAP_ALLOC	//Do 
//#include <stdlib.h>			//wycieku 
//#include <crtdbg.h>			//pamiêci




int main(int argc, char** argv)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //Do wycieku pamiêci
	std::ifstream plik;
	int decyzja, flaga1 = 1;
	char nazwa_pliku[50], format;
	while (flaga1)
	{		
		try
		{
			system("cls");
			std::cout << "Menu: \n 1. Rozwiaz macierz wedlug demo3 \n 2. Rozwiaz macierz wedlug demo4 \n 3. Wczytaj macierz z pliku \n 4. Zamknij \n";
			decyzja = kontrola_bledow(1, 4);
			switch(decyzja)
			{
				case 1:
				case 2:
				{
					Macierz<double> m;
					if (decyzja == 1)
					{
						m.alokuj(3);
						demo3(m);
					}
					else
					{
						m.alokuj(4);
						demo4(m);
					}
					m.pokaz();
					std::cout << std::endl;
					Solver<double> s(m);
					s.rozwiaz();
					m.pokaz();
					system("pause");
				}
				break;
				case 3:	
				{
					skanuj_folder();
					std::cout << "Ktory plik chcesz wczytac? \n";
					std::cin >> nazwa_pliku;
					std::string sciezka("przykladowe macierze\\");
					sciezka.append(nazwa_pliku);
					//std::string sciezka("przykladowe macierze\\pro_uklad_1.txt");
					plik.open(sciezka, std::ifstream::in);
					if (plik.is_open())
					{
						plik >> format;
						if (format == 'D')
							wczytaj_macierz<double>(plik);
						else if (format == 'F')
							wczytaj_macierz<float>(plik);
						else
						{
							std::cout << "Bledny format pliku! \n";
							system("pause");
							break;
						}
						plik.close();
					}
					else
					{
						std::cout << "Nie udalo sie otworzyc pliku! \n";
						system("pause");
					}
				}
				break;
				case 4:
					flaga1 = 0;
					break;
			}			
		}
		catch (std::exception& wyjatek)
		{
			std::cout << wyjatek.what(); 
			system("pause");
		}
		catch (const char& tekst)
		{
			std::cout << tekst;
			system("pause");
		}
		catch (...)
		{
			std::cout << "Wystapil blad!";
			system("pause");
		}
	}	
	
	return 0;
}


