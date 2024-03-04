#pragma once
#include"room.h"
class revenue
{
private:
	float fee;
public:
	revenue();
	void caculate(room a, int days, float discount=0); //tinh toan tien khach hang can thanh toan
	void display(); //hien thi doanh thu
	void reset(); //reset doanh thu ve 0
	void menu(); // menu
};

