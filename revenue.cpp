#include "revenue.h"
#include"room.h"
#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

revenue::revenue() {
	this->fee = 0;
}

void revenue::caculate(room a, int days, float discount) {
	fstream file;
	file.open("revenue.txt",ios::in);
	if (!file.is_open()) {
		cout << "File could not open! Press any key..." << endl;
		cin.ignore();
		return;
	}
	file >> fee;
	fee = fee +(1-discount/100)*(a.get_price() * days);
	file.close();
	file.open("revenue.txt", ios::trunc|ios::out);
	file << fee;
	file.close();
}

void revenue::display() {
	ifstream fin("revenue.txt");
	if (!fin.is_open()) {
		cout << "File could not open! Press any key..." << endl;
		cin.ignore();
		return;
	}
	fin >> fee;
	cout << "Total Revenue: " << fee << endl;
	fin.close();
	cout << "Press any key..." << endl;
	cin.ignore();
}
void revenue::reset() {
	fstream file;
	file.open("revenue.txt", ios::trunc | ios::out);
	file << 0;
	file.close();
	cout << "Revenue resetted! Press any key..." << endl;
	cin.ignore();
}

void revenue::menu() {
	int choice;
	do {
		system("cls");
		cout << "========== REVEUE MANAGEMENT MENU ========" << endl;
		cout << "|| 1. Revenue Display                   ||" << endl;
		cout << "|| 2. Revenue Reset                     ||" << endl;
		cout << "|| 3. Back                              ||" << endl;
		cout << "==========================================" << endl;
		cout << "Enter your choice (1-3):";
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
			this->display();
			cin.ignore();
			break;
		case 2:
			this->reset();
			cin.ignore();
			break;
		case 3:
			cout << " Exiting program..." << endl;
			break;
		default:
			cout << "Invalid choice. Please enter a number from 1-3." << endl;
			cin.ignore();
			break;
		}
	} while (choice != 3);
}
