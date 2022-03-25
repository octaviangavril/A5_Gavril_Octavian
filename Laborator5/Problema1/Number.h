#pragma once
class Number

{

	char* nr;
	int baza;

public:

	Number(const char* value, int base); // where base is between 2 and 16
	Number(int value); //value will be in base 10
	~Number();

	Number(const Number& ex);
	Number(const Number&& ex);

	friend Number operator+(Number ex1,Number ex2);
	friend Number operator-(Number ex1,Number ex2);
	void operator+=(Number ex);
	void operator-=(Number ex);
	void operator--();
	void operator--(int value);
	char operator[](int index);
	Number& operator=(Number&& ex);
	Number& operator=(int value);
	Number& operator=(const char* value);
	bool operator<(Number ex);
	bool operator>(Number ex);
	bool operator<=(Number ex);
	bool operator>=(Number ex);
	bool operator==(Number ex);
	// rezultatul va fi in baza cea mai mare


	void SwitchBase(int newBase);

	void Print();

	int  GetDigitsCount(); // returns the number of digits for the current number

	int  GetBase(); // returns the current base

};

