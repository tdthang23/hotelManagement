#include "customer_management.h"
#include"room.h"
#include"room_management.h"
#include"revenue.h"
#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

bool customer_management::evaluate(customer u) {
	bool evaluate = true;
	ifstream fin("customer.txt");
	customer* x;
	x = new customer;
	while (fin.read((char*)x, sizeof(customer))) {
		if (u.get_id() == x->get_id()) {
			evaluate = false;
			break;
		}
	}
	return evaluate;
}
void customer_management::check_in() {
	room_management x;
	bool check_room = false;
	size_t pos;
	u = new customer;
	u->add();
	bool check_customer = this->evaluate(*u);
	if (check_customer == false) {
		cout << "Customer ID existed! Press any key..." << endl;
		cin.ignore();
	}
	fstream fin;
	fin.open("room.txt", ios::in | ios::out);
	if (!fin.is_open()) {
		cout<< "File could not be opened!! Press any key..." << endl;
		return;
	}
	ofstream fout;
	fout.open("Customer.txt", ios::app);
	if (!fout.is_open()) {
		cout << "File could not be opened!! Press any key..." << endl;
		return;
	}
	a = new room;
	while (fin.read((char*)a, sizeof(room))) {
		if (u->get_room_id() == a->get_room_id()&&a->get_status() == false) {
			fout.write((char*)u,sizeof(customer));
			check_room = true;
			x.change_status(a->get_room_id());
			break;
		}
	}
	if (check_room==true)
		cout << "Customer added sucessfully! Press any key..." << endl;
	else
		cout << "Room is unavailable! Press any key.." << endl;
	fin.close();
	fout.close();
	cin.ignore();
}

void customer_management::check_out(int id) {
	fstream fin, fout;
	bool check;
	size_t pos;
	bool found = false;
	revenue r;
	room_management x;
	fin.open("customer.txt", ios::in);
	fout.open("customer_temp.txt", ios::out);
	if (!fout.is_open() || !fin.is_open()) {
		cout << "File could not open! Press any key..." << endl;
		return;
	}
	u = new customer;
	while (fin.read((char*)u, sizeof(customer))) {
		if (u->get_id() == id) {
			u->display();
			found = true;
			cout << "Do you really want to check-out? " << endl;
			cout << "1. YES" << endl;
			cout << "0. NO" << endl;
			cout << "Your option: ";
			cin >> check;
			if (check == true) {
				float discount;
				cout << "Enter Discout amount(%): ";
				cin >> discount;
				a = new room;
				ifstream froom("room.txt");
				if (!froom.is_open()) {
					cout << "File could not be opened!! Press any key..." << endl;
					cin.ignore();
					return;
				}
				while (froom.read((char*)a, sizeof(room))) {
					if (u->get_room_id() == a->get_room_id()) {
						x.change_status(a->get_room_id());
						r.caculate(*a, u->get_days(), discount);
						froom.close();
						break;
					}
				}
				continue;
			}
		}
		fout.write((char*)u, sizeof(customer));
	}
	fin.close();
	fout.close();
	if (found == true)
		cout << "Checked-out! Press any key..." << endl;
	else
		cout << "Customer does not exist! Press any key..." << endl;
	cin.ignore();
	remove("customer.txt");
	rename("customer_temp.txt", "customer.txt");
}

void customer_management::display(int id) {
	ifstream fin("customer.txt");
	bool found = false;
	if (!fin.is_open()) {
		cout << "File could not open! Press any key..." << endl;
		return;
	}
	u = new customer;
	while (fin.read((char*)u, sizeof(customer))) {
		if (u->get_id() == id) {
			u->display();
			found = true;
			break;
		}
	}
	fin.close();
	if (found == false)
		cout << "Customer does not exist! Press any key..." << endl;
	cin.ignore();
}

void customer_management::customer_list() {
	cout << left << setw(20) << "Customer ID" << left << setw(40) << "Name" << left << setw(10) << "Gender" << left << setw(20) << "Phone" << left << setw(10) << "Room" << left << setw(20) << "Days" << endl;
	ifstream fin("customer.txt");
	if (!fin.is_open()) {
		cout << "File could not open! Press any key..." << endl;
		return;
	}
	u = new customer;
	while (fin.read((char*)u, sizeof(customer))) {
		u->display();
	}
	fin.close();
	cout << "Press any key...";
	cin.ignore();
}

void customer_management::menu() {
	int choice;
	int key;
	do {
		system("cls");
		cout << "========== ROOM MANAGEMENT MENU ==========" << endl;
		cout << "|| 1. Check In                          ||" << endl;
		cout << "|| 2. Check Out                         ||" << endl;
		cout << "|| 3. Search Customer                   ||" << endl;
		cout << "|| 4. Display list of Customers         ||" << endl;
		cout << "|| 5. Back                              ||" << endl;
		cout << "==========================================" << endl;
		cout << "Enter your choice (1-5):";
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
			this->check_in();
			cin.ignore();
			break;
		case 2:
			cout << "Enter Customer ID: ";
			cin >> key;
			this->check_out(key);
			cin.ignore();
			break;
		case 3:
			cout << "Enter Customer ID: ";
			cin >> key;
			this->display(key);
			cin.ignore();
			break;
		case 4:
			this->customer_list();
			cin.ignore();
			break;
		case 5:
			cout << " Exiting program..." << endl;
			break;
		default:
			cout << "Invalid choice. Please enter a number from 1-5." << endl;
			break;
		}
	} while (choice != 5);
}