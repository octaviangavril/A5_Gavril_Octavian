#include "NumberList.h"
#include <stdio.h>
void NumberList::Init()
{
	this->count = 0;
 }
bool NumberList::Add(int x)
{
	if (this->count < 10)
	{
    this->count++;
	this->numbers[this->count] = x;
	printf("Am adaugat valoarea %d in vector\n", x);
	}
	else
	{
		printf("Vectorul are numarul maxim de elemente");
		return false;
	}
}
void NumberList::Sort()
{
	for (int i = 0; i < this->count; i++)
		for (int j = i + 1; j <= this->count; j++)
			if (this->numbers[i] > this->numbers[j])
			{
				int aux = this->numbers[i];
				this->numbers[i] = this->numbers[j];
				this->numbers[j] = aux;
			}
}
void NumberList::Print()
{
	printf("Vectorul este:");
	for (int i = 0; i <= this->count; i++)
		printf("%d ", this->numbers[i]);
	printf("\n");
}