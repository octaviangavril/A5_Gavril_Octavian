#include "Circuit.h"
#include "Car.h"
#include "Dacia.h"
#include "Ford.h"
#include "Mazda.h"
#include "Mercedes.h"
#include "Toyota.h"
#include "weather.h"
#include <stdlib.h>
int main()

{

	Circuit c;

	c.SetLength(100);

	c.SetWeather(weather::Rain);

	c.AddCar(new Dacia());
	
	c.AddCar(new Toyota());

	c.AddCar(new Mercedes());

	c.AddCar(new Ford());

	c.AddCar(new Mazda());

	c.Race();

	c.ShowFinalRanks(); // it will print the time each car needed to finish the circuit sorted from the fastest car to the   slowest.

	c.ShowWhoDidNotFinis(); // it is possible that some cars don't have enough fuel to finish the circuit
 
	system("pause");
	return 0;

}