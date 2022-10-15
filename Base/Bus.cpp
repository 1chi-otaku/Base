#include "Bus.h"
#include "Vehicle.h"
#include "Base.h"

Bus::Bus():Vehicle()
{
	pass_places = 18;
	people_count = rand() % (5 - (pass_places + 1)) + 5;
}

Bus::Bus(int people, int max_people, double petrol, double max_petrol):Vehicle(petrol,max_petrol)
{
	people_count = people;
	pass_places = max_people;
}

int Bus::getPeopleCount() { return people_count; }
int Bus::getMaxPeople(){ return pass_places;}

void Bus::Print()
{
	Vehicle::Print();
	cout << "People in Bus - " << people_count << endl;
	cout << "Max passenger places - " << pass_places << endl;
}

bool Bus::leave()
{
	if (is_free)return false;
	if (Base::Get_petrol_on_base() - (tank_volume - petrol_amount) < 0) {
		cout << "No fuel" << endl;
		return false;
	}
	if (Base::Get_people_on_base() == 0) {
		cout << "No people" << endl;
		return false;
	}
	if (Base::Get_people_on_base() >= pass_places) {
		people_count = pass_places;
		Base::Set_people_on_base(Base::Get_people_on_base() - pass_places);
	}
	else{
		people_count = Base::Get_people_on_base();
		Base::Set_people_on_base(0);
	}

	Base::Set_petrol_on_base(Base::Get_petrol_on_base() - (tank_volume - petrol_amount));
	Base::Set_vehicles_on_base(Base::Get_vehicles_on_base()-1);
	is_free = true;
}

void Bus::arrive()
{
	if (!is_free)return;

	Base::Set_people_on_base(Base::Get_people_on_base() + people_count);
	Base::Set_vehicles_on_base(Base::Get_vehicles_on_base() + 1);
	people_count = 0;
	

	is_free = false;
}
