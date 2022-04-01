#define _NO_CRT_STDIO_INLINE
#include "Circuit.h"
#include "Car.h"
#include <stdlib.h>
#include <stdio.h>
void Circuit::SetLength(int value)
{
	this->Length = value;
}
void Circuit::SetWeather(weather w)
{
	this->w = w;
}
void Circuit::AddCar(Car* c)
{
	if(this->number_of_cars<this->maxNumber)
		this->cars[this->number_of_cars++] = c;
}
int Circuit::Get_Lenght()
{
	return this->Length;
}
weather Circuit::Get_weather()
{
	return this->w;
}
Circuit::Circuit()
{
	this->maxNumber = 10;
	this->Length = 0;
	this->w = Rain;
	this->number_of_cars = 0;
	this->number_of_failed_cars = 0;
	this->cars = (Car**)(malloc(sizeof(Car*)*this->maxNumber));
	this->failed_cars=(Car**)(malloc(sizeof(Car*)*this->maxNumber));
	printf("A fost apelat constructorul Circuit\n");
}
Circuit::~Circuit()
{
	for (int i = 0; i < this->number_of_cars; i++)
	{
		this->cars[i] = nullptr;
		delete(this->cars[i]);
	}
	for (int i = 0; i < this->number_of_failed_cars; i++)
	{
		this->failed_cars[i] = nullptr;
		delete(this->failed_cars[i]);
	}
	this->cars = nullptr;
	this->failed_cars = nullptr;
	delete(this->failed_cars);
	delete(this->cars);
	printf("A fost apelat destructorul Circuit\n");
}
bool car_can_finish(Car* c,int lenght)
{
	int a = c->Get_fuel_capacity();
	int b = c->Get_fuel_consumption();
	
	if (lenght / 100 * b <= a)
		return true;
	return false;
}
void Circuit::delete_car(int index)
{
	for (int i = index; i < this->number_of_cars; i++)
		this->cars[i] = this->cars[i + 1];
}
void Circuit::Race()
{
	for(int i=0;i<this->number_of_cars;i++)
		if (!car_can_finish(this->cars[i], this->Length))
		{
			this->failed_cars[this->number_of_failed_cars++] = this->cars[i];
			this->delete_car(i);
			this->number_of_cars--;
		}
	for(int i=0;i<this->number_of_cars-1;i++)
		for (int j = i + 1; j < this->number_of_cars; j++)
		{
			int speed1 = this->cars[i]->Get_average_speed(this->w);
			int speed2 = this->cars[j]->Get_average_speed(this->w);
			if (speed1 < speed2)
			{
				Car* aux;
				aux = this->cars[i];
				this->cars[i] = this->cars[j];
				this->cars[j] = aux;
			}
		}
}
void Circuit::ShowFinalRanks()
{
	printf("Cars that have finished:\n");
	for (int i = 0; i < this->number_of_cars; i++)
	{
		printf("%d. ", i + 1); 
		this->cars[i]->Print_name();
	}
	printf("\n");
}
void Circuit::ShowWhoDidNotFinis()
{
	printf("Cars that have not finished:\n");
	for (int i = 0; i < this->number_of_failed_cars; i++)
	{
		printf("- ");
	    this->failed_cars[i]->Print_name();
	}
	printf("\n");
}