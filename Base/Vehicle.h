#pragma once
#include <iostream>
using namespace std;

class Vehicle
{
protected:
	double petrol_amount; // Текущее кол-во топлива в баке.
	double tank_volume;	//Максимальный объем топлива.
	bool is_free; // Если транспорт уже присутсвует на базе, возвращает false.

public:
	Vehicle();
	Vehicle(double petrol_amount, double tank_volume);
	double getTankVolume(); //-узнать объем бензобака в литрах;
	double getPetrolAmount();// -узнать текущее количество топлива в баке;
	virtual bool leave();// -залить полный бак и покинуть базу; в случае невозможности уехать возвращает false;
	virtual void arrive();
	virtual void Print();
	virtual bool isFree();
};

