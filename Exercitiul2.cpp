#include <stdio.h>
#include <cstring>
int char_to_int(char s[50])
{
	int nr=0, p = 1;
	int k = strlen(s) - 1;
	for (int i = k; i >= 0; i--)
	{
		int cifra=s[i]-'0';
		nr = nr + p * cifra;
		p = p * 10;
	}
	return nr;
}
int main()
{
	FILE * pfile;
	fopen_s(&pfile,"ini.txt", "r");
	if (pfile == NULL)
		printf("Nu am putut deschide fisierul");
	else
	{
		char numar[200]; int s = 0;
		while (fgets(numar, 200, pfile))
		{
			numar[strlen(numar)-1 ] = '\0';
			s = s + char_to_int(numar);
			printf("Am citit numarul %s\n", numar);
		}
		printf("Suma numerelor din fisier este: %d", s);
		fclose(pfile);
	}
}