#include "Base.h"
#include <iostream>
using namespace std;
int Base::people_on_base = 0;
int Base::vehicles_on_base = 0;
double Base::petrol_on_base = 1000;
double Base::goods_on_base = 500;
Base::Base(double petrol, double goods)
{
	petrol_on_base = petrol;
	goods_on_base = goods;
}

int Base::Get_people_on_base()
{
	return people_on_base;
}
int Base::Get_vehicles_on_base()
{
	return vehicles_on_base;
}
double Base::Get_petrol_on_base()
{
	return petrol_on_base;
}
double Base::Get_goods_on_base()
{
	return goods_on_base;
}
void Base::Set_people_on_base(int new_data)
{
	people_on_base = new_data;
}
void Base::Set_vehicles_on_base(int new_data)
{
	vehicles_on_base = new_data;
}
void Base::Set_petrol_on_base(double new_data)
{
	petrol_on_base = new_data;
}
void Base::Set_goods_on_base(double new_data) {
	goods_on_base = new_data;
}

void Base::Print()
{
	cout << "People - " << people_on_base << endl;
	cout << "Vehicles - " << vehicles_on_base << endl;
	cout << "Petrol - " << petrol_on_base << endl;
	cout << "Goods - " << goods_on_base << endl;
}


Base::~Base()
{
	people_on_base = 0;
	vehicles_on_base = 0;
	petrol_on_base = 0;
	goods_on_base = 0;
}
