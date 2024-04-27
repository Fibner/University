## Zadanie 1
Operacja wyszukiwania, wstawiania, znajdowania maksymalnego i minimalnego elementu, usuwania na drzewie binarnym (rekurencyjnie)

```C++
#include <iostream>

using namespace std;

struct Drzewo {
	int Key;
	Drzewo* Left;
	Drzewo* Right;
	Drzewo* Parent;
};

bool Search(Drzewo* head, int key) {
	if (head != NULL) {
		if (key > head->Key) {
			return(Search(head->Right, key));
		}
		else
		{
			if (key < head->Key) return(Search(head->Left, key));
			else
				if (key == head->Key) return true;
		}
	}
	return false;
}

Drzewo* Insert(Drzewo* head, int key) {

	if (head != NULL) {

		if (key > head->Key) {
			head->Right = (Insert(head->Right, key));
			head->Right->Parent = head;
		}
		else
			if (key <= head->Key) {
				head->Left = Insert(head->Left, key);
				head->Left->Parent = head;
			}
		return(head);

	}
	else {
		Drzewo* p;

		p = new Drzewo[1];
		p->Left = NULL;
		p->Right = NULL;
		p->Parent = NULL;
		p->Key = key;

		head = p;

		return(head);

	}
}

void Display(Drzewo* head) {
	Drzewo* p;
	p = head;
	if (p != NULL) {
		Display(p->Left);
		cout << "\n " << p->Key;
		Display(p->Right);

	}
};

int FindTheBiggest(Drzewo* head) {
	Drzewo* p = head;
	if (p->Right != NULL) {
		p = p->Right;
		return FindTheBiggest(p);
	}
	else return p->Key;
}

int FindTheSmallest(Drzewo* head) {
	Drzewo* p = head;
	if (p->Left != NULL) {
		p = p->Left;
		return FindTheSmallest(p);
	}
	else return p->Key;
}

void Delete(Drzewo* head, int key) {
	if (key > head->Key) {
		return(Delete(head->Right, key));
	}
	else
	{
		if (key < head->Key) return(Delete(head->Left, key));
		else
			if (key == head->Key) {
				if (head->Right == NULL && head->Left == NULL){
					if (head->Key > head->Parent->Key) head->Parent->Right = NULL;
					else head->Parent->Left = NULL;
				}
				else if (head->Right == NULL || head->Left == NULL) {
					if (head->Right != NULL) {
						if (head->Parent->Key < head->Key)	head->Parent->Right = head->Right;
						else head->Parent->Left = head->Right;
						head->Right->Parent = head->Parent;
					}
					else{
						if (head->Parent->Key < head->Key)	head->Parent->Right = head->Left;
						else head->Parent->Left = head->Left;
						head->Left->Parent = head->Parent;
					}
				}
				else if (head->Right != NULL && head->Left != NULL) {
					Drzewo* temp = head->Left;
					while (temp->Right != NULL)	temp = temp->Right;
					temp->Parent->Right = NULL;
					if (head->Parent->Key < head->Key)	head->Parent->Right = temp;
					else head->Parent->Left = temp;
					temp->Parent = head->Parent;
					temp->Right = head->Right;
					temp->Left = head->Left;
				}
				delete head;
			}
	}
}

int main()
{
	Drzewo* head = NULL;

	head = Insert(head, 10);
	head = Insert(head, 2);
	head = Insert(head, 1);
	head = Insert(head, 15);
	Display(head);
	Delete(head, 2);
	cout << "\n";
	cout << "\n Liczba 10? " << Search(head, 10);
	cout << "\n Liczba 2? " << Search(head, 2);
	cout << "\n Liczba 1? " << Search(head, 1);
	cout << "\n Liczba 15? " << Search(head, 15);
	cout << "\n Liczba 16? " << Search(head, 16);
	cout << "\n";

	cout << "\n";
	cout << "Najwiekszy element to " << FindTheBiggest(head);
	cout << "\n";
	cout << "Najmniejszy element to " << FindTheSmallest(head);
	cout << "\n";


}
```

## Zadanie 2
Operacja wyszukiwania, wstawiania, znajdowania maksymalnego i minimalnego elementu, usuwania na drzewie binarnym (iteracyjnie)

