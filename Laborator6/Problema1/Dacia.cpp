#include "Dacia.h"
#include <stdio.h>
Dacia::Dacia() 
{
	Set_name("Dacia");
	Set_fuel_capacity(20);
	Set_fuel_consumption(7);
	Set_average_speed(Rain, 60);
	Set_average_speed(Sunny, 70);
	Set_average_speed(Snow, 40);
	printf("A fost apelat constructorul Dacia\n");
}
Dacia::~Dacia()
{
	printf("A fost apelat destructorul Dacia\n");
}
