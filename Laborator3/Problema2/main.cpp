#include "Canvas.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
	Canvas C(40, 70);
	C.DrawCircle(20, 35, 5, '.');
	C.DrawLine(10, 10, 35, 50, '*');
	C.FillRect(2, 2, 8,5, '-');
	C.Print();

	printf("\n");
	printf("Apasa orice tasta pentru a curata tabla..\n");
	C.Clear();
	system("pause");
	C.DrawRect(1, 1, 50, 8, '*');
	C.SetPoint(30, 60, '@');
	C.FillCircle(15, 45, 7, '.');
	C.Print();
	system("pause");
	return 0;
}