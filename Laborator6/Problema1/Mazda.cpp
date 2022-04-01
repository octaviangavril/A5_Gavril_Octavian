#include "Mazda.h"
#include <stdio.h>
Mazda::Mazda()
{
	Set_name("Mazda");
	Set_fuel_capacity(15);
	Set_fuel_consumption(8);
	Set_average_speed(Rain, 50);
	Set_average_speed(Sunny, 90);
	Set_average_speed(Snow, 25);
	printf("A fost apelat constructorul Mazda\n");
}

Mazda::~Mazda()
{
	printf("A fost apelat destructorul Mazda\n");
}