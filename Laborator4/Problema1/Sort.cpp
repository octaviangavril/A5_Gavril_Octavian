#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

Sort::Sort(int numar_elemente, int min_element, int max_element)
{
	this->vector = (int*)(malloc(numar_elemente * sizeof(int)));
	this->numar_elemente = numar_elemente;
	time_t t;
	srand((unsigned)time(&t));
	for (int i = 0; i < numar_elemente; i++)
	{
		//printf("Am generat elementul cu numarul %d: %d\n", i, min_element + rand() % (min_element - max_element + 1));
		this->vector[i] = min_element + rand() % (min_element - max_element + 1);
	}
}
Sort::Sort(int* vector, int numar_elemente)
{
	this->vector = (int*)(malloc(numar_elemente * sizeof(int)));
	this->numar_elemente = numar_elemente;
	for (int i = 0; i < numar_elemente; i++)
	{
		//printf("Elementul de pe pozitia %d:%d\n", i, vector[i]);
		this->vector[i] = vector[i];
	}
}
Sort::Sort(int count, ...)
{ 
	this->numar_elemente = count;
	va_list vl;
	va_start(vl, count);
	for (int i = 0; i < count; i++)
	{
		//printf("Elementul din va arg cu numarul %d: %d\n", i, va_arg(vl, int));
		this->vector = (int*)(realloc(vector, (i + 1) * sizeof(int)));
		this->vector[i] = va_arg(vl, int);
	}

	va_end(vl);

}
Sort::Sort(char* c)
{
	//parcurgem sirul si transformam fiecare string in nr
	char* p;
	int i = 0;
	this->vector = (int*)(malloc(10*sizeof(int)));
	p = strtok(c, ",");
	while (p)
	{
		int nr = 0, k = 1;
		int l = strlen(p) - 1;
		for (int i = l; i >= 0; i--)
		{
			int cifra = p[i] - '0';
			nr = nr + k * cifra;
			k = k * 10;
		}
		if(i>=10)
		   this->vector = (int* )(realloc(vector, (i + 20) * sizeof(int)));
		this->vector[i++] = nr;
		//printf("Elementul de pe poitia %d: %d\n", i-1, this->vector[i - 1]);
		p = strtok(NULL, ",");
	}
	this->numar_elemente = i;
}
Sort::Sort(): vector(new int[6]{ 1, 2, 3, 4, 5, 6 }) {
	this->numar_elemente = 6;
}
void Sort::InsertSort(bool ascendent)
{
	int i, key, j;
	if(ascendent==true)
		for (i = 1; i < this->numar_elemente; i++)
		{
			key = this->vector[i];
			j = i - 1;

			while (j >= 0 && this->vector[j] > key)
			{
				this->vector[j + 1] = this->vector[j];
				j = j - 1;
			}
			this->vector[j + 1] = key;
		}
	else
	for (i = 1; i < this->numar_elemente; i++)
	{
		key = this->vector[i];
		j = i - 1;

		while (j >= 0 && this->vector[j] < key)
		{
			this->vector[j + 1] = this->vector[j];
			j = j - 1;
		}
		this->vector[j + 1] = key;
	}
}
int partition_true(int arr[], int low, int high)
{
	int pivot = arr[high]; 
	int i = (low - 1); 

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++; 
			int aux = arr[i];
			arr[i] = arr[j];
			arr[j] = aux;
		}
	}
	int aux = arr[i+1];
	arr[i+1] = arr[high];
	arr[high] = aux;
	return (i + 1);
}
int partition_false(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] > pivot)
		{
			i++;
			int aux = arr[i];
			arr[i] = arr[j];
			arr[j] = aux;
		}
	}
	int aux = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = aux;
	return (i + 1);
}
void Sort::QuickSort(bool ascendent,int low, int high)
 {
	if (ascendent)
	{
	  if (low < high)
	{
		int pi = partition_true(this->vector, low, high);
		QuickSort(ascendent,low, pi - 1);
		QuickSort(ascendent,pi + 1, high);
	}

	}
	else
	{
		if (low < high)
		{
			int pi = partition_false(this->vector, low, high);
			QuickSort(ascendent, low, pi - 1);
			QuickSort(ascendent, pi + 1, high);
		}
	}
	
}

void Sort::BubbleSort(bool ascendent )
{
	int i, j,aux;
	if (ascendent)
	{
		for (i = 0; i < this->numar_elemente - 1; i++)
			for (j = 0; j < this->numar_elemente - i - 1; j++)
				if (this->vector[j] > this->vector[j + 1])
				{
					aux = this->vector[j];
					this->vector[j] = this->vector[j + 1];
					this->vector[j + 1] = aux;
				}
	}
	else
	{
		for (i = 0; i < this->numar_elemente - 1; i++)
			for (j = 0; j < this->numar_elemente - i - 1; j++)
				if (this->vector[j] < this->vector[j + 1])
				{
					aux = this->vector[j];
					this->vector[j] = this->vector[j + 1];
					this->vector[j + 1] = aux;
				}
	}
}

void Sort::Print()
{
	for (int i = 0; i < this->numar_elemente; i++)
	   printf("%d ", this->vector[i]);
	printf("\n");
}

int  Sort::GetElementsCount()
{
	return this -> numar_elemente;
}

int  Sort::GetElementFromIndex(int index)
{
	return this->vector[index];
}