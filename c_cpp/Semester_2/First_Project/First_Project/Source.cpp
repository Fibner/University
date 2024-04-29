#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class Motorcycle {
public:
	char brand[50];
	char model[50];
	int power;
	void static addMotorcycle() {
		system("cls");
		Motorcycle tempMotorcycle;
		cout << "Podaj marke: ";
		cin.ignore();
		cin.getline(tempMotorcycle.brand, 50);
		cout << "Podaj model: ";
		cin.getline(tempMotorcycle.model, 50);
		cout << "Podaj moc: ";
		cin >> tempMotorcycle.power;

		vector<Motorcycle> motorcycles;

		ifstream fileIn;
		fileIn.open("motorcycles", ios::binary | ios::in);
		Motorcycle tempReadMotorcycle;
		while (fileIn.read((char*)&tempReadMotorcycle, sizeof(Motorcycle)))
		{
			motorcycles.push_back(tempReadMotorcycle);
		}
		fileIn.close();

		motorcycles.push_back(tempMotorcycle);
		ofstream outFile;
		outFile.open("motorcycles", ios::binary | ios::out);
		for (int i = 0; i < motorcycles.size(); i++)
		{
			outFile.write((char*)&motorcycles.at(i), sizeof(Motorcycle));
		}
		outFile.close();

		cout << "\nNowy motocykl zostal dodany do bazy.\n";
		system("pause");
	};
	void static deleteMotorcycle() {
		vector<Motorcycle> motorcycles;
		ifstream fileIn;

		fileIn.open("motorcycles", ios::binary | ios::in);
		Motorcycle tempMotorcycle;
		while (fileIn.read((char*)&tempMotorcycle, sizeof(Motorcycle)))
		{
			motorcycles.push_back(tempMotorcycle);
		}
		fileIn.close();

		system("cls");
		for (int i = 0; i < motorcycles.size(); i++)
		{
			cout << "Motocykl " << i + 1 << "\n";
			cout << "Marka: " << motorcycles.at(i).brand << "\n";
			cout << "Model: " << motorcycles.at(i).model << "\n";
			cout << "Moc: " << motorcycles.at(i).power << "\n\n";
		}
		if (motorcycles.size() == 0) {
			cout << "Brak motocykli do usuniecia.\n\n";
			system("pause");
			return;
		}


		int deleteId = 0;
		cout << "Podaj numer motocyklu do usuniecia: ";
		cin >> deleteId;
		motorcycles.erase(motorcycles.begin() + deleteId - 1);

		ofstream fileOut;
		fileOut.open("motorcycles", ios::binary | ios::out);
		for (int i = 0; i < motorcycles.size(); i++)
		{
			fileOut.write((char*)&motorcycles.at(i), sizeof(Motorcycle));
		}
		fileOut.close();

		system("cls");
		cout << "Motocykl zostal usuniety z bazy.\n\n";
		system("pause");
	};
	void static editMotorcycle() {
		vector<Motorcycle> motorcycles;
		ifstream fileIn;

		fileIn.open("motorcycles", ios::binary | ios::in);
		Motorcycle tempMotorcycle;
		while (fileIn.read((char*)&tempMotorcycle, sizeof(Motorcycle)))
		{
			motorcycles.push_back(tempMotorcycle);
		}
		fileIn.close();

		system("cls");
		for (int i = 0; i < motorcycles.size(); i++)
		{
			cout << "Motocykl " << i + 1 << "\n";
			cout << "Marka: " << motorcycles.at(i).brand << "\n";
			cout << "Model: " << motorcycles.at(i).model << "\n";
			cout << "Moc: " << motorcycles.at(i).power << "\n\n";
		}
		if (motorcycles.size() == 0) {
			cout << "Brak motocykli do edycji.\n\n";
			system("pause");
			return;
		}

		int editId = 0;
		int editAttribute;
		cout << "Podaj numer motocyklu do edycji: ";
		cin >> editId;
		system("cls");
		cout << "1. Marka: " << motorcycles.at(editId - 1).brand << "\n";
		cout << "2. Model: " << motorcycles.at(editId - 1).model << "\n";
		cout << "3. Moc: " << motorcycles.at(editId - 1).power << "\n\n";
		cout << "Ktory atrybut chcesz zedytowac: ";
		cin >> editAttribute;
		system("cls");
		cout << "Podaj nowa wartosc: ";
		switch (editAttribute)
		{
		case 1:
			cin.ignore();
			cin.getline(motorcycles.at(editId - 1).brand, 50);
			break;
		case 2:
			cin.ignore();
			cin.getline(motorcycles.at(editId - 1).model, 50);
			break;
		case 3:
			cin >> motorcycles.at(editId - 1).power;
			break;
		default:
			break;
		}

		ofstream fileOut;
		fileOut.open("motorcycles", ios::binary | ios::out);
		for (int i = 0; i < motorcycles.size(); i++)
		{
			fileOut.write((char*)&motorcycles.at(i), sizeof(Motorcycle));
		}
		fileOut.close();

		system("cls");
		cout << "Motocykl zostal zedytowany.\n\n";
		system("pause");
	};
	void static displayMotorcycles() {
		vector<Motorcycle> motorcycles;
		ifstream fileIn;

		fileIn.open("motorcycles", ios::binary | ios::in);
		Motorcycle tempMotorcycle;
		while (fileIn.read((char*)&tempMotorcycle, sizeof(Motorcycle)))
		{
			motorcycles.push_back(tempMotorcycle);
		}
		fileIn.close();

		system("cls");
		for (int i = 0; i < motorcycles.size(); i++)
		{
			cout << "Motocykl " << i + 1 << "\n";
			cout << "Marka: " << motorcycles.at(i).brand << "\n";
			cout << "Model: " << motorcycles.at(i).model << "\n";
			cout << "Moc: " << motorcycles.at(i).power << "\n\n";
		}
		if (motorcycles.size() == 0) {
			cout << "Brak motocykli w bazie.\n\n";
			system("pause");
		}

		int selectedAction;
		cout << "Opcje:\n";
		cout << "0 - Powrot\n";
		cout << "1 - Sortuj po marce\n";
		cout << "2 - Sortuj po modelu\n";
		cout << "3 - Sortuj po mocy\n";
		cin >> selectedAction;
		switch (selectedAction)
		{
		case 0:
			return;
			break;
		case 1:
			sort(motorcycles.begin(), motorcycles.end(), [](Motorcycle m1, Motorcycle m2) {return (string(m1.brand) < string(m2.brand)); });
			break;
		case 2:
			sort(motorcycles.begin(), motorcycles.end(), [](Motorcycle m1, Motorcycle m2) {return (string(m1.model) < string(m2.model)); });
			break;
		case 3:
			sort(motorcycles.begin(), motorcycles.end(), [](Motorcycle m1, Motorcycle m2) {return (m1.power < m2.power); });
			break;
		default:
			break;
		}
		ofstream fileOut;
		fileOut.open("motorcycles", ios::binary | ios::out);
		for (int i = 0; i < motorcycles.size(); i++)
		{
			fileOut.write((char*)&motorcycles.at(i), sizeof(Motorcycle));
		}
		fileOut.close();

		return Motorcycle::displayMotorcycles();
	};
};

