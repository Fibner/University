## Zadanie 1
Pierwszym zadaniem było utworzenie struktury listy. Posiada ona wartość oraz wskaźnik na następny obiekt. Dodatkowo funkcja Display wyświetla całą listę, a funkcja Insert „dodaje” obiekt do listy.

```C++
#include <iostream>

using namespace std;

struct List {
	int key;
	List* next;
};

List* Insert(List* head, int key) {
	List* p;
	p = new List;

	p->key = key;
	p->next = head;
	return p;
};

void Display(List* head) {
	List* p;
	p = head;
	while (p != NULL)
	{
		cout << p->key << endl;
		p = p->next;
	}
}
int main() {
	List* head = NULL;
	head = Insert(head, 1);
	head = Insert(head, 2);
	head = Insert(head, 3);
	head = Insert(head, 4);
	head = Insert(head, 5);
	Display(head);
}
```

## Zadanie 2
Kolejne zadanie polegało na dodaniu funkcji, która przeszukuje listę w celu znaleźenia konretnej wartości.

```C++
#include <iostream>

using namespace std;

struct List {
	int key;
	List* next;
};

List* Insert(List* head, int key) {
	List* p;
	p = new List;

	p->key = key;
	p->next = head;
	return p;
};

void Display(List* head) {
	List* p;
	p = head;
	while (p != NULL)
	{
		cout << p->key << endl;
		p = p->next;
	}
}

bool LookFor(List* head, int key) {
	List* p;
	p = head;
	while (p != NULL)
	{
		if (p->key == key) {
			cout << "Wartosc " << key << " znajduje sie w liscie." << endl;
			return true;
		}
		p = p->next;
	}
	cout << "Brak wartosci " << key << " w liscie." << endl;
	return false;
}

int main() {
	List* head = NULL;
	head = Insert(head, 1);
	head = Insert(head, 2);
	head = Insert(head, 3);
	head = Insert(head, 4);
	head = Insert(head, 5);
	Display(head);
	LookFor(head, 3);
	LookFor(head, 8);
}
```

## Zadanie 3
Trzecim zadaniem było dodanie funkcji, która dodaje nowy element na końcu listy. Oznacza to, że trzeba przejść po całej liście, aby dostać się do elementu, który wszedł na samym początku.

```C++
#include <iostream>

using namespace std;

struct List {
	int key;
	List* next;
};

List* Insert(List* head, int key) {
	List* p;
	p = new List;

	p->key = key;
	p->next = head;
	return p;
};

void InsertEnd(List* head, int key) {
	List* p;
	p = head;

	while (p->next != NULL)
	{
		p = p->next;
	}

	p->next = new List;
	p = p->next;
	p->key = key;
	p->next = NULL;
}

void Display(List* head) {
	List* p;
	p = head;
	while (p != NULL)
	{
		cout << p->key << endl;
		p = p->next;
	}
}

bool LookFor(List* head, int key) {
	List* p;
	p = head;
	while (p != NULL)
	{
		if (p->key == key) {
			cout << "Wartosc " << key << " znajduje sie w liscie." << endl;
			return true;
		}
		p = p->next;
	}
	cout << "Brak wartosci " << key << " w liscie." << endl;
	return false;
}

int main() {
	List* head = NULL;
	head = Insert(head, 1);
	head = Insert(head, 2);
	head = Insert(head, 3);
	head = Insert(head, 4);
	head = Insert(head, 5);
	LookFor(head, 3);
	LookFor(head, 8);
	InsertEnd(head, 0);
	Display(head);
}
```

## Zadanie 4
Następne zadanie polegało na stworzeniu funkcji, która usuwa element o podanej wartości z listy. Dodatkową uwagę trzeba zwrócić na element pierwszy i ostatni.

```C++
#include <iostream>

using namespace std;

struct List {
	int key;
	List* next;
};

List* Insert(List* head, int key) {
	List* p;
	p = new List;

	p->key = key;
	p->next = head;
	return p;
};

void InsertEnd(List* head, int key) {
	List* p;
	p = head;

	while (p->next != NULL)
	{
		p = p->next;
	}

	p->next = new List;
	p = p->next;
	p->key = key;
	p->next = NULL;
}

void Display(List* head) {
	List* p;
	p = head;
	while (p != NULL)
	{
		cout << p->key << endl;
		p = p->next;
	}
}

bool LookFor(List* head, int key) {
	List* p;
	p = head;
	while (p != NULL)
	{
		if (p->key == key) {
			cout << "Wartosc " << key << " znajduje sie w liscie." << endl;
			return true;
		}
		p = p->next;
	}
	cout << "Brak wartosci " << key << " w liscie." << endl;
	return false;
}

List* Delete(List* head, int key) {
	List* p;
	List* previous;
	p = head;
	previous = NULL;

	while (p->key != key) {
		previous = p;
		p = p->next;
	}

	if (previous == NULL) head = p->next;
	else if (p->next == NULL) previous->next = NULL;
	else previous->next = p->next;

	delete p;
	return head;
}

int main() {
	List* head = NULL;
	head = Insert(head, 1);
	head = Insert(head, 2);
	head = Insert(head, 3);
	head = Insert(head, 4);
	head = Insert(head, 5);
	LookFor(head, 3);
	LookFor(head, 8);
	InsertEnd(head, 0);
	Display(head);
	head = Delete(head, 3);
	Display(head);
}
```

