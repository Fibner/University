## Zadanie 1
Początkowym zadaniem było napisanie prostego programu który obliczy sumę
dwóch podanych przez użytkownika liczb.

```C++
#include <math.h>
#include <iostream>

using namespace std;

int main(){
    int a;
    int b;
    int suma;

    cout << "Podaj pierwsza liczbe:";
    cin >> a;
    cout << "Podaj druga liczbe:";
    cin >> b;
    suma = a + b;
    cout << "Suma liczb " << a << " oraz " << b << " wynosi: " << suma;
}
```

## Zadanie 2
W drugim zadaniu program miał zliczyć sumę 10 cyfr za pomocą pętli while.

```C++
#include <math.h>
#include <iostream>

using namespace std;

int main(){
    int wektor[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int i = 0;
    int suma = 0;

    while(i < 0)
    {
        suma = suma + wektor[i];
        i++;
    }

    cout << "Suma wynosi: " << suma;
}
```

## Zadanie 3
W trzecim zadaniu program miał zliczyć sumę 10 cyfr, jednak tym razem z
wykorzystaniem pętli for.

```C++
#include <math.h>
#include <iostream>

using namespace std;

int main(){
    int wektor[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int i = 0;
    int suma = 0;

    for(i = 0; i < 10; i++)
    {
        suma = suma + wektor[i];
    }

    cout << "Suma wynosi: " << suma;
}
```

## Zadanie 4
Następne zadanie miało na celu stworzenie programu, który liczy sumę 10 cyfr, ale z
wyłączeniem liczb ujemnych. Posłużyłem się tutaj poprzednim przykładem dodając
instrukcję warunkową if.

```C++
#include <math.h>
#include <iostream>

using namespace std;

int main(){
    int wektor[10] = { -1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int i = 0;
    int suma = 0;

    for(i = 0; i < 10; i++)
    {
        if(wektor[i] > 0) suma = suma + wektor[i];
    }

    cout << "Suma wynosi: " << suma;
}
```

## Zadanie 5
Kolejne zadanie polegało na napisaniu programu, który będzie obliczał deltę z
podanych wartości a,b,c. Jeżeli delta będzie większa niż 0, program obliczy jej
rozwiązania x1 oraz x2.

```C++
#include <math.h>
#include <iostream>

using namespace std;

int main(){
    int a;
    int b;
    int c;
    int delta;
    int x1;
    int x2;
    cout << "Podaj dlugosc boku a: ";
    cin >> a;
    cout << "Podaj dlugosc boku b: ";
    cin >> b;
    cout << "Podaj dlugosc boku c: ";
    cin >> c;

    delta = pow(b, 2) - (4 * a * c);
    if(delta > 0)
    {
        x1 = (-b - sqrt(delta)) / 2 * a;
        x2 = (-b + sqrt(delta)) / 2 * a;
        cout << "Delta jest wieksza od 0, x1 =  " << x1 << ", x2 = " << x2;
    }
    else if(delta == 0)
    {
        x1 = (-b - sqrt(delta)) / 2 * a;
        cout << "Delta jest rowna 0, x1 =  " << x1;
    }
    else
    {
        cout << "Delta jest mniejsza od 0, brak rozwiazan";
    }
}
```