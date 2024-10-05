#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ListElement {
public:
	string value;
	ListElement* next;
};

class List {
public:
	char name;
	ListElement* head;
	static List* createList(char _name) {
		List* temp = new List;
		temp->name = _name;
		temp->head = NULL;
		return temp;
	}
	static void addElement(string _value, List* _list) {
		ListElement* temp = new ListElement;
		temp->value = _value;
		temp->next = NULL;
		if (_list->head != NULL) temp->next = _list->head;
		_list->head = temp;
	}
	static void displayElements(List* _list) {
		ListElement* temp = _list->head;
		while (temp != NULL)
		{
			cout << temp->value << "\n";
			temp = temp->next;
		}
	}
	static void deleteElement(string _value, List* _list) {
		ListElement* temp = _list->head;
		ListElement* previous = NULL;
		while (temp->value != _value) {
			previous = temp;
			temp = temp->next;
		}

		if (previous == NULL) _list->head = temp->next;
		else if (temp->next == NULL) previous->next = NULL;
		else previous->next = temp->next;
		delete temp;
	}
	static List* unionLists(List* _A, List* _B, char _resultName) {
		List* newList = List::createList(_resultName);
		newList->head = _A->head;
		ListElement* temp = _A->head;
		while (temp->next != NULL)	temp = temp->next;
		temp->next = _B->head;
		delete _A;
		delete _B;
		return newList;
	}
	static List* intersectionLists(List* _A, List* _B, char _resultName) {
		List* newList = List::createList(_resultName);
		ListElement* tempA = _A->head;
		ListElement* tempB = _B->head;
		do {
			do {
				if (tempA->value == tempB->value) addElement(tempA->value, newList);
				tempB = tempB->next;
			} while (tempB != NULL);
			tempA = tempA->next;
			tempB = _B->head;
		} while (tempA != NULL);

		tempA = _A->head;
		while (tempA != NULL) {
			tempB = tempA->next;
			delete tempA;
			tempA = tempB;
		}
		tempB = _B->head;
		while (tempB != NULL) {
			tempA = tempB->next;
			delete tempB;
			tempB = tempA;
		}
		delete _A;
		delete _B;
		delete tempA;
		delete tempB;
		return newList;
	}
	static List* differenceLists(List* _A, List* _B, char _resultName) {
		List* newList = List::createList(_resultName);
		ListElement* tempA = _A->head;
		ListElement* tempB = _B->head;
		bool isInB = false;
		do {
			do {
				if (tempA->value == tempB->value) isInB = true;
				tempB = tempB->next;
			} while (tempB != NULL);
			if (!isInB) List::addElement(tempA->value, newList);
			isInB = false;
			tempA = tempA->next;
			tempB = _B->head;
		} while (tempA != NULL);

		tempA = _A->head;
		while (tempA != NULL) {
			tempB = tempA->next;
			delete tempA;
			tempA = tempB;
		}
		tempB = _B->head;
		while (tempB != NULL) {
			tempA = tempB->next;
			delete tempB;
			tempB = tempA;
		}
		delete _A;
		delete _B;
		delete tempA;
		delete tempB;
		return newList;
	}
	static bool isSubset(List* _A, List* _B) {
		ListElement* tempA = _A->head;
		ListElement* tempB = _B->head;
		bool isInB = false;
		do {
			do {
				if (tempA->value == tempB->value) isInB = true;
				tempB = tempB->next;
			} while (tempB != NULL);
			if (!isInB) return false;
			isInB = false;
			tempA = tempA->next;
			tempB = _B->head;
		} while (tempA != NULL);

		delete tempA;
		delete tempB;
		return true;
	}
	static bool isImplication(List* _A, List* _B) {
		return List::isSubset(_A, _B);
	}
};

