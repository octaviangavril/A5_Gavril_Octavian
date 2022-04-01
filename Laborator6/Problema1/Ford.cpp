#include "Ford.h"
#include <stdio.h>
Ford::Ford()
{
	Set_name("Ford");
	Set_fuel_capacity(7);
	Set_fuel_consumption(8);
	Set_average_speed(Rain, 40);
	Set_average_speed(Sunny, 100);
	Set_average_speed(Snow, 30);
	printf("A fost apelat construcotrul Ford\n");
}
Ford::~Ford()
{
	printf("A fost apelat destructorul Ford\n");
}