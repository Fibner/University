## 1. Opis programu
Program umożliwia obliczanie operacji na zbiorach, gdzie elementami zbiorów są łańcuchy
znaków. Program jest w stanie zdefiniować dowolną liczbę zbiorów. Istnieje możliwość dodania,
wyświetlenia oraz usunięcia elementów ze zbiorów. Na zbiorach dostępne są również operacje
sumy, iloczynu, różnicy, zawierania oraz wynikania.

## 2. Przyjęte założenia
Lista jest reprezentowana za pomocą struktury dwukierunkowej, gdzie każdy element zawiera
wartość (string) oraz wskaźnik na następny element. Lista jest reprezentowana za pomocą
struktury dwukierunkowej, gdzie każdy element zawiera wartość (string) oraz wskaźnik na
następny element.

## 3. Pseudokod istotnych algorytmów
createList ()
1. Utwórz nową instancję List i przypisz ją do zmiennej temp
2. Ustaw pole name obiektu temp na wartość _name
3. Ustaw pole head obiektu temp na NULL
4. Zwróć obiekt temp
<br />
<br />

addElement ()
1. Utwórz nowy element listy.
2. Przypisz wartość elementu.
3. Ustaw wskaźnik na następny element jako NULL.
4. Jeśli lista nie jest pusta, ustaw wskaźnik na obecny pierwszy element.
5. Ustaw nowy element jako głowę listy.
<br />
<br />

displayElements ()
1. Ustaw wskaźnik na pierwszy element listy.
2. Dopóki wskaźnik nie jest NULL:<br/>
 a. Wypisz wartość elementu. <br/>
 b. Przesuń wskaźnik na następny element.
<br />
<br />

deleteElement ()
1. Ustaw wskaźnik na pierwszy element listy.
2. Ustaw wskaźnik na poprzedni element jako NULL.
3. Przeszukuj listę, dopóki wartość elementu nie będzie równa szukanej wartości:<br/>
 a. Przypisz obecny element jako poprzedni.<br/>
 b. Przesuń wskaźnik na następny element.
4. Jeśli poprzedni element jest NULL, ustaw pierwszy element listy na następny element.
5. W przeciwnym razie, jeśli następny element jest NULL, ustaw wskaźnik poprzedniego elementu
na NULL.
6. W przeciwnym razie, ustaw wskaźnik poprzedniego elementu na następny element obecnego
elementu.
7. Usuń obecny element.
<br />
<br />

unionLists ()
1. Utwórz nową listę o nazwie wynikowej.
2. Ustaw pierwszy element nowej listy na pierwszy element listy A.
3. Ustaw wskaźnik na pierwszy element listy A.
4. Przeszukuj listę A, dopóki nie dojdziesz do ostatniego elementu.
5. Ustaw wskaźnik następnego elementu ostatniego elementu listy A na pierwszy element listy B.
6. Usuń listę A.
7. Usuń listę B.
8. Zwróć nową listę.
<br />
<br />

intersectionLists ()
1. Utwórz nową listę o nazwie wynikowej.
2. Ustaw wskaźnik na pierwszy element listy A.
3. Ustaw wskaźnik na pierwszy element listy B.
4. Dla każdego elementu w liście A:<br/>
 a. Dla każdego elementu w liście B:<br/>
 &emsp;i. Jeśli wartości elementów są równe, dodaj wartość elementu A do nowej listy.<br/>
 &emsp;ii. Przesuń wskaźnik na następny element listy B.<br/>
 b. Przesuń wskaźnik na następny element listy A.<br/>
 c. Ustaw wskaźnik na pierwszy element listy B.
5. Usuń wszystkie elementy listy A.
6. Usuń wszystkie elementy listy B.
7. Usuń listę A.
8. Usuń listę B.
9. Zwróć nową listę.
<br />
<br />

differenceLists ()
1. Utwórz nową listę o nazwie wynikowej.
2. Ustaw wskaźnik na pierwszy element listy A.
3. Ustaw wskaźnik na pierwszy element listy B.
4. Ustaw flagę isInB na false.
5. Dla każdego elementu w liście A:<br/>
 a. Dla każdego elementu w liście B:<br/>
 &emsp;i. Jeśli wartości elementów A i B są równe, ustaw isInB na true.<br/>
 &emsp;ii. Przesuń wskaźnik na następny element listy B.<br/>
 b. Jeśli isInB jest false, dodaj wartość elementu A do nowej listy.<br/>
 c. Zresetuj flagę isInB na false.<br/>
 d. Przesuń wskaźnik na następny element listy A.<br/>
 e. Ustaw wskaźnik na pierwszy element listy B.
6. Usuń wszystkie elementy listy A.
7. Usuń wszystkie elementy listy B.
8. Usuń listę A.
9. Usuń listę B.
10. Zwróć nową listę.
<br/>
<br/>

isSubset ()
1. Ustaw wskaźnik na pierwszy element listy A.
2. Ustaw wskaźnik na pierwszy element listy B.
3. Ustaw flagę isInB na false.
4. Dla każdego elementu w liście A:<br/>
 a. Dla każdego elementu w liście B:<br/>
 &emsp;i. Jeśli wartości elementów A i B są równe, ustaw isInB na true.<br/>
 &emsp;ii. Przesuń wskaźnik na następny element listy B.<br/>
 b. Jeśli isInB jest false, zwróć false.<br/>
 c. Zresetuj flagę isInB na false.<br/>
 d. Przesuń wskaźnik na następny element listy A.<br/>
 e. Ustaw wskaźnik na pierwszy element listy B.
5. Usuń wskaźnik na element listy A.
6. Usuń wskaźnik na element listy B.
7. Zwróć true

## 4. Opis istotnych struktur danych
<table>
<tr>
<td style="text-align: center">class</br><b>List</b></td>
<td style="text-align: center; width: 10px;"></td>
<td style="text-align: center">class</br><b>ListElement&emsp;</b></td>
</tr>
<tr>
<td style="text-align: left">+Name: string</br>+Head: ListElement*</td>
<td style="text-align: center; width: 10px;"></td>
<td style="text-align: left">+Value: string</br>+Next: ListElement*</td>
</tr>
<td style="text-align: left">+createList()</br>+addElement()</br>+displayElements()</br>+deleteElement()</br>+unionLists()<br/>+intersectionLists()<br/>+differenceLists()<br/>+isSubset()<br/>+isImplication()</td>
<td style="text-align: center; width: 10px;"></td>
<td style="text-align: left"></td>
</table>

<br>

Klasa List:
- Pole Name do przechowywania nazwy listy
- Pole Head do przechowywania adresu pierwszego elementu listy

<br>

Klasa ListElement
- Pole Value do przechowywania wartości
- Pole Next do przechowywania adresu następnego elementu listy