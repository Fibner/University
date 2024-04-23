#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Motorcycle {
public:
	string brand;
	string model;
	int power;
};

class Customer {
public:
	string name;
	string surname;
	string addres;
};

void menu();
void addCustomer();
void addMotorcycle();
void displayCustomers();
void displayMotorcycles();
int main() {
	menu();
	/*Motorcycle motorcycle1("Suzuki", "Katana", 999);
	Motorcycle motorcycle2("Suzuki", "GSX-8R", 1135);
	Motorcycle motorcycle3("Harley Davison", "Fatboy", 1868);
	Motorcycle motorcycles[3];
	motorcycles[0] = motorcycle1;
	motorcycles[1] = motorcycle2;
	motorcycles[2] = motorcycle3;

	ofstream fileOut;
	ifstream fileIn;
	fileOut.open("motorcycles", ios::binary);
	fileOut.write((char *) &motorcycles, sizeof(Motorcycle)*3);
	fileOut.close();

	Motorcycle readMotorcycles[3];
	fileIn.open("motorcycles", ios::binary);
	fileIn.read((char *) &readMotorcycles, sizeof(Motorcycle)*3);
	fileIn.close();*/

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
		addCustomer();
		break;
	case 2:
		addMotorcycle();
		break;
	case 6:
		displayCustomers();
		break;
	case 7:
		displayMotorcycles();
		break;
	default:
		return menu();
		break;
	}
}

void addCustomer() {
	Customer tempCustomer;
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
	cin >> tempCustomer.addres;
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
	return menu();
}

void addMotorcycle() {
	system("cls");
	Motorcycle tempMotorcycle;
	cout << "Podaj marke: ";
	cin >> tempMotorcycle.brand;
	cout << "Podaj model: ";
	cin >> tempMotorcycle.model;
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
	return menu();
};

void displayCustomers() {
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
	if (customers.size() == 0) cout << "Brak klientow w bazie.\n\n";

	system("pause");
	return menu();
};

void displayMotorcycles() {
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
	if (motorcycles.size() == 0) cout << "Brak motocykli w bazie.\n\n";
	system("pause");
	return menu();
};