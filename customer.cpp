#include "customer.h"
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

customer::customer() {
	this->customer_id = -1;
	this->name = " ";
	this->gender = 1;
	this->phone_number = " ";
	this->room_id = -1;
	this->days = 0;
}

void customer::set_id() {
	fflush(stdin);
	cin >> customer_id;
	cin.ignore();
}

void customer::set_name() {
	fflush(stdin);
	getline(cin, name);
}

void customer::set_gender() {
	fflush(stdin);
	cin >> gender;
	cin.ignore();
}
void customer::set_phone_number() {
	fflush(stdin);
	getline(cin, phone_number);
}
void customer::set_room() {
	fflush(stdin);
	cin >> room_id;
}
void customer::set_days() {
	fflush(stdin);
	cin >> days;
}

int customer::get_id() {
	return customer_id;
}
string customer::get_name() {
	return name;
}
bool customer::get_gender() {
	return gender;
}
string customer::get_phone_number() {
	return phone_number;
}
int customer::get_room_id() {
	return room_id;
}
int customer::get_days() {
	return days;
}

void customer::add() {
	cout << "Customer's Infomation: " << endl;
	cout << "Customer ID: ";
	this->set_id();
	cout << "Name: ";
	this->set_name();
	cout << "gender (1-Male/ 0-Female): ";
	this->set_gender();
	cout << "Phone Number: ";
	this->set_phone_number();
	cout << "Room ID: ";
	this->set_room();
	cout << "Days: ";
	this->set_days();
}

void customer::display() {
	cout << left << setw(20) << customer_id << left << setw(40) << name;
	if (gender == true)
		cout << left << setw(10) << "Male";
	else
		cout << left << setw(10) << "Female";
	cout << left << setw(20) << phone_number << left << setw(10) <<room_id << left << setw(20) << days << endl;;
}
