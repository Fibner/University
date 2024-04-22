#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Motorbike {
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

int main() {
	int testNumber = 2;
	int readTestNumber;
	ofstream fileOut;
	ifstream fileIn;
	fileOut.open("test", ios::binary);
	fileOut.write((char *) &testNumber, sizeof(int));
	fileOut.close();

	fileIn.open("test", ios::binary);
	fileIn.read((char *)&readTestNumber, sizeof(int));
	cout << readTestNumber << endl;
	fileIn.close();
}