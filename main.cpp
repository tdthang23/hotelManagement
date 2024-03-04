#include<iostream>
#include"room_management.h"
#include"customer_management.h"
#include"revenue.h"
#include"room.h"
using namespace std;

int main() {
	room_management a;
	customer_management u;
	revenue x;
	int choice;
	do {
		system("cls");
		cout << "========== HOTEL MANAGEMENT MENU =========" << endl;
		cout << "|| 1. ROOM MANGAGEMENT                  ||" << endl;
		cout << "|| 2. CUSTOMER MANAGEMENT               ||" << endl;
		cout << "|| 3. REVENUE MANAGEMENT                ||" << endl;
		cout << "|| 4. EXIT                              ||" << endl;
		cout << "==========================================" << endl;
		cout << "Enter your choice (1-4):";
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
			a.menu();
			cin.ignore();
			break;
		case 2:
			u.menu();
			cin.ignore();
			break;
		case 3:
			x.menu();
			cin.ignore();
			break;
		case 4:
			cout << " Exiting program..." << endl;
			break;
		default:
			cout << "Invalid choice. Please enter a number from 1-4." << endl;
			cin.ignore();
			break;
		}
	} while (choice != 4);
}