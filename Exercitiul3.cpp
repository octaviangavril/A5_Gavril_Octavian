#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <cstring>

int main()
{
	char c[20][20];
	printf("Introduceti numarul de cuvinte din propozitie: ");
	int numarCuvinte;
	scanf_s("%d", &numarCuvinte, 4);
	printf("Introduceti o propozitie: ");
	char cuvant[20];
	int counter = 0;
	while (scanf_s("%19s", cuvant, 19))
	{
		strcpy_s(c[counter],sizeof cuvant, cuvant);
		
		counter += 1;
		if (counter >= numarCuvinte)
			break;
	}
	counter--;
	for (int i = 0; i < counter; i++)
		for (int j = i + 1; j <= counter; j++)
			if (strlen(c[i]) < strlen(c[j]))
			{
				char aux[20];
				strcpy_s(aux, sizeof c[i], c[i]);
				strcpy_s(c[i], sizeof c[j], c[j]);
				strcpy_s(c[j], sizeof c[j], aux);
			}
			else if (strlen(c[i]) == strlen(c[j]) && strcmp(c[i],c[j])>0)
			{
				char aux[20];
				strcpy_s(aux, sizeof c[i], c[i]);
				strcpy_s(c[i], sizeof c[j], c[j]);
				strcpy_s(c[j], sizeof c[j], aux);
			}
	for (int i = 0; i <= counter; i++)
		printf("%s\n", c[i]);
}