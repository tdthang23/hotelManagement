#pragma once
#include<string>
using namespace std;
class customer
{
	private:
		int customer_id;
		string name;
		bool gender;
		string phone_number;
		int room_id;
		int days;
	public:
		customer(); //ham khoi tao
		void set_id(); //nhap id khach hang
		void set_name(); //nhap ten khach hang
		void set_gender(); //nhap gioi tinh
		void set_phone_number(); //nhap sdt khach hang
		void set_room(); //nhap id phong cho khach thue
		void set_days(); //nhap so ngay thue
		void add(); //them thong tin khach hang
		int get_id(); //lay id khach hang
		string get_name(); //lay ten khach hang
		bool get_gender(); //lay gioi tinh
		string get_phone_number(); // lay sdt khach hang
		int get_room_id(); //lay id phong khach dang thue
		int get_days(); //lay so ngay khach thue
		void display(); //hien thi thong tin khach hang
};

