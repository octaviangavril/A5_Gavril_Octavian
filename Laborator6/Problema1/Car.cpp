#define _CRT_SECURE_NO_WARNINGS
#include "Car.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
Car::Car()
{
	printf("A fost apelat constructorul Car\n");
}
Car::~Car()
{
	this->name = nullptr;
	delete(name);
	printf("A fost apelat destructorul Car\n");
}
void Car::Set_name(const char* name)
{
	this->name = (char*)(malloc(strlen(name) + 1));
	memcpy(this->name, name, strlen(name) + 1);
}
void Car:: Set_fuel_capacity(int value)
{
	this->fuel_capacity = value;
}
void Car::Set_fuel_consumption(int value)
{
	this->fuel_consumption = value;
}
 void Car::Set_average_speed(weather w, int value)
{
	 this->average_speed[w] = value;
}
void Car::Print_name()
 {
	printf(this->name);
	printf("\n");
 }
 int Car::Get_fuel_capacity()
{
	 return fuel_capacity;
}
 int Car::Get_fuel_consumption()
{
	 return fuel_consumption;
}
 int Car::Get_average_speed(weather w)
{
	 return average_speed[w];
}