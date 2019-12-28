#pragma once
#include "dirent.h"
#undef max // dirent.h korzysta z tego makro

// Wykorzystuje linuxowe dirent.h
int skanuj_folder()
{
	DIR* folder;
	int i = 1;
	struct dirent* plik;
	if ((folder = opendir("przykladowe macierze")) != NULL)
	{
		while ((plik = readdir(folder)) != NULL)
		{
			if (plik->d_name[0] != '.')
			{
				printf("Plik %d: %s \n", i, plik->d_name);
				i++;
			}
		}
		closedir(folder);
	}
	else
	{
		perror("");
		return 0;
	}
} 
// Do kontrolowania b³êdów
int kontrola_bledow(int a, int b)
{
	int poprawka, flaga = 1;
	while (flaga)
	{
		std::cin >> poprawka;
		if (poprawka <= b && poprawka >= a && std::cin.fail() == false) //std::cin zwraca 0 przy z³ym formacie [ std::cin.failbit() ]
			flaga--;
		else
		{
			std::cout << "Wprowadzono bledna odpowiedz! \n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	return poprawka;
};
void demo3(Macierz<double>& m) {
	m.element(0, 0) = 0; //2.2
	m.element(0, 1) = -1.5;
	m.element(0, 2) = 0.6;
	m.wolny(0) = 1.3;
	m.element(1, 0) = 0;
	m.element(1, 1) = 1.2;
	m.element(1, 2) = 1.8;
	m.wolny(1) = 1.85;
	m.element(2, 0) = 1.2;
	m.element(2, 1) = 0.8;
	m.element(2, 2) = -2.1;
	m.wolny(2) = -4.55;
}
void demo4(Macierz<double>& m) {
	m.element(0, 0) = -0.2;
	m.element(0, 1) = 1.1;
	m.element(0, 2) = 0.1;
	m.element(0, 3) = 0.9;
	m.wolny(0) = 1.95;
	m.element(1, 0) = -1.2;
	m.element(1, 1) = 3.5;
	m.element(1, 2) = -2.6;
	m.element(1, 3) = 1.9;
	m.wolny(1) = 5.43;
	m.element(2, 0) = 0.8;
	m.element(2, 1) = -2.3;
	m.element(2, 2) = 1.2;
	m.element(2, 3) = -0.8;
	m.wolny(2) = -3.28;
	m.element(3, 0) = 0.2;
	m.element(3, 1) = -1.7;
	m.element(3, 2) = 1.9;
	m.element(3, 3) = 1.3;
	m.wolny(3) = -0.05;
}
void wyczysc_uklad(std::string& tekst, std::string& niewiadome)
{
	bool flaga = true;
	std::size_t pos;
	while (flaga)
	{
		while ((pos = tekst.find_first_of("=*+", 0)) != tekst.npos)
		{
			tekst[pos] = ' ';
			flaga = false;
		}
		if (flaga == false)
		{
			tekst.erase(std::remove_if(tekst.begin(), tekst.end(), isspace), tekst.end());
			while ((pos = tekst.find_first_of("qwertyuioplkjhgfdsazxcvbnm", 0)) != tekst.npos)
			{
				niewiadome.push_back(tekst[pos]);
				tekst[pos] = ' ';
			}
		}
		//std::remove_if(tekst.begin(), tekst.end(), isspace);
		flaga = false;
	}
};
template <typename T>
void zwroc_wynik(Macierz<T>& mat, std::string niewiadome)
{
	for (int i = 0; i < mat.getIleWierszy(); i++)
	{
		std::cout << niewiadome.at(i) << "=" << mat.element(i, mat.getIleWierszy()) << ", ";
	}
	std::cout << std::endl;
}
template <typename T>
void wczytaj_macierz(std::ifstream& plik)
{
	int dlugosc_wierszy = 2;
	int ilosc_wierszy = 0;
	int i = 1;
	std::string niewiadome;
	T num;
	std::vector<T>tekst_z_pliku;
	std::vector<std::string> tekst;
	plik.get();
	//for (int i = 0; i < 10; i++)
		//tekst[i].reserve(i);
	//wyczysc_uklad(tekst, plik);
	while (!plik.eof())
	{
		tekst.resize(i);
		getline(plik, tekst[ilosc_wierszy]);
		if (ilosc_wierszy != dlugosc_wierszy - 1)
		{
			wyczysc_uklad(tekst[ilosc_wierszy], niewiadome);
			std::stringstream ss(tekst[ilosc_wierszy]);
			while (ss >> num) tekst_z_pliku.push_back(num);
			if (ilosc_wierszy == 0)
				dlugosc_wierszy = tekst_z_pliku.size();
			ilosc_wierszy++;
			i++;
		}
	}
	dlugosc_wierszy = ilosc_wierszy + 1;
	Macierz<T> m;
	m.alokuj(dlugosc_wierszy - 1);
	m.wypelnij(tekst_z_pliku);
	Solver<T> s(m);
	m.pokaz();
	std::cout << std::endl;
	s.rozwiaz();
	m.pokaz();
	if (!niewiadome.empty())
		zwroc_wynik(m, niewiadome);
	system("pause");
};
