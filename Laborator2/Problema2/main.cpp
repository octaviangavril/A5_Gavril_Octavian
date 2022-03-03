#include "School.h"
#include <stdlib.h>
#include <cstring>
#include <stdio.h>
int compareNume(char* s1, char* s2)
{
	if (strlen(s1)-strlen(s2) > 0)
		return 1;
	else if (strlen(s1) - strlen(s2) < 0)
		return -1;
	else return 0;
}
int compareNotaMate(int s1, int s2)
{
	if (s1 > s2)
		return 1;
	else if (s1 == s2)
		return 0;
	else return -1;
}
int compareNotaEng(int s1, int s2)
{
	if (s1 > s2)
		return 1;
	else if (s1 == s2)
		return 0;
	else return -1;
}
int compareNotaIst(int s1, int s2)
{
	if (s1 > s2)
		return 1;
	else if (s1 == s2)
		return 0;
	else return -1;
}
int compareAverage(double s1, double s2)
{
	if (s1 > s2)
		return 1;
	else if (s1 == s2)
		return 0;
	else return -1;
}
int main()
{
	School student1, student2;
	student1.setNume((char*)"Marian");
	student1.setNotaMate(9);
	student1.setNotaEng(10);
	student1.setNotaIst(8);

	student2.setNume((char*)"Andrei");
	student2.setNotaMate(6);
	student2.setNotaEng(10);
	student2.setNotaIst(9);

	printf("%d\n", compareNume(student1.getNume(), student2.getNume()));
	printf("%d\n", compareNotaMate(student1.getNotaMate(), student2.getNotaMate()));
	printf("%d\n", compareNotaEng(student1.getNotaEng(), student2.getNotaEng()));
	printf("%d\n", compareNotaIst(student1.getNotaIst(), student2.getNotaIst()));
	printf("%d\n", compareAverage(student1.average(), student2.average()));

	system("pause");
	return 0;
}