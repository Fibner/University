## 1. Opis programu
Program służy do wspomagania zarządzaniem wypożyczalni motocykli. Przechowuje baze
klientów oraz motocykli w plikach binarnych. Dostępne są opcje dodania nowego użytkownika do
bazy, usunięcia użytkownika z bazy, wyświetlenia użytkowników z bazy z możliwością
posortowania, dodania motocyklu do bazy, usunięcia motocyklu z bazy, edycji informacji o
motocyklu w bazie oraz wyświetlenia motocyklów z bazy z możliwością posortowania.

## 2. Przyjęte założenia
Pole imienia i nazwiska klasy klienta może zawierać maksymalnie 50 znaków, w dodatku program
odczytuje tylko jeden wyraz (do momentu wykrycia spacji).
Pole Miasto klasy klienta oraz marka i model klasy motocyklu może zawierać maksymalnie 50
znaków oraz więcej wyrazów niż jedno.
Pole Moc klasy motocyklu jest typu int.
Zakładamy że wszystkie informacje są podane z wielkiej litery dzięki czemu program łatwiej radzi
sobie z sortowaniem względem słów, porównując jedynie kod ASCII poszczególnych liter.

## 3. Pseudokod istotnych algorytmów
addMotorcycle()
1. Pobierz wartosci od uzytkownika o nowym motocyklu i zapisz do zmiennej
2. Wczytaj obiekty motocykl z pliku binarnego do wektora
3. Dodaj do wektora nowo utworzony obiekt przez użytkownika
4. Zapisz wektor do pliku binarnego
<br />
<br />

deleteMotorcycle() 
1. Wczytaj obiekty motocykl z pliku binarnego do wektora
2. Wyświetl użytkownikowi listę motocykli z wektora
3. Zapytaj o numer indeksu motocykla, który użytkownik chce usunąć
4. Pobierz wartość indeksu wektora od użytkownika do zmiennej
5. Usuń obiekt motocykl z wektora o indeksie podannym przez użytkownika
6. Zapisz wektor do pliku binarnego
<br />
<br />

editMotorcycle()
1. Wczytaj obiekty motocykl z pliku binarnego do wektora
2. Wyświetl użytkownikowi listę motocykli z wektora
3. Zapytaj o numer indeksu motocykla, który użytkownik chce edytować
4. Pobierz wartość indeksu wektora od użytkownika do zmiennej
5. Wyświetl atrybuty obiektu motocykl z wektora o indeksie podanym przez użytkownika
6. Zapytaj który atrybut obiektu użytkownik chce edytować
7. Pobierz odpowiadający mu numer od użytkownika
8. Zapytaj użytkownika o nową wartość atrybutu obiektu
9. Pobierz nową wartość atrybutu obiektu od użytkownika
10. Zapisz nową wartość atrybutu obiektu w wektorze, który użytkownik edytował
11. Zapisz wektor do pliku binarnego
<br />
<br />

displayMotorcycles()
1. Wczytaj obiekty motocykl z pliku binarnego do wektora
2. Wyświetl użytkownikowi listę motocykli z wektora
3. Wyświetl dodatkowe opcje sortowania oraz powrotu
4. Pobierz wartość od użytkownika, co chce dalej zrobić<br />
  4a. W przypadku wyboru sortowania<br/>
    &emsp;4aa. Zapytaj użytkownika po jakim atrybucie chce posortować obiekty<br />
    &emsp;4ab. Pobierz wartość od użytkownika z metodą sortowania<br />
    &emsp;4ac. Posortuj obiekty w wektorze po atrybucie wybranym przez użytkownika<br />
    &emsp;4ad. Zapisz wektor do pliku binarnego<br />
    &emsp;4ae. Wywołaj displayMotorcycles()<br />
  4b. W przypadku wyboru powrót<br />
    &emsp;4ba. Wróć do menu
<br />
<br />

addCustomer()
1. Pobierz wartosci od uzytkownika o nowym kliencie i zapisz do zmiennej
2. Wczytaj obiekty klient z pliku binarnego do wektora
3. Dodaj do wektora nowo utworzony obiekt przez użytkownika
4. Zapisz wektor do pliku binarnego
<br />
<br />

deleteCustomer()
1. Wczytaj obiekty klient z pliku binarnego do wektora
2. Wyświetl użytkownikowi listę klientów z wektora
3. Zapytaj o numer indeksu klienta, którego użytkownik chce usunąć
4. Pobierz wartość indeksu wektora od użytkownika do zmiennej
5. Usuń obiekt klient z wektora o indeksie podannym przez użytkownika
6. Zapisz wektor do pliku binarnego
<br />
<br />

displayCustomers()
1. Wczytaj obiekty klient z pliku binarnego do wektora
2. Wyświetl użytkownikowi listę klientów z wektora
3. Wyświetl dodatkowe opcje sortowania oraz powrotu
4. Pobierz wartość od użytkownika, co chce dalej zrobić<br />
  4a. W przypadku wyboru sortowania<br />
    &emsp;4aa. Zapytaj użytkownika po jakim atrybucie chce posortować obiekty<br />
    &emsp;4ab. Pobierz wartość od użytkownika z metodą sortowania<br />
    &emsp;4ac. Posortuj obiekty w wektorze po atrybucie wybranym przez użytkownika<br />
    &emsp;4ad. Zapisz wektor do pliku binarnego<br />
    &emsp;4ae. Wywołaj displayCustomers()<br />
  4b. W przypadku wyboru powrót<br />
    &emsp;4ba. Wróć do menu

## 4. Opis istotnych struktur danych
<table>
<tr>
<td style="text-align: center">class</br><b>Motorcycle</b></td>
<td style="text-align: center; width: 10px;"></td>
<td style="text-align: center">class</br><b>Customer</b></td>
</tr>
<tr>
<td style="text-align: left">+char brand[50]</br>+char model[50]</br>+int power</td>
<td style="text-align: center; width: 10px;"></td>
<td style="text-align: left">+char name[50]</br>+char surname[50]</br>+char address[50]</td>
</tr>
<td style="text-align: left">+addMotorcycle()</br>+deleteMotorcycle()</br>+editMotorcycle()</br>+displayMotorcycle()</td>
<td style="text-align: center; width: 10px;"></td>
<td style="text-align: left">+addCustomer()</br>+deleteCustomer()</br>+displayMotorcycle()</td>
</table>

<br>

Klasa Motorcycle:
- Pole brand do przechowywania marki motocykla
- Pole model do przechowywania modelu motocykla
- Pole power do przechowywania mocy motocykla

<br>

Klasa Customer:
- Pole name do przechowywania imienia
- Pole surname do przechowywania nazwiska
- pole addres do przechowywania adresu

## 5. Rozmieszczenie danych w pliku
Dane zostały rozmieszczone pomiędzy dwa pliki binarne. Plik customers przechowywuje obiekty
klientów utworzonych z klasy Customer. Natomiast plik motorcycles przechowywuje obiekty
motocykli utworzonych z klasy Motorcycle.