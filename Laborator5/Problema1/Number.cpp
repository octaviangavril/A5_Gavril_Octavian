#define _CRT_SECURE_NO_WARNINGS
#include "Number.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>

int char_to_int(char s[100])
{
	int nr = 0, p = 1;
	int k = (int)strlen(s) - 1;
	for (int i = k; i >= 0; i--)
	{
		int cifra = s[i] - '0';
		nr = nr + p * cifra;
		p = p * 10;
	}
	return nr;
}

int bazaX_to_baza10(int numar,int bazaX)
{
	int i = 0,nou=0;
	while (numar)
	{
		nou = nou + numar % 10 * (int)pow(bazaX, i);
		i++;
		numar /= 10;
	}
	return nou;
}
char* baza10_to_bazaX(int numar, int bazaX)
{
	char nr_final[100]="", cifra[100]="";
	while (numar)
	{
		int r = numar % bazaX;
		numar /= bazaX;
		if (r >= 10)
			cifra[0] = (char)(r + 55);
		else
			cifra[0] = (char)(r + '0');
		cifra[1] = NULL;
		strcat(cifra, nr_final);
		strcpy(nr_final, cifra);
	}
	return (char*)nr_final;
}
Number::Number(const char* value, int base)
{
	this->baza = base;
	this->nr = (char*)(malloc(sizeof(char)*strlen(value)));		
	if (this->nr != nullptr)
		memset(this->nr, 0, strlen(value));
	strcpy(this->nr, value);
}
Number::Number(int value)
{
	this->baza = 10;
	char temp[100];
	strcpy(temp,baza10_to_bazaX(value, 10));
	this->nr = (char*)(malloc(sizeof(char) * strlen(temp) + 1));
	if (this->nr != nullptr)
		memset(this->nr, 0, strlen(temp) + 1);
	strcpy(this->nr, temp);
}
Number::~Number()
{
	this->nr=nullptr;
	delete(this->nr);
	this->baza = 0;
}
void Number::SwitchBase(int newBase)
{
	int numar = char_to_int(this->nr), nou = 0,i=0;
	nou = bazaX_to_baza10(numar, this->baza);
	// nou este in baza 10
	strcpy(this->nr, baza10_to_bazaX(nou,newBase));
	this->baza = newBase;
}

void Number::Print()
{
	printf("%s\n", this->nr);
}

int  Number::GetDigitsCount()
{
	return (int )strlen(this->nr); 
}

int  Number::GetBase()
{
	return this->baza;
}

Number::Number(const Number& ex): Number(ex.nr, ex.baza) {
	
}

Number::Number(const Number&& ex) {
	//printf("move\n");
	this->nr = ex.nr;
	this->baza = ex.baza;
}
Number& Number::operator=(int value) {
	//printf("Move assignment operator\n");
	strcpy(this->nr,baza10_to_bazaX(value,this->baza));
	return *this;
}
Number& Number::operator=(const char* value) {
	//printf("Move assignment operator\n");
	Number rez(value, this->baza);
	return rez;
}
Number& Number::operator=(Number&& ex) {
	//printf("Move assignment operator\n");
	this->nr = ex.nr;
	this->baza = ex.baza;
	return *this;
}

Number operator+(Number ex1,Number ex2) {
	
	printf("Operatorul + apelat in format operator+(Number ex)\n");
	int baz;
	if (ex1.baza >= ex2.baza)
		baz = ex1.baza;
	else baz = ex2.baza;
	int n1 = char_to_int(ex1.nr);
	int n2 = char_to_int(ex2.nr);
	int suma = bazaX_to_baza10(n1, ex1.baza) + bazaX_to_baza10(n2, ex2.baza);
	char temp[100];
	strcpy(temp,baza10_to_bazaX(suma, baz));
	Number rez(temp, baz);
	return rez;
}

Number operator-(Number ex1,Number ex2) {
	printf("Operatorul - apelat in format operator-(Number ex)\n");
	int baz;
	if (ex1.baza >= ex2.baza)
		baz = ex1.baza;
	else baz = ex2.baza;
	int n1 = char_to_int(ex1.nr);
	int n2 = char_to_int(ex2.nr);
	int dif = abs(bazaX_to_baza10(n1, ex1.baza) - bazaX_to_baza10(n2, ex2.baza));
	char temp[100];
	strcpy(temp, baza10_to_bazaX(dif, baz));
	Number rez(temp, baz);
	return rez;
}

void Number::operator+=(Number ex){
	int n1 = char_to_int(this->nr);
	int n2 = char_to_int(ex.nr);
	int suma = bazaX_to_baza10(n1,this->baza) + bazaX_to_baza10(n2, ex.baza);
	strcpy(this->nr, baza10_to_bazaX(suma, this->baza));
}

void Number::operator-=(Number ex) {
	int n1 = char_to_int(this->nr);
	int n2 = char_to_int(ex.nr);
	int dif = abs(bazaX_to_baza10(n1, this->baza) - bazaX_to_baza10(n2, ex.baza));
	strcpy(this->nr, baza10_to_bazaX(dif, this->baza));
}

void Number::operator--(int value) {
	printf("Operatorul -- apelat in format prefixat\n");
	this->nr[strlen(this->nr) - 1] = NULL;
}
void Number::operator--() {
	printf("Operatorul -- apelat in format postfixat\n");
	for (int i = 0; i < strlen(this->nr) - 1; i++)
	{
		this->nr[i] = this->nr[i + 1];
	}
	this->nr[strlen(this->nr) - 1] = NULL;
}

char Number::operator[](int index) {
	printf("Operatorul de indexare\n");
	return this->nr[index];
}

bool Number::operator<(Number ex) {
	printf("Operatorul < cu parametru Number\n");
	int n1 = char_to_int(this->nr);
	int n2 = char_to_int(ex.nr);
	n1 = bazaX_to_baza10(n1, this->baza);
	n2 = bazaX_to_baza10(n2, ex.baza);
	if (n1 < n2)
		return true;
	else return false;

}
bool Number::operator>(Number ex) {
	printf("Operatorul > cu parametru Number\n");
	int n1 = char_to_int(this->nr);
	int n2 = char_to_int(ex.nr);
	n1 = bazaX_to_baza10(n1, this->baza);
	n2 = bazaX_to_baza10(n2, ex.baza);
	if (n1 > n2)
		return true;
	else return false;
}
bool Number::operator<=(Number ex) {
	printf("Operatorul <= cu parametru Number\n");
	int n1 = char_to_int(this->nr);
	int n2 = char_to_int(ex.nr);
	n1 = bazaX_to_baza10(n1, this->baza);
	n2 = bazaX_to_baza10(n2, ex.baza);
	if (n1 <= n2)
		return true;
	else return false;
}
bool Number::operator>=(Number ex) {
	printf("Operatorul >= cu parametru Number\n");
	int n1 = char_to_int(this->nr);
	int n2 = char_to_int(ex.nr);
	n1 = bazaX_to_baza10(n1, this->baza);
	n2 = bazaX_to_baza10(n2, ex.baza);
	if (n1 >= n2)
		return true;
	else return false;
}
bool Number::operator==(Number ex) {
	printf("Operatorul == cu parametru Number\n");
	int n1 = char_to_int(this->nr);
	int n2 = char_to_int(ex.nr);
	n1 = bazaX_to_baza10(n1, this->baza);
	n2 = bazaX_to_baza10(n2, ex.baza);
	if (n1 == n2)
		return true;
	else return false;
}