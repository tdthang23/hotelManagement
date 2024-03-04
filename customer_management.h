#pragma once
#include"customer.h"
#include"room.h"
class customer_management
{
private:
	customer *u;
	room *a;
	bool evaluate(customer u); //kiem tra id khach hang da ton tai trong file hay chua
public:
	void check_in(); //Ghi thong tin khach hang vao file
	void check_out(int id); //Xoa thong tin khach hang khoi file, thay doi trang thai phong va tinh tien
	void display(int id); //hien thi thong tin khach hang voi id duoc nhap vao
	void customer_list(); //hien thi danh sach khach hang
	void menu(); //menu
};

