#include "Sort.h"
#include <stdlib.h>
#include <stdio.h>
int main()
{
	Sort c1(6, 50, 30);
	printf("Vectorul initial:\n");
	c1.Print();
	printf("Vectorul sortat crescator:\n");
	c1.BubbleSort(true);
	c1.Print();
	printf("Vectorul sortat descrescator:\n");
	c1.BubbleSort(false);
	c1.Print();
	printf("\n");

	int v[5] = { 1, 8, 12, 4, 9 };
	Sort c2(v, 5);
	printf("Vectorul initial:\n");
	c2.Print();
	printf("Vectorul sortat crescator:\n");
	c2.InsertSort(true);
	c2.Print();
	printf("Vectorul sortat descrescator:\n");
	c2.InsertSort(false);
	c2.Print();
	printf("\n");

	Sort c3(6, 1, 8, 3, 9, 5, 6);
	int n = c3.GetElementsCount();
	printf("Vectorul initial:\n");
	c3.Print();
	printf("Vectorul sortat crescator:\n");
	c3.QuickSort(true, 0, n);
	c3.Print();
	printf("Vectorul sortat descrescator:\n");
	c3.QuickSort(false, 0, n);
	c3.Print();
	printf("\n");

	char c[] = "12,4,26,18";
	Sort c4(c);
	printf("Vectorul initial:\n");
	c4.Print();
	printf("Vectorul sortat crescator:\n");
	c4.BubbleSort(true);
	c4.Print();
	printf("Vectorul sortat descrescator:\n");
	c4.BubbleSort(false);
	c4.Print();
	printf("\n");

	Sort c5;
	printf("Vectorul initial:\n");
	c5.Print();
	printf("Vectorul sortat crescator:\n");
	c5.InsertSort(true);
	c5.Print();
	printf("Vectorul sortat descrescator:\n");
	c5.InsertSort(false);
	c5.Print();
	printf("\n");

	int e = c1.GetElementFromIndex(3);
	printf("Elementul de pe pozitia 3 a vectorului c1 este: %d\n", e);
	system("pause");
	return 0;
}