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