#include "room.h"
#include<iostream>
#include<iomanip>
using namespace std;

room::room() {
	this->room_id = -1;
	this->price = 0;
	this->status = false;
}

void room::set_room_id() {
	cin >> room_id;
}
void room::set_price() {
	cin >> price;
	cin.ignore();
}
void room::add_room() {
	cout << "Room's Information: " << endl;
	cout << "Room ID: ";
	this->set_room_id();
	cout << "Price($): ";
	cin >> price;
}

int room::get_room_id() {
	return room_id;
}
bool room::get_status() {
	return status;
}
float room::get_price() {
	return price;
}

void room::display() {
	cout << left << setw(10) << room_id << left << setw(20) << price;
	if (status == true)
		cout << left << setw(20) << "Unavailable" << endl;
	else 
		cout << left << setw(20) << "Available" << endl;
}

void room::modify() {
	cout << "Modify Room ID: ";
	this->set_room_id();
	cout << "Modify prince: ";
	this->set_price();
}

void room::change_status() {
	if (this->status == true)
		this->status = false;
	else
		this->status = true;
}
