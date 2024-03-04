#pragma once
#include"room.h"
class room_management
{
private:
	room *a;
	bool evaluate(room u); //kiem tra id phong da ton tai trong file hay chua
public:
	void add_room(); //them phong vao file
	void change_status(int room_id); //thay doi trang thai phong va cap nhat vao file
	void show_room_property(int key); //hien thi thong tin phong voi id duoc nhap
	void display_room_list(); //hien thi danh sach phong
	void modify(int key); //cap nhat thong tin phong vao file
	void delete_room(int key); //xoa phong
	void menu(); //menu
};

