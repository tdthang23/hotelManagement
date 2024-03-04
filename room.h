#pragma once
class room
{
private:
	int room_id;
	bool status;
	float price;
public:
	room(); //ham khoi tao
	void set_room_id(); //nhap id phong
	void set_price(); //nhap gia phong
	void add_room(); //them phong
	int get_room_id(); //lay id phong
	bool get_status(); //lay trang thai hien tai cua phong
	float get_price(); //lay gia thue phong
	void display(); //hien thi thong tin phong
	void modify(); //cap nhat thong tin phong
	void change_status(); //thay doi tang thai phong
};