## Zadanie 5 - Lista dwukierunkowa
Celem zadania było przekształcenie listy z poprzednich zadań na dwukierunkową. Wszystkie funkcje zostały do tego również dopasowane.

```C++
#include <iostream>

using namespace std;

struct List {
	int key;
	List* next;
	List* previous;
};

List* Insert(List* head, int key) {
	List* p;
	p = new List;

	p->key = key;
	p->next = head;
	p->previous = NULL;
	if (head != NULL) head->previous = p;
	return p;
};

void InsertEnd(List* head, int key) {
	List* p;
	List* previous;
	p = head;

	while (p->next != NULL)
	{
		p = p->next;
	}

	p->next = new List;
	p->next->previous = p;
	p = p->next;
	p->key = key;
	p->next = NULL;
}

void Display(List* head) {
	List* p;
	p = head;
	while (p != NULL)
	{
		cout << p->key << endl;
		p = p->next;
	}
}

bool LookFor(List* head, int key) {
	List* p;
	p = head;
	while (p != NULL)
	{
		if (p->key == key) {
			cout << "Wartosc " << key << " znajduje sie w liscie." << endl;
			return true;
		}
		p = p->next;
	}
	cout << "Brak wartosci " << key << " w liscie." << endl;
	return false;
}

List* Delete(List* head, int key) {
	List* p;
	p = head;

	while (p->key != key) {
		p = p->next;
	}

	if (p->previous == NULL) {
		head = p->next;
		head->previous = NULL;
	}
	else if (p->next == NULL) {
		p->previous->next = NULL;
	}
	else {
		p->previous->next = p->next;
		p->next->previous = p->previous;
	}

	delete p;
	return head;
}

int main() {
	List* head = NULL;
	head = Insert(head, 1);
	head = Insert(head, 2);
	head = Insert(head, 3);
	head = Insert(head, 4);
	head = Insert(head, 5);
	LookFor(head, 3);
	LookFor(head, 8);
	InsertEnd(head, 0);
	Display(head);
	cout << '\n';
	head = Delete(head, 1);
	Display(head);
}
```

## Zadanie 6 - Lista cykliczna
Ostatnim zadaniem było utworzenie listy cyklicznej. Postanowiłem stworzyć listę cykliczną jednokierunkową. Wykorzystałem listę z poprzednich zadań, oraz przekształciłem odpowiednio funkcje.

```C++
#include <iostream>

using namespace std;

struct List {
	int key;
	List* next;
};

List* Insert(List* head, int key) {
	List* p;
	p = new List;

	p->key = key;
	if (head == NULL) p->next = p;
	else {
		p->next = head->next;
		head->next = p;
	}
	return p;
};

void Display(List* head) {
	List* p;
	p = head;
	do {
		cout << p->key << endl;
		p = p->next;
	} while (p != head);
}

bool LookFor(List* head, int key) {
	List* p;
	p = head;
	do {
		if (p->key == key) {
			cout << "Wartosc " << key << " znajduje sie w liscie." << endl;
			return true;
		}
		p = p->next;
	} while (p != head);
	cout << "Brak wartosci " << key << " w liscie." << endl;
	return false;
}

List* Delete(List* head, int key) {
	List* p;
	List* prev;
	p = head;
	prev = NULL;
	while (p->key != key) {
		prev = p;
		p = p->next;
	}

	if (prev == NULL && p == head) {

		if (p->next == p) {
			delete p;
			return NULL;
		}

		p = p->next;
		while (p != head) {
			prev = p;
			p = p->next;
		}
		head = prev;
	}

	prev->next = p->next;
	delete p;
	return head;
}

int main() {
	List* head = NULL;
	head = Insert(head, 1);
	head = Delete(head, 1);
	head = Insert(head, 2);
	head = Insert(head, 3);
	head = Insert(head, 4);
	head = Insert(head, 5);
	LookFor(head, 3);
	LookFor(head, 8);
	Display(head);
	cout << '\n';
	head = Delete(head, 5);
	Display(head);
}
```