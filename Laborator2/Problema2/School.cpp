#include "School.h"
#include <stdio.h>
#include <cstring>
void School::setNume(char* nume)
{
	strcpy_s(this->nume, 20, nume);
}
char* School::getNume()
{
	return this->nume;
}
void School::setNotaMate(int n)
{
	this->notaMate = n;
}
int School::getNotaMate()
{
	return this->notaMate;
}
void School::setNotaEng(int n)
{
	this->notaEng = n;
}
int School::getNotaEng()
{
	return this->notaEng;
}
void School::setNotaIst(int n)
{
	this->notaIst = n;
}
int School::getNotaIst()
{
	return this->notaIst;
}
double School::average()
{
	double x = this->notaMate + this->notaEng + this->notaIst;
	return x / 3;
}