#pragma once
class School
{
private:
	char nume[20];

	int notaMate, notaEng, notaIst;

public:
	void setNume(char* nume);
	char* getNume();

	void setNotaMate(int n);
	int getNotaMate();

	void setNotaEng(int n);
	int getNotaEng();

	void setNotaIst(int n);
	int getNotaIst();

	double average();
};

