## Zadanie 1

Pierwszy program polegał na demonstracji działania ifstream oraz ofstream. Miał za
zadanie przekopiowanie zawartości z pliku Input.txt do Output.txt.

```C++
#include <fstream>

using namespace std;

int main() {
    char ch;
    ifstream in;
    ofstream out;
    in.open("Input.txt");
    out.open("Output.txt");
    while (in >> ch)
    {
        out << ch;
    }
    in.close();
    out.close();
    return 0;
}
```

## Zadanie 2
Drugi program robił dokładnie to samo co pierwszy, jednak tym razem danymi były liczby.

```C++
#include <fstream>

using namespace std;

int main() {
    char ch;
    ifstream in;
    ofstream out;
    in.open("Input.txt");
    out.open("Output.txt");
    while (in >> ch)
    {
        out << ch << '\n';
    }
    in.close();
    out.close();
    return 0;
}
```

## Zadanie 3
Kolejny program miał na celu przekopiowanie liczb większych od 0 z Input.txt do pliku Output.txt.

```C++
#include <fstream>

using namespace std;

int main() {
    int liczba;
    ifstream in;
    ofstream out;
    in.open("Input.txt");
    out.open("Output.txt");
    while (in >> liczba)
    {
        if(liczba > 0) out << liczba << '\n';
    }
    in.close();
    out.close();
    return 0;
}
```

## Zadanie 4
W czwartym zadaniu, należało wykorzystać struktury do przchowania wartości z pliku Input.txt.

```C++
#include <fstream>
#include <iostream>

using namespace std;

struct Samochod
{
    char Nazwa[20];
    char Model[20];
    float Moc;
};

int main(){
    Samochod s[i];
    ifstream in;
    in.open("Input.txt");

    in >> s[i].Nazwa;
    in >> s[i].Model;
    in >> s[i].Moc;

    cout << s[i].Nazwa << '\n';
    cout << s[i].Model << '\n';
    cout << s[i].Moc << '\n';

    in.close();
    return 0;
}
```

## Zadanie 5
Następny program miał przypisywać wartości z pliku do wektora struktur utworzonych na podstawie struktury Samochod.

```C++
#include <fstream>
#include <iostream>

using namespace std;

struct Samochod
{
    char Nazwa[20];
    char Model[20];
    float Moc;
};

int main(){
    Samochod s[4];
    ifstream in;
    in.open("Input.txt");

    for(int i = 0; i < 4; i++)
    {
        in >> s[i].Nazwa;
        in >> s[i].Model;
        in >> s[i].Moc;
    }

    for(int i = 0; i < 4; i++)
    {
        cout << s[i].Nazwa << '\n';
        cout << s[i].Model << '\n';
        cout << s[i].Moc << '\n' << '\n';
    }

    in.close();
    return 0;
}
```

## Zadanie 6
W tym zadaniu trzeba było zrobić to samo co w poprzednim jednak z wykorzystaniem wskaźnika na wektor.

```C++
#include <fstream>
#include <iostream>

using namespace std;

struct Samochod
{
    char Nazwa[20];
    char Model[20];
    float Moc;
};

int main(){
    Samochod *s;
    int size;
    ifstream in;
    in.open("Input.txt");

    in >> size;
    s = new Samochod[size];
    int i = 0;
    while(i < size)
    {
        in >> s[i].Nazwa;
        in >> s[i].Model;
        in >> s[i].Moc;
        i++;
    }

    int i = 0;
    while(i < size)
    {
        cout << s[i].Nazwa << '\n';
        cout << s[i].Model << '\n';
        cout << s[i].Moc << '\n' << '\n';
        i++;
    }

    in.close();
    return 0;
}
```

## Zadanie 7
Siódme zadanie polegało na zczytaniu liczb z pliku do dynamicznego wektora i obliczenia ich sumy. Pierwsza wartość w pliku służy określeniu rozmiaru wektora więc nie jest brana do sumy.

```C++
#include <fstream>
#include <iostream>

using namespace std;

int main(){
    int* liczby;
    int size;
    int suma = 0;
    ifstream in;
    in.open("Input.txt");

    in >> size;
    liczby = new int[size];
    int i = 0;

    while(i < size)
    {
        in >> liczby[i];
        suma += liczby[i];
        i++;
    }

    in.close();
    cout << "Suma liczb: " << suma;
    return 0;
}
```

## Zadanie 8
Ostatnie zadanie polegało na pobraniu tekstu z pliku oraz sprawdzenia jego długości.

```C++
#include <fstream>
#include <iostream>

using namespace std;

int main(){
    char text[20];
    int size;
    ifstream in;
    in.open("Input.txt");

    for(int i = 0; i < 3; i++)
    {
        size = 0;
        in >> text;
        for(int j = 0; text[j] != '\0'; j++)
        {
            size++;
        }
        cout << "Dlugosc " << text << ": " << size << '\n';
    }

    in.close();
    return 0;
}
```