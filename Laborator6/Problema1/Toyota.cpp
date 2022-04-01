#include "Toyota.h"
#include <stdio.h>

Toyota::Toyota()
{
	Set_name("Toyota");
	Set_fuel_capacity(7);
	Set_fuel_consumption(8);
	Set_average_speed(Rain, 50);
	Set_average_speed(Sunny, 80);
	Set_average_speed(Snow, 30);
	printf("A fost apelat constructorul Toyota\n");
}
Toyota::~Toyota()
{
	printf("A fost apelat destructorul Toyota\n");
}