class Customer {
public:
	char name[50];
	char surname[50];
	char addres[50];
	void static addCustomer() {
		Customer tempCustomer{ "", "", "" };
		vector<Customer> customers;

		ifstream fileIn;
		fileIn.open("customers", ios::binary | ios::in);
		while (fileIn.read((char*)&tempCustomer, sizeof(Customer)))
		{
			customers.push_back(tempCustomer);
		}
		fileIn.close();

		system("cls");
		cout << "Podaj imie: ";
		cin >> tempCustomer.name;
		cout << "Podaj nazwisko: ";
		cin >> tempCustomer.surname;
		cout << "Podaj adres: ";
		cin.ignore();
		cin.getline(tempCustomer.addres, 50);
		customers.push_back(tempCustomer);

		ofstream fileOut;
		fileOut.open("customers", ios::binary | ios::out);
		for (int i = 0; i < customers.size(); i++)
		{
			fileOut.write((char*)&customers.at(i), sizeof(Customer));
		}
		fileOut.close();

		cout << "\nNowy klient zostal dodany do bazy.\n";
		system("pause");
	}
	void static deleteCustomer() {
		vector<Customer> customers;
		ifstream fileIn;

		fileIn.open("customers", ios::binary | ios::in);
		Customer tempCustomer;
		while (fileIn.read((char*)&tempCustomer, sizeof(Customer)))
		{
			customers.push_back(tempCustomer);
		}
		fileIn.close();

		system("cls");
		for (int i = 0; i < customers.size(); i++)
		{
			cout << "Klient " << i + 1 << "\n";
			cout << "Imie: " << customers.at(i).name << "\n";
			cout << "Nazwisko: " << customers.at(i).surname << "\n";
			cout << "Adres: " << customers.at(i).addres << "\n\n";
		}
		if (customers.size() == 0) {
			cout << "Brak klientow do usuniecia.\n\n";
			system("pause");
			return;
		}

		int deleteId = 0;
		cout << "Podaj numer klienta do usuniecia: ";
		cin >> deleteId;
		customers.erase(customers.begin() + deleteId - 1);

		ofstream fileOut;
		fileOut.open("customers", ios::binary | ios::out);
		for (int i = 0; i < customers.size(); i++)
		{
			fileOut.write((char*)&customers.at(i), sizeof(Customer));
		}
		fileOut.close();

		system("cls");
		cout << "Klient zostal usuniety z bazy.\n\n";
		system("pause");
	};
	void static displayCustomers() {

		vector<Customer> customers;
		ifstream fileIn;

		fileIn.open("customers", ios::binary | ios::in);
		Customer tempCustomer;
		while (fileIn.read((char*)&tempCustomer, sizeof(Customer)))
		{
			customers.push_back(tempCustomer);
		}
		fileIn.close();

		system("cls");
		for (int i = 0; i < customers.size(); i++)
		{
			cout << "Klient " << i + 1 << "\n";
			cout << "Imie: " << customers.at(i).name << "\n";
			cout << "Nazwisko: " << customers.at(i).surname << "\n";
			cout << "Adres: " << customers.at(i).addres << "\n\n";
		}
		if (customers.size() == 0) {
			cout << "Brak klientow w bazie.\n\n";
			system("pause");
		}

		int selectedAction;
		cout << "-----\nOpcje:\n";
		cout << "0 - Powrot\n";
		cout << "1 - Sortuj po imieniu\n";
		cout << "2 - Sortuj po nazwisku\n";
		cout << "3 - Sortuj po adresie\n";
		cin >> selectedAction;
		switch (selectedAction)
		{
		case 0:
			return;
			break;
		case 1:
			sort(customers.begin(), customers.end(), [](Customer c1, Customer c2) {return (string(c1.name) < string(c2.name)); });
			break;
		case 2:
			sort(customers.begin(), customers.end(), [](Customer c1, Customer c2) {return (string(c1.surname) < string(c2.surname)); });
			break;
		case 3:
			sort(customers.begin(), customers.end(), [](Customer c1, Customer c2) {return (string(c1.addres) < string(c2.addres)); });
			break;
		default:
			break;
		}
		ofstream fileOut;
		fileOut.open("customers", ios::binary | ios::out);
		for (int i = 0; i < customers.size(); i++)
		{
			fileOut.write((char*)&customers.at(i), sizeof(Customer));
		}
		fileOut.close();

		return Customer::displayCustomers();
	};
};

void menu();
int main() {
	while (true) menu();
	return 0;
}

void menu() {
	int operation;
	system("cls");
	cout << "System wypozyczalni motocykli\n\n";
	cout << "Menu:\n";
	cout << "1 - Dodaj nowego klienta\n";
	cout << "2 - Dodaj nowy sprzet\n";
	cout << "3 - Usun klienta z bazy\n";
	cout << "4 - Usun sprzet z bazy\n";
	cout << "5 - Modyfikuj dane sprzetu\n";
	cout << "6 - Wyswietl liste klientow\n";
	cout << "7 - Wyswietl liste sprzetow\n";
	cout << "\nPodaj numer operacji: ";
	cin >> operation;

	switch (operation)
	{
	case 1:
		Customer::addCustomer();
		break;
	case 2:
		Motorcycle::addMotorcycle();
		break;
	case 3:
		Customer::deleteCustomer();
		break;
	case 4:
		Motorcycle::deleteMotorcycle();
		break;
	case 5:
		Motorcycle::editMotorcycle();
		break;
	case 6:
		Customer::displayCustomers();
		break;
	case 7:
		Motorcycle::displayMotorcycles();
		break;
	default:
		break;
	}
}