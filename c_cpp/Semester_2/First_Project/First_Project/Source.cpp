#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Motorbike {
public:
	string brand;
	string model;
	int power;
	Motorbike() {};
	Motorbike(string _brand, string _model, int _power) {
		brand = _brand;
		model = _model;
		power = _power;
	};
};

class Customer {
public:
	string name;
	string surname;
	string addres;
};

int main() {
	Motorbike motorbike1("Suzuki", "Katana", 999);
	Motorbike motorbike2("Suzuki", "GSX-8R", 1135);
	Motorbike motorbike3("Harley Davison", "Fatboy", 1868);
	Motorbike motorbikes[3];
	motorbikes[0] = motorbike1;
	motorbikes[1] = motorbike2;
	motorbikes[2] = motorbike3;

	ofstream fileOut;
	ifstream fileIn;
	fileOut.open("motorbikes", ios::binary);
	fileOut.write((char *) &motorbikes, sizeof(Motorbike)*3);
	fileOut.close();

	Motorbike readMotorbikes[3];
	fileIn.open("motorbikes", ios::binary);
	fileIn.read((char *) &readMotorbikes, sizeof(Motorbike)*3);
	fileIn.close();
	
	return 0;
}