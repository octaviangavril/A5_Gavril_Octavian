#include "NumberList.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	NumberList v;
	v.Init();

	v.Add(3);
	v.Add(8);
	v.Add(1);
	v.Add(12);
	v.Add(7);

	v.Print();

	v.Sort();
	v.Print();

	v.Add(5);
	v.Add(7);
	v.Sort();
	v.Print();

	system("pause");
	return 0;
}