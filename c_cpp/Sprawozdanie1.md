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

### Tablica pomocnicza do zadań 6 - 11
| 1 | 2 | 3 | 4 | 5 |
|---|---|---|---|---|
| 1 | 2 | 3 | 4 | 5 |
| 1 | 2 | 3 | 4 | 5 |
| 1 | 2 | 3 | 4 | 5 |
| 1 | 2 | 3 | 4 | 5 |


## Zadanie 6
Następny program miał za zadanie zliczyć sumę liczb z tablicy dwuwymiarowej, pod
warunkiem że liczba jest mniejsza bądź równa 2 lub większa bądź równa 5.

```C++
#include <math.h>
#include <iostream>

using namespace std;

int main(){
    int tablica[5][5] = {{ 1, 2, 3, 4, 5 }, { 1, 2, 3, 4, 5 }, { 1, 2, 3, 4, 5 }, { 1, 2, 3, 4, 5 }, { 1, 2, 3, 4, 5 }};
    int i, j;
    int suma = 0;

    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
        {
            if(tablica[i][j] <= 2 || tablica[i][j] >= 5) suma = suma + tablica[i][j];
        }
    }

    cout << "Suma liczb tablicy mniejszych badz rownych 2, oraz wiekszych badz rownych 5: " << suma;
}
```

## Zadanie 7
Kolejny program szukał w tablicy dwuwymiarowej najmniejszej liczby.

```C++
#include <math.h>
#include <iostream>

using namespace std;

int main(){
    int tablica[5][5] = {{ 1, 2, 3, 4, 5 }, { 1, 2, 3, 4, 5 }, { 1, 2, 3, 4, 5 }, { 1, 2, 3, 4, 5 }, { 1, 2, 3, 4, 5 }};
    int i, j;
    int najmniejsza = tablica[0][0];

    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
        {
            if(tablica[i][j] < najmniejsza) najmniejsza = tablica[i][j];
        }
    }

    cout << "Najmniejszy element tablicy wynosi: " << najmniejsza;
}
```

## Zadanie 8
W następnym zadaniu, program miał zliczyć sumę liczb tablicy po ukosie (od lewego
górnego elementu, do prawego dolnego).

```C++
#include <math.h>
#include <iostream>

using namespace std;

int main(){
    int tablica[5][5] = {{ 1, 2, 3, 4, 5 }, { 1, 2, 3, 4, 5 }, { 1, 2, 3, 4, 5 }, { 1, 2, 3, 4, 5 }, { 1, 2, 3, 4, 5 }};
    int i;
    int suma = 0;

    for(i = 0; i < 5; i++)
    {
        suma = suma + tablica[i][i];
    }

    cout << "Suma liczb po przekatnej wynosi: " << suma;
}
```

## Zadanie 9
W kolejnym zadaniu, program miał zliczyć sumę liczb tablicy po ukosie, jak w
poprzednim zadaniu, oraz liczb znajdujących się pod tą przekątną.

```C++
#include <math.h>
#include <iostream>

using namespace std;

int main(){
    int tablica[5][5] = {{ 1, 2, 3, 4, 5 }, { 1, 2, 3, 4, 5 }, { 1, 2, 3, 4, 5 }, { 1, 2, 3, 4, 5 }, { 1, 2, 3, 4, 5 }};
    int i, j;
    int suma = 0;

    for(i = 0; i < 5; i++)
    {
        for(j = 0; j <= i; j++)
        {
            suma = suma + tablica[i][j];
        }
    }

    cout << "Suma liczb po przekatnej oraz liczb pod nia wynosi: " << suma;
}
```

## Zadanie 10
Następne zadanie polegało na stworzeniu programu, który korzystając z założeń
przekątnej w tablicy z poprzednich przykładów, znajdzie największą liczbę
znajdującą się w tej przekątnej oraz pod nią.

```C++
#include <math.h>
#include <iostream>

using namespace std;

int main(){
    int tablica[5][5] = {{ 1, 2, 3, 4, 5 }, { 1, 2, 3, 4, 5 }, { 1, 2, 3, 4, 5 }, { 1, 2, 3, 4, 5 }, { 1, 2, 3, 4, 5 }};
    int i, j;
    int najwieksza = tablica[0][0];

    for(i = 0; i < 5; i++)
    {
        for(j = 0; j <= i; j++)
        {
            if(tablica[i][j] > najwieksza) najwieksza = tablica[i][j];
        }
    }

    cout << "Najwieksza liczba z przekatnej oraz z liczb pod nia wynosi: " << najwieksza;
}
```

## Zadanie 11
Kolejny program miał za zadanie obliczać sumę liczb z przekątnej oraz znajdujących
się powyżej przekątnej z poprzednich przykładów.

```C++
#include <math.h>
#include <iostream>

using namespace std;

int main(){
    int tablica[5][5] = {{ 1, 2, 3, 4, 5 }, { 1, 2, 3, 4, 5 }, { 1, 2, 3, 4, 5 }, { 1, 2, 3, 4, 5 }, { 1, 2, 3, 4, 5 }};
    int i, j;
    int suma = 0;

    for(i = 0; i < 5; i++)
    {
        for(j = 0+i; j < 5; j++)
        {
            suma = suma + tablica[i][j];
        }
    }

    cout << "Suma liczba z przekatnej oraz liczb nad nia wynosi: " << suma;
}
```