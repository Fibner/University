## Zadanie 1
Pierwsze zadanie polegało na przeprowadzeniu prostych operacji na tablicy. Mianowicie zsumowaniu wszystkich liczb, znalezeniu największej oraz najmniejszej.
```C++
#include <iostream>

using namespace std;

int main() {
	int tablica[5][5] = { {1,2,3,4,5},{1,2,3,4,5}, {1,2,3,4,5}, {1,2,3,4,5}, {1,2,3,4,5} };
	int suma = 0;
	int max = tablica[0][0];
	int min = tablica[0][0];

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			suma += tablica[i][j];
			if (tablica[i][j] > max) max = tablica[i][j];
			if (tablica[i][j] < min) min = tablica[i][j];
		}
	}

	cout << "Suma tablicy wynosi " << suma << '\n';
	cout << "Największa wartość tablicy wynosi " << max << '\n';
	cout << "Najmniejsza wartość tablicy wynosi " << min << '\n';
}
```
## Zadanie 2
Kolejne zadanie bazowało na poprzednim, jednak dane wyjsciowe trzeba było zapisać do pliku. 
```C++
#include <iostream>
#include <fstream>

using namespace std;

int main() {
	int tablica[5][5] = { {1,2,3,4,5},{1,2,3,4,5}, {1,2,3,4,5}, {1,2,3,4,5}, {1,2,3,4,5} };
	int suma = 0;
	int max = tablica[0][0];
	int min = tablica[0][0];
	ofstream out;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			suma += tablica[i][j];
			if (tablica[i][j] > max) max = tablica[i][j];
			if (tablica[i][j] < min) min = tablica[i][j];
		}
	}

	out.open("Output.txt");
	out << "Suma tablicy wynosi " << suma << '\n';
	out << "Najwieksza wartosc tablicy wynosi " << max << '\n';
	out << "Najmniejsza wartosc tablicy wynosi " << min << '\n';
	out.close();
}
```
## Zadanie 3
Następne zadanie wymagało wczytania tekstu z konsoli oraz policzenia ilości liter. 
```C++
#include <iostream>

using namespace std;

int main() {
	int i;
	string tekst;
	cin >> tekst;
	for (i = 0; tekst[i] != '\0'; i++);
	cout << "Dlugosc tekstu wynosi " << i;
}
```
## Zadanie 4
Ostatnie zadanie polegało na przekopiowaniu napisu z pliku wejsciowego do pliku wyjściowego, z obliczoną długością tego wyrazu.
```C++
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	int i;
	ifstream in;
	ofstream out;
	string tekst;
	
	in.open("Input.txt");
	while (in >> tekst)
	{
		for (i = 0; tekst[i] != '\0'; i++);
	}
	in.close();

	out.open("Output.txt");
	out << tekst << " ma znakow " << i;
	out.close();
}
```