```C++
#include <iostream>

using namespace std;

struct Drzewo {
	int Key;
	Drzewo* Left;
	Drzewo* Right;
	Drzewo* Parent;
};

bool Search(Drzewo* head, int key) {
	while (head != NULL) {
		if (key > head->Key) {
			head = head->Right;
		}
		else if (key < head->Key) {
			head = head->Left;
		}
		else {
			return true;
		}
	}
	return false;
}

Drzewo* Insert(Drzewo* head, int key) {
	Drzewo* p;
	p = new Drzewo[1];
	p->Left = NULL;
	p->Right = NULL;
	p->Parent = NULL;
	p->Key = key;

	if (head == NULL) {
		head = p;
		return head;
	}
	else {
		Drzewo* temp = head;
		Drzewo* prev = NULL;
		while (temp != NULL) {
			prev = temp;
			if (key > temp->Key) {
				temp = temp->Right;
			}
			else {
				temp = temp->Left;
			}
		}

		if (key > prev->Key) {
			prev->Right = p;
		}
		else {
			prev->Left = p;
		}

		p->Parent = prev;

		return head;
	}
}

void Display(Drzewo* head) {
	Drzewo* p = head;
	Drzewo* temp = NULL;

	while (p != NULL) {
		if (p->Left == NULL) {
			cout << "\n " << p->Key;
			p = p->Right;
		}
		else {
			temp = p->Left;
			while (temp->Right != NULL && temp->Right != p) {
				temp = temp->Right;
			}

			if (temp->Right == NULL) {
				temp->Right = p;
				p = p->Left;
			}
			else {
				temp->Right = NULL;
				cout << "\n " << p->Key;
				p = p->Right;
			}
		}
	}
}

int FindTheBiggest(Drzewo* head) {
	Drzewo* p = head;
	while (p->Right != NULL) {
		p = p->Right;
	}
	return p->Key;
}

int FindTheSmallest(Drzewo* head) {
	Drzewo* p = head;
	while (p->Left != NULL) {
		p = p->Left;
	}
	return p->Key;
}

void Delete(Drzewo* head, int key) {
	while (head->Key != key)
	{
		if (key > head->Key) head = head->Right;
		else head = head->Left;
	}

	if (head->Right == NULL && head->Left == NULL) {
		if (head->Key > head->Parent->Key) head->Parent->Right = NULL;
		else head->Parent->Left = NULL;
	}
	else if (head->Right == NULL || head->Left == NULL) {
		if (head->Right != NULL) {
			if (head->Parent->Key < head->Key)	head->Parent->Right = head->Right;
			else head->Parent->Left = head->Right;
			head->Right->Parent = head->Parent;
		}
		else {
			if (head->Parent->Key < head->Key)	head->Parent->Right = head->Left;
			else head->Parent->Left = head->Left;
			head->Left->Parent = head->Parent;
		}
	}
	else if (head->Right != NULL && head->Left != NULL) {
		Drzewo* temp = head->Left;
		while (temp->Right != NULL)	temp = temp->Right;
		temp->Parent->Right = NULL;
		if (head->Parent->Key < head->Key)	head->Parent->Right = temp;
		else head->Parent->Left = temp;
		temp->Parent = head->Parent;
		temp->Right = head->Right;
		temp->Left = head->Left;
	}
	delete head;
}

int main()
{
	Drzewo* head = NULL;

	head = Insert(head, 10);
	head = Insert(head, 2);
	head = Insert(head, 1);
	head = Insert(head, 15);
	Display(head);
	Delete(head, 1);
	cout << "\n";
	cout << "\n Liczba 10? " << Search(head, 10);
	cout << "\n Liczba 2? " << Search(head, 2);
	cout << "\n Liczba 1? " << Search(head, 1);
	cout << "\n Liczba 15? " << Search(head, 15);
	cout << "\n Liczba 16? " << Search(head, 16);
	cout << "\n";

	cout << "\n";
	cout << "Najwiekszy element to " << FindTheBiggest(head);
	cout << "\n";
	cout << "Najmniejszy element to " << FindTheSmallest(head);
	cout << "\n";
}
```