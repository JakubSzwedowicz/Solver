# Solver

Program do rozwiązywania układów liniowych zapisanych macierzowo w plikach .txt.
Naczelną zasadą jest, że w każdym wierszu musi być liczba wyrazów odpowiadająca liczbie niewiadomych + wynik równania dla tych zmiennych
oraz że liczba kolumn i wierszy musi być taka sama. Poza tym pierwsza litera w pliku .txt podaje typ zmiennych F - float, D - double.

Przykład z pliku macierz_1.txt:
```
F
0.9 1.3 -1.3 0.62
-1.5 0.2 -2.1 3.09
2.2 -2.9 -2.4 -0.93
```
zatem pierwszy wiersz to:
0.9x + 1.3y - 1.3z = 0.62

## Przygotowania do włączenia programu

Aby uruchomić poprawnie program należy załączyć wszystkie pliki w jednym projekcie, 
zaś folder "przykładowe macierze" umieścić w folderze z plikami źródłowymi.

### Programy dodatkowe

Nie ma większych wymagań co do oprogramowania potrzebnego do uruchomienia programu. 
W trakcie tworzenia oprogramowania korzystano z Microsoft Visual Studio Community 2019 16.1.0

## Testy

Przygotowane są 2 przykładowe testy demo3 oraz demo4 różniące się liczbą niewiadomych. 
Można je uruchomić bezpośrednio z poziomu aplikacji.

### Wyniki testów

Ich zadaniem jest pokazać przykładowe rozwiązane w konsoli. Wynik podawany jest w formie macierzy jednostkowej.

Przykład po rozwiązaniu demo3:
```
1.0 0 0 -0.3596
0 1.0 0 -1.3337
0 0 1.0 1.2675
```
Zatem x = -0.36, y = -1.33, z = 1.27

## Autor

* **Jakub Szwedowicz** - *Solver* - [JakubSzwedowicz](https://github.com/JakubSzwedowicz)
