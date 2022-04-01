#include "Mercedes.h"
#include <stdio.h>
Mercedes::Mercedes()
{
	Set_name("Mercedes");
	Set_fuel_capacity(10);
	Set_fuel_consumption(5);
	Set_average_speed(Rain, 55);
	Set_average_speed(Sunny, 80);
	Set_average_speed(Snow, 35);
	printf("A fost apelat constructorul Mercedes\n");
}
Mercedes::~Mercedes()
{
	printf("A fost apelat destructorul Mercedes\n");
}