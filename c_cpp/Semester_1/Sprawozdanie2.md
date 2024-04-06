## Zadanie 1
Pierwszy program pokazuje jak język C oraz C++ w zmiennej CHAR przechowuje znaki tekstowe za pomocą tablicy ASCII. Dzięki temu dodając liczbę możemy zmienić znak tekstowy.

```C++
#include <iostream>

using namespace std;

int main(){
    char znak;
    znak = 'A';

    cout << '\n' << znak;
    znak = 76;
    cout << '\n' << znak;

    znak = 'A';
    znak = znak + 10;
    cout << '\n' << znak;

    return 0;
}
```

## Zadanie 2
Kolejne zadanie polegało na utworzeniu programu, który za pomocą pętli for wypisuje z znaki oraz przynależny im kod z tablicy ASCII.

```C++
#include <iostream>

using namespace std;

int main(){
    char znak;
    int i;

    for(znak = 0; znak < 127; znak++)
    {
        i = znak;
        cout << "znak = " << znak << " kod znaku = " << i << '\n';
    }

    return 0;
}
```

## Zadanie 3
Następny program, za pomocą pętli for liczy ilość znaków w tekście przechowywanym w tablicy znaków (stringu).

```C++
#include <iostream>

using namespace std;

int main(){
    char T[80] = { "ALFA BETA GAMMA" };
    int i;

    for(i = 0; T[i] != '\0'; i++);
    cout << T << " liczba znakow: " << i;
    
    return 0;
}
```

## Zadanie 4
Kolejny program odpowiada za skopiowanie tekstu z jednej zmiennej do drugiej.

```C++
#include <iostream>

using namespace std;

int main(){
    char T1[80] = { "ALFA" };
    char T2[80];
    int i;

    for(i = 0; T1[i] != '\0'; i++)
    {
        T2[i] = T1[i];
    }
    T2[i] = '\0';
    cout << T2;
    
    return 0;
}
```

## Zadanie 5
Piąty program miał za zadanie złączyć tekst z dwóch zmiennych i zapisać go w trzeciej zmiennej.

```C++
#include <iostream>

using namespace std;

int main(){
    char T1[80] = { "ALFA" };
    char T2[80] = { "BETA" };
    char T3[80];
    int i;
    int j;

    for(i = 0; T1[i] != '\0'; i++) T3[i] = T1[i];
    j = i;
    for(i = 0; T2[i] != '\0'; i++) T3[j + i] = T2[i];

    T3[j + i] = '\0';
    cout << T3;

    return 0;
}
```

## Zadanie 6
Następne zadanie polegało na stworzeniu programu, który wypisuje tekst ze zmiennej w odwróconej kolejności.

```C++
#include <iostream>

using namespace std;

int main(){
    char T1[80] = { "1234567" };
    int i;
    int temp;

    cout << T1 << '\n';
    for(i = 0; i < 6/2; i++)
    {
        temp = T1[6 - i];
        T1[6 - i] = T1[i];
        T1[i] = temp;
    }
    cout << T1;

    return 0;
}
```

## Zadanie 7
Kolejny program miał zliczyć ilosć poszczególnych liczb w tekście.

```C++
#include <iostream>

using namespace std;

int main(){
    char T1[80] = { "1234567" };
    int count;
    int i;
    int j;
    int temp;

    for(i = 0; i < 9; i++)
    {
        count = 0;
        for(j = 0; T1[j] != '\0'; j++)
        {
            if(T1[j] - '0' == i) count++;
        }
        cout << "Liczba " << i << " wystapila: " << count << " razy\n";
    }
    return 0;
}
```

## Zadanie 8
Ósme zadanie polegało na napisaniu programu, który ze zmiennej tekstowej usuwa wszystkie 1, a następnie wypisuje tekst użytkownikowi.

```C++
#include <iostream>

using namespace std;

int main(){
    char T1[80] = { "1213415671" };
    int i;
    int j;

    for(i = 0; T1[i] != '\0'; i++)
    {
        if(T1[i] == '1'){
            for(j = i; T1[j] != '\0'; j++)
            {
                T1[j] = T1[j + 1];
            }
        }
    }
    cout << T1;
    return 0;
}
```

## Zadanie 9
Przed ostatnie zadanie polegało na napisaniu programu który ze zmiennej tekstowej znajduje liczby szesnastkowe i zapisuje je w postaci dziesiętnej. Do tego zadania napisałem fukncję która zamienia tekstowe liczby szesnastkowe na dziesiętne typu int.

```C++
#include <iostream>
#include <cmath>

using namespace std;

int hexConvert(char* text, int& sizeTemp){
    int j;
    int decimalTemp = 0;
    int decimal = 0;
    for(j = sizeTemp; j >= 0; j--)
    {
        if(text[j] >= '0' && text[j] <= '9')
        {
            decimalTemp = text[j] - 48;
        }
        else if(text[j] >= 'a' && text[j] <= 'f')
        {
            decimalTemp = text[j] - 97 + 10;
        }
        else if(text[j] >= 'A' && text[j] <= 'F')
        {
            decimalTemp = text[j] - 65 + 10;
        }

        decimal += decimalTemp * pow(16, (sizeTemp - j));
    }
    sizeTemp = -1;
    return decimal;
}

int main(){
    char T1[80] = { "12 FF AC B 11" };
    char charTemp[80] = { "\0" };
    int T2[10];
    int sizeTemp = -1;
    int hex, i, j, k = 0;

    while(T1[i] != '\0'){
        for(i; T1[i] != ' ' && T1[i] != '\0'; i++)
        {
            charTemp[k] = T1[i];
            k++;
            sizeTemp++;
        }
        T2[j] = hexConvert(charTemp, sizeTemp);
        j++;
        i++;
        k = 0;
    }

    for(i = 0; i < j; i++)
    {
        cout << T2[i] << " ";
    }
    return 0;
}
```

## Zadanie 10
Ostatnim zadaniem był napisanie programu podobnego do tego z ćwiczenia 9, jednak tym razem zamiana była systemu dwójkowego na dziesiętny. Posłużyłem się tutaj kodem z poprzedniego zadania, edytując funkcję konwersji liczb.

```C++
#include <iostream>
#include <cmath>

using namespace std;

int binConvert(char* text, int& sizeTemp){
    int j;
    int decimalTemp = 0;
    int decimal = 0;
    for(j = sizeTemp; j >= 0; j--)
    {
        decimal += (text[j] - 48) * pow(2, (sizeTemp - j));
    }
    sizeTemp = -1;
    return decimal;
}

int main(){
    char T1[80] = { "1111 0010 1010 0110" };
    char charTemp[80] = { "\0" };
    int T2[10];
    int sizeTemp = -1;
    int i, j, k = 0;

    while(T1[i] != '\0')
    {
        for(i; T1[i] != ' ' && T1[i] != '\0'; i++)
        {
            charTemp[k] = T1[i];
            k++;
            sizeTemp++;
        }
        T2[j] = binConvert(charTemp, sizeTemp);
        j++;
        i++;
        k = 0;
    }

    for(i = 0; i < j; i++)
    {
        cout << T2[i] << " ";
    }
    return 0;
}
```