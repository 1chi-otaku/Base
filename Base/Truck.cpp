#include "Truck.h"
#include "Vehicle.h"
#include "Base.h"
Truck::Truck():Vehicle()
{
	max_load = 30;
	current_load = 22;
}
Truck::Truck(double load, double max_load, double petrol, double max_petrol):Vehicle(petrol,max_petrol)
{
	this->max_load = load;
	current_load = max_load;
}
double Truck::getCurrentLoad(){return current_load;}
double Truck::getMaxLoad(){return max_load;}
void Truck::Print()
{
	Vehicle::Print();
	cout << "Max load - " << max_load << endl;
	cout << "Current load - " << current_load << endl;
}
bool Truck::leave()
{
	if (is_free)return false;
	if (Base::Get_petrol_on_base() - (tank_volume - petrol_amount) < 0) {
		cout << "No fuel" << endl;
		return false;
	}
	if (Base::Get_goods_on_base() <= 0) {
		cout << "No goods" << endl;
		return false;
	}
	if (Base::Get_people_on_base() == 0) {
		cout << "No people" << endl;
		return false;
	}
	if (Base::Get_goods_on_base() >= max_load) {
		current_load = max_load;
		Base::Set_goods_on_base(Base::Get_goods_on_base() - max_load);
	}
	else {
		current_load = Base::Get_goods_on_base();
		Base::Set_goods_on_base(0);
	}
	Base::Set_petrol_on_base(Base::Get_petrol_on_base() - (tank_volume - petrol_amount));
	Base::Set_vehicles_on_base(Base::Get_vehicles_on_base() - 1);
	Base::Set_people_on_base(Base::Get_people_on_base() - 1);
	is_free = true;
}
void Truck::arrive()
{
	if (!is_free)return;

	Base::Set_goods_on_base(Base::Get_goods_on_base() + current_load);
	Base::Set_vehicles_on_base(Base::Get_vehicles_on_base() + 1);
	Base::Set_people_on_base(Base::Get_people_on_base() + 1);
	current_load = 0;


	is_free = false;
}