void menu(vector<List*> &lists) {
	system("cls");
	for (int i = 0; i < lists.size(); i++)
	{
		cout << "Zbior " << lists.at(i)->name << "\n";
		if (lists.at(i)->head != NULL) List::displayElements(lists.at(i));
		else cout << "\n";
	}
	if (lists.size() == 0) {
		cout << "Brak zbiorow\n";
	}
	cout << '\n';

	int option;
	int j = 0;
	int k = 0;
	string value;
	char listName;
	List* tempListA;
	List* tempListB;
	string equasion;
	cout << "Wybierz operacje:\n1 - utworz nowy zbior\n2 - Dodaj element do zbioru\n3 - Usun element ze zbioru\n4 - Suma zbiorow\n5 - Iloczyn zbiorow\n6 - Roznica zbiorow\n7 - Sprawdz zawieranie\n8 - Sprawdz wynikanie\n9 - Obliczanie wyrazenia\n";
	cin >> option;
	switch (option)
	{
	case 1:
		system("cls");
		cout << "Podaj nazwe nowego zbioru (duza litera alfabetu): ";
		cin >> listName;
		listName = toupper(listName);
		lists.push_back(List::createList(listName));
		break;
	case 2:
		cout << "Podaj nazwe zbioru na ktorym chcesz operowac: ";
		cin >> listName;
		listName = toupper(listName);
		while (lists.at(j)->name != listName && lists.size() > j)	j++;
		cout << "Podaj wartosc do dodania: ";
		cin >> value;
		List::addElement(value, lists.at(j));
		break;
	case 3:
		cout << "Podaj nazwe zbioru na ktorym chcesz operowac: ";
		cin >> listName;
		listName = toupper(listName);
		while (lists.at(j)->name != listName && lists.size() > j)	j++;
		cout << "Podaj wartosc do usuniecia: ";
		cin >> value;
		List::deleteElement(value, lists.at(j));
		break;
	case 4:
		cout << "Podaj nazwe pierwszego zbioru: ";
		cin >> listName;
		listName = toupper(listName);
		while (lists.at(j)->name != listName && lists.size() > j)	j++;
		tempListA = lists.at(j);
		lists.erase(lists.begin()+j);
		cout << "Podaj nazwe drugiego zbioru: ";
		cin >> listName;
		listName = toupper(listName);
		while (lists.at(j)->name != listName && lists.size() > j)	j++;
		tempListB = lists.at(j);
		lists.erase(lists.begin() + j);
		cout << "Podaj nazwe zbioru wynikowego: ";
		cin >> listName;
		listName = toupper(listName);
		lists.push_back(List::unionLists(tempListA, tempListB, listName));
		break;
	case 5:
		cout << "Podaj nazwe pierwszego zbioru: ";
		cin >> listName;
		listName = toupper(listName);
		while (lists.at(j)->name != listName && lists.size() > j)	j++;
		tempListA = lists.at(j);
		lists.erase(lists.begin() + j);
		cout << "Podaj nazwe drugiego zbioru: ";
		cin >> listName;
		listName = toupper(listName);
		while (lists.at(j)->name != listName && lists.size() > j)	j++;
		tempListB = lists.at(j);
		lists.erase(lists.begin() + j);
		cout << "Podaj nazwe zbioru wynikowego: ";
		cin >> listName;
		listName = toupper(listName);
		lists.push_back(List::intersectionLists(tempListA, tempListB, listName));
		break;
	case 6:
		cout << "Podaj nazwe pierwszego zbioru: ";
		cin >> listName;
		listName = toupper(listName);
		while (lists.at(j)->name != listName && lists.size() > j)	j++;
		tempListA = lists.at(j);
		lists.erase(lists.begin() + j);
		cout << "Podaj nazwe drugiego zbioru: ";
		cin >> listName;
		listName = toupper(listName);
		while (lists.at(j)->name != listName && lists.size() > j)	j++;
		tempListB = lists.at(j);
		lists.erase(lists.begin() + j);
		cout << "Podaj nazwe zbioru wynikowego: ";
		cin >> listName;
		listName = toupper(listName);
		lists.push_back(List::differenceLists(tempListA, tempListB, listName));
		break;
	case 7:
		cout << "Podaj nazwe pierwszego zbioru (czy jest zawarty): ";
		cin >> listName;
		listName = toupper(listName);
		while (lists.at(j)->name != listName && lists.size() > j)	j++;
		tempListA = lists.at(j);
		cout << "Podaj nazwe drugiego zbioru: ";
		cin >> listName;
		listName = toupper(listName);
		while (lists.at(j)->name != listName && lists.size() > j)	j++;
		tempListB = lists.at(j);
		if (List::isSubset(tempListA, tempListB)) {
			cout << "Zbior " << tempListA->name << " jest zawarty w zbiorze " << tempListB->name << ".\n";
		}
		else {
			cout << "Zbior " << tempListA->name << " nie jest zawarty w zbiorze " << tempListB->name << ".\n";
		}
		system("pause");
		break;
	case 8:
		cout << "Podaj nazwe pierwszego zbioru (czy implikuje): ";
		cin >> listName;
		listName = toupper(listName);
		while (lists.at(j)->name != listName && lists.size() > j)	j++;
		tempListA = lists.at(j);
		cout << "Podaj nazwe drugiego zbioru: ";
		cin >> listName;
		listName = toupper(listName);
		while (lists.at(j)->name != listName && lists.size() > j)	j++;
		tempListB = lists.at(j);
		if (List::isImplication(tempListA, tempListB)) {
			cout << "Zbior " << tempListA->name << " implikuje zbior " << tempListB->name << ".\n";
		}
		else {
			cout << "Zbior " << tempListA->name << " nie implikuje zbioru " << tempListB->name << ".\n";
		}
		system("pause");
		break;
	case 9:
		cout << "Podaj wyrazenie (+ suma, - roznica, * iloczyn, > zawieranie, : implikacja) np. A=B+C: ";
		cin >> equasion;
		if (equasion.find('=') != std::string::npos) {
			listName = toupper(equasion.at(equasion.find('=') - 1));
		}
		if (equasion.find('+') != std::string::npos) {
			while (lists.at(j)->name != toupper(equasion.at(equasion.find('+')-1)) && lists.size() > j)	j++;
			tempListA = lists.at(j);
			lists.erase(lists.begin() + j);
			while (lists.at(j)->name != toupper(equasion.at(equasion.find('+')+1)) && lists.size() > j)	j++;
			tempListB = lists.at(j);
			lists.erase(lists.begin() + j);
			lists.push_back(List::unionLists(tempListA, tempListB, listName));
		}
		else if (equasion.find('-') != std::string::npos) {
			while (lists.at(j)->name != toupper(equasion.at(equasion.find('-')-1)) && lists.size() > j)	j++;
			tempListA = lists.at(j);
			lists.erase(lists.begin() + j);
			while (lists.at(j)->name != toupper(equasion.at(equasion.find('-') + 1)) && lists.size() > j)	j++;
			tempListB = lists.at(j);
			lists.erase(lists.begin() + j);
			lists.push_back(List::differenceLists(tempListA, tempListB, listName));
		}
		else if(equasion.find('*') != std::string::npos) {
			while (lists.at(j)->name != toupper(equasion.at(equasion.find('*')-1)) && lists.size() > j)	j++;
			tempListA = lists.at(j);
			lists.erase(lists.begin() + j);
			while (lists.at(j)->name != toupper(equasion.at(equasion.find('*') + 1)) && lists.size() > j)	j++;
			tempListB = lists.at(j);
			lists.erase(lists.begin() + j);
			lists.push_back(List::intersectionLists(tempListA, tempListB, listName));
		}
		else if (equasion.find('>') != std::string::npos) {
			while (lists.at(j)->name != toupper(equasion.at(equasion.find('>') - 1)) && lists.size() > j)	j++;
			tempListA = lists.at(j);
			while (lists.at(j)->name != toupper(equasion.at(equasion.find('>') + 1)) && lists.size() > j)	j++;
			tempListB = lists.at(j);
			if (List::isSubset(tempListA, tempListB)) {
				cout << "Zbior " << tempListA->name << " jest zawarty w zbiorze " << tempListB->name << ".\n";
			}
			else {
				cout << "Zbior " << tempListA->name << " nie jest zawarty w zbiorze " << tempListB->name << ".\n";
			}
		}
		else if (equasion.find(':') != std::string::npos) {
			while (lists.at(j)->name != toupper(equasion.at(equasion.find('=') - 1)) && lists.size() > j)	j++;
			tempListA = lists.at(j);
			while (lists.at(j)->name != toupper(equasion.at(equasion.find('=') + 1)) && lists.size() > j)	j++;
			tempListB = lists.at(j);
			if (List::isSubset(tempListA, tempListB)) {
				cout << "Zbior " << tempListA->name << " implikuje zbior " << tempListB->name << ".\n";
			}
			else {
				cout << "Zbior " << tempListA->name << " nie implikuje zbioru " << tempListB->name << ".\n";
			}
		}
		break;
	default:
		break;
	}
}

int main(){
	vector<List*> lists;
	while(true)	menu(lists);
}