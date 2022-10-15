#pragma once
#include "Vehicle.h"
class Bus :public Vehicle
{
	int people_count;
	int pass_places;
public:
	Bus();
	Bus(int people, int max_people, double petrol, double max_petrol);
	int getPeopleCount(); //-получить текущее количество пассажиров(водитель в это число не входит);
	int getMaxPeople(); //кол-во пассажирских мест.
	void Print();
	virtual bool leave();// -залить полный бак и покинуть базу; в случае невозможности уехать возвращает false;
	virtual void arrive();
};

