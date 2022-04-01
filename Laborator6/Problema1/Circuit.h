#pragma once
#include "Car.h"
class Circuit
{
private:
	int maxNumber;
	int Length;
	weather w;
	int number_of_cars;
	int number_of_failed_cars;
	Car** cars,**failed_cars;
public:
	Circuit();
	~Circuit();

	void SetLength(int value);
	void SetWeather(weather w);
	void AddCar(Car* c);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinis();

	void delete_car(int index);
	int Get_Lenght();
	weather Get_weather();
};

