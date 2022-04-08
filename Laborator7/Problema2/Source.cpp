#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

int main()
{
	VECTOR<int> templateint;

	templateint.push(4);
	templateint.push(12);
	templateint.push(9);
	templateint.push(10);
	templateint.push(22);
	templateint.push(31);

	printf("Vectorul initial cu %d elemente: ", templateint.count());

	for (int i = 0; i < templateint.count(); i++)
		printf("%d ", templateint.get(i));
	printf("\n");

	printf("Ultimul element adaugat este %d\n", templateint.pop());

	templateint.remove(3);

	printf("Vectorul dupa remove(3): ");

	for (int i = 0; i < templateint.count(); i++)
		printf("%d ", templateint.get(i));
	printf("\n");

	templateint.insert(14, 3);

	printf("Vectorul dupa insert(14, 3): ");

	for (int i = 0; i < templateint.count(); i++)
		printf("%d ", templateint.get(i));
	printf("\n");

	templateint.sort(nullptr);

	printf("Vectorul dupa sort(nullptr): ");

	for (int i = 0; i < templateint.count(); i++)
		printf("%d ", templateint.get(i));
	printf("\n");

	templateint.sort(functieDeComparare);

	printf("Vectorul dupa sort(functieDeComparare): ");

	for (int i = 0; i < templateint.count(); i++)
		printf("%d ", templateint.get(i));
	printf("\n");

	templateint.set(5, 99);

	printf("Vectorul dupa set(5, 99): ");

	for (int i = 0; i < templateint.count(); i++)
		printf("%d ", templateint.get(i));
	printf("\n");

	printf("Indexul lui %d este : %d\n",9,templateint.firstIndexOf(nullptr, 9));

	printf("Indexul lui %d este : %d\n", 12, templateint.firstIndexOf(functieDeEgalitate, 11));
}