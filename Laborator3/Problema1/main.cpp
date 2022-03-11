#include "Math.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
	Math f;
	printf("%d\n", f.Add(2, 3));
	printf("%d\n", f.Add(2, 3,4));
	printf("%d\n", f.Add(2.5, 3.4));
	printf("%d\n", f.Add(2.5, 3.4, 4.4));
	printf("%d\n", f.Mul(2, 3));
	printf("%d\n", f.Mul(2, 3, 4));
	printf("%d\n", f.Mul(2.5, 3.4));
	printf("%d\n", f.Mul(2.5, 3.5, 4.4));
	printf("%d\n", f.Add(3, 3, 4, 6));
	f.Add("Ana", "Maria");
	system("pause");
	return 0;
}