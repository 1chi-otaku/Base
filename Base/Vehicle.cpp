#include "Vehicle.h"
#include "Base.h"
#include <iostream>

Vehicle::Vehicle()
{
    petrol_amount = rand() % (70 - 100) + 70;
    tank_volume = 150;
    is_free = true;
}
Vehicle::Vehicle(double petrol_amount, double tank_volume)
{
    this->petrol_amount = petrol_amount;
    this->tank_volume = tank_volume;
    is_free = true;
}
double Vehicle::getTankVolume() { return tank_volume; }
double Vehicle::getPetrolAmount(){return petrol_amount;}
void Vehicle::arrive()
{
    if (!is_free)return;
    
    Base::Set_people_on_base(Base::Get_people_on_base()+1);
    Base::Set_vehicles_on_base(Base::Get_vehicles_on_base() + 1);

    is_free = false;
}
void Vehicle::Print()
{
    cout << "Petrol - " << petrol_amount << endl;
    cout << "Tank Volume - " << tank_volume << endl;
    cout << "Is free? - ";
    if (is_free)cout << "Yes" << endl;
    else cout << "No" << endl;
}
bool Vehicle::isFree()
{
    return is_free;
}
bool Vehicle::leave()
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
    Base::Set_people_on_base(Base::Get_people_on_base() - 1);
    Base::Set_vehicles_on_base(Base::Get_vehicles_on_base() - 1);
    

    Base::Set_petrol_on_base(Base::Get_petrol_on_base() - (tank_volume - petrol_amount));

    is_free = true;
    
    return true;
   
}

