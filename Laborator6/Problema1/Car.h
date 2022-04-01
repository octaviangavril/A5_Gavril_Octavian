#pragma once
#include "weather.h"
class Car
{
	int fuel_capacity;
	int fuel_consumption;
	int average_speed[3];
	char* name;
public:
	Car();
	~Car();
	virtual void Set_name(const char* name);
	virtual void Set_fuel_capacity(int value);
	virtual void Set_fuel_consumption(int value);
	virtual void Set_average_speed(weather w,int value);

	virtual void Print_name();
	virtual int Get_fuel_capacity();
	virtual int Get_fuel_consumption();
	virtual int Get_average_speed(weather w);
};

