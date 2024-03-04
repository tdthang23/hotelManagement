#include "room_management.h"
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

bool room_management::evaluate(room u) {
	bool evaluate = true;
	ifstream fin("room.txt");
	room* x;
	x = new room;
	while (fin.read((char*)x, sizeof(room))) {
		if (u.get_room_id() == x->get_room_id()) {
			evaluate = false;
			break;
		}
	}
	return evaluate;
}

void room_management::add_room() {
	a = new room;
	a->add_room();
	bool check = this->evaluate(*a);
	if (check == false) {
		cout << "Room ID existed! Press any key..." << endl;
		cin.ignore();
		return;
	}
	fstream fout;
	fout.open("room.txt", ios::app);
	if (!fout.is_open()) {
		cout << "File could not open! Press any key..." << endl;
		return;
	}
	fout.write((char*)a, sizeof(room));
	cout << "Room is added! Press any key..." << endl;
	cin.ignore();
	fout.close();
}

void room_management::change_status(int room_id) {
	fstream fout;
	size_t pos;
	bool found = false;
	fout.open("room.txt", ios::in | ios::out);
	if (!fout.is_open()) {
		cout << "File could not open! Press any key..." << endl;
		return;
	}
	a = new room;
	while (fout.read((char*)a, sizeof(room))) {
		if (a->get_room_id() == room_id) {
			pos = fout.tellg();
			a->change_status();
			fout.seekp(pos - sizeof(room));
			fout.write((char*)a, sizeof(room));
			cout << "Status updated! Press any key..." << endl;
			found = true;
			break;
		}
	}
	if (found == false)
		cout << "Room does not exist! Press any key..." << endl;
	fout.close();
	cin.ignore();
}
void room_management::show_room_property(int key) {
	ifstream fin("room.txt");
	bool found = false;
	if (!fin.is_open()) {
		cout << "File could not open! Press any key..." << endl;
		return;
	}
	a = new room;
	while (fin.read((char*)a, sizeof(room))) {
		//a = new room[sizeof(room)];
		//fin.read((char*)a, sizeof(room));
		if (a->get_room_id() == key) {
			a->display();
			found = true;
			break;
		}
	}
	fin.close();
	if (found == false)
		cout << "Room does not exist! Press any key..." << endl;
	cin.ignore();
}

void room_management::display_room_list() {
	cout << left << setw(10) << "Room ID" << left << setw(20) << "Price" << left << setw(20) << "Status" << endl;
	ifstream fin("room.txt");
	if (!fin.is_open()) {
		cout << "File could not open! Press any key..." << endl;
		return;
	}
	a = new room;
	while (fin.read((char*)a, sizeof(room))) {
		a->display();
	}
	fin.close();
	cout << "Press any key...";
	cin.ignore();
}

void room_management::modify(int key) {
	fstream fout;
	size_t pos;
	bool found = false;
	fout.open("room.txt", ios::in|ios::out);
	if (!fout.is_open()) {
		cout << "File could not open! Press any key..." << endl;
		return;
	}
	a = new room;
	while (fout.read((char*)a, sizeof(room))) {
		if (a->get_room_id() == key) {
			pos = fout.tellg();
			cout << "Modify Room: " << endl;
			a->modify();
			fout.seekp(pos - sizeof(room));
			fout.write((char*)a, sizeof(room));
			cout << "Record Updated! Press any key..." << endl;
			found = true;
			break;
		}
	}
	if (found == false)
		cout << "Room does not exist! Press any key..." << endl;
	fout.close();
	cin.ignore();
}

void room_management::delete_room(int key) {
	fstream fin, fout;
	bool check;
	size_t pos;
	bool found = false;
	fin.open("room.txt", ios::in);
	fout.open("temp.txt", ios::out);
	if (!fout.is_open()||!fin.is_open()) {
		cout << "File could not open! Press any key..." << endl;
		return;
	}
	a=new room;
	while (fin.read((char*)a, sizeof(room))) {
		if (a->get_room_id() == key) {
			a->display();
			found = true;
			cout << "Do you really want to delete this room? " << endl;
			cout << "1. YES" << endl;
			cout << "0. NO" << endl;
			cout << "Your option: ";
			cin >> check;
			if (check == true) {
				continue;
			}
		}
		fout.write((char*)a, sizeof(room));
	}
	fin.close();
	fout.close();
	if (found == true)
		cout << "Record Updated! Press any key..." << endl;
	else
		cout << "Room does not exist! Press any key..." << endl;
	cin.ignore();
	remove("room.txt");
	rename("temp.txt", "room.txt");
}

void room_management::menu() {
	int choice;
	int key;
	do {
		system("cls");
		cout << "========== ROOM MANAGEMENT MENU ==========" << endl;
		cout << "|| 1. Add Room                          ||" << endl;
		cout << "|| 2. Search Room                       ||" << endl;
		cout << "|| 3. Display list of Rooms             ||" << endl;
		cout << "|| 4. Modify Room                       ||" << endl;
		cout << "|| 5. Delete Room                       ||" << endl;
		cout << "|| 6. Change Room's Status              ||" << endl;
		cout << "|| 7. Back                              ||" << endl;
		cout << "==========================================" << endl;
		cout << "Enter your choice (1-7):";
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
			this->add_room();
			cin.ignore();
			break;
		case 2:
			cout << "Enter Room ID: ";
			cin >> key;
			this->show_room_property(key);
			cin.ignore();
			break;
		case 3:
			this->display_room_list();
			cin.ignore();
			break;
		case 4:
			cout << "Enter Room ID: ";
			cin >> key;
			this->modify(key);
			cin.ignore();
			break;
		case 5:
			cout << "Enter Room ID: ";
			cin >> key;
			this->delete_room(key);
			cin.ignore();
			break;
		case 6:
			cout << "Enter Room ID: ";
			cin >> key;
			this->change_status(key);
			cin.ignore();
		case 7:
			cout << " Exiting program..." << endl;
			break;
		default:
			cout << "Invalid choice. Please enter a number from 1-7." << endl;
			break;
		}
	} while (choice != 7);
}