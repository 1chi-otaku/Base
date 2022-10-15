#pragma once
#include "Vehicle.h"
class Truck :public Vehicle
{
	double max_load;
	double current_load;
public:
	Truck();
	Truck(double load, double max_load, double petrol, double max_petrol);
	double getCurrentLoad(); //получить текущую загруженность машины(масса груза в тоннах);
	double getMaxLoad(); //узнать максимальную вместительность(грузоподъемность) машины;
	void Print();
	virtual bool leave();// -залить полный бак и покинуть базу; в случае невозможности уехать возвращает false;
	virtual void arrive();
};

