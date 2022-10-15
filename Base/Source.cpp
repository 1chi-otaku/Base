#include <iostream>
#include "Base.h"
#include "Vehicle.h"
#include "Bus.h"
#include "Truck.h"
#include "new"
using namespace std;

void PrintMenu();
void ArriveAll(Vehicle* p1, int veh_count, Bus* p2, int bus_count, Truck* p3, int trk_count);
void LeaveAll(Vehicle* p1, int veh_count, Bus* p2, int bus_count, Truck* p3, int trk_count);
void ShowAll(Vehicle* p1, int veh_count, Bus* p2, int bus_count, Truck* p3, int trk_count);

int main() {
	srand(time(NULL));
	
	Base base(500, 1000);
	int vehicle_count, bus_count, truck_count;
	cout << "Enter Vehicle count: ";
	cin >> vehicle_count;
	Vehicle* veh = new Vehicle[vehicle_count];
	cout << "Enter Bus count: ";
	cin >> bus_count;
	Bus* bus = new Bus[bus_count];
	cout << "Enter Truck count: ";
	cin >> truck_count;
	Truck* trk = new Truck[truck_count];
	
	int input = -3;
	
	while (input != -2)
	{
		PrintMenu();
		cin >> input;
		switch (input)
		{

		case 1:
			system("cls");
			base.Print();
			system("pause");
			break;
		case 2:
			ShowAll(veh,vehicle_count,bus,bus_count,trk,truck_count);
			break;
		case 3:
			ArriveAll(veh, vehicle_count, bus, bus_count, trk, truck_count);
			break;
		case 4:
			LeaveAll(veh, vehicle_count, bus, bus_count, trk, truck_count);
			break;


		case 5:


			break;
		default:
			break;
		}

	}
	
	



	delete[]veh;
	delete[]trk;
	delete[]bus;
	

	
	return 0;
}

void PrintMenu()
{
	system("cls");
	cout << "---------------------- MILITARY BASE SIMULATOR! TM ----------------------" << endl;
	cout << "1 - Show Base information." << endl;
	cout << "2 - Show all the vehicles!" << endl;
	cout << "3 - Drive all vehicles to the base." << endl;
	cout << "4 - Remove all vehicles from the base." << endl;
	cout << ": ";
}

void ArriveAll(Vehicle* p1, int veh_count, Bus* p2, int bus_count, Truck* p3, int trk_count)
{
	system("cls");
	cout << "Arrived!" << endl;
	for (int i = 0; i < veh_count; i++)
	{
		if(p1->isFree())(p1 + i)->arrive();
	}
	for (int i = 0; i < bus_count; i++)
	{
		if (p2->isFree())(p2 + i)->arrive();
	}
	for (int i = 0; i < trk_count; i++)
	{
		if (p3->isFree())(p3 + i)->arrive();
	}
	system("pause");
}
void LeaveAll(Vehicle* p1, int veh_count, Bus* p2, int bus_count, Truck* p3, int trk_count)
{
	system("cls");
	for (int i = 0; i < veh_count; i++)
	{
		if (!p1->isFree())(p1 + i)->leave();
	}
	for (int i = 0; i < bus_count; i++)
	{
		if (!p2->isFree())(p2 + i)->leave();
	}
	for (int i = 0; i < trk_count; i++)
	{
		if (!p3->isFree())(p3 + i)->leave();
	}
	cout << "Success!" << endl;
	system("pause");
}
void ShowAll(Vehicle* p1, int veh_count, Bus* p2, int bus_count, Truck* p3, int trk_count)
{
	system("cls");
	if(veh_count > 0)cout << "-------------VEHICLES-------------" << endl;
	for (int i = 0; i < veh_count; i++)
	{
		cout << "Vehicle #" << i + 1 << ")" << endl;
		(p1 + i)->Print();
		cout << endl;
	}
	if (bus_count > 0)cout << "---------------BUS---------------" << endl;
	for (int i = 0; i < bus_count; i++)
	{
		cout << "Bus #" << i + 1 << ")" << endl;
		(p2 + i)->Print();
		cout << endl;
	}
	if (trk_count > 0)cout << "-------------TRUCKS--------------" << endl;
	for (int i = 0; i < trk_count; i++)
	{
		cout << "Truck #" << i + 1 << ")" << endl;
		(p3 + i)->Print();
		cout << endl;
	}
	system("pause");
}
