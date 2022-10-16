#pragma once
#include "Vehicle.h"
class Base
{
	static int people_on_base; //количество людей на территории базы;
	static int vehicles_on_base; //количество транспортных средств на территории базы;
	static double petrol_on_base; //количество бензина на местной "заправке" (в литрах);
	static double goods_on_base; //количество "груза" - различных материальных ценностей(в тоннах).
public:
	Base(double petrol, double goods);
	int static Get_people_on_base();
	int static Get_vehicles_on_base();
	double static Get_petrol_on_base();
	double static Get_goods_on_base();
	void static Set_people_on_base(int new_data);
	void static Set_vehicles_on_base(int new_data);
	void static Set_petrol_on_base(double new_data);
	void static Set_goods_on_base(double new_data);
	void Print();
	void Init();
	~Base();
};


