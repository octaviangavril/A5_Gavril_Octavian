#include "Math.h"
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
int Math::Add(int a, int b)
{
	return a + b;
}

 int Math::Add(int a, int b, int c)
{
	 return a + b + c;
}

 int Math::Add(double a, double b)
{
	 double s = a + b;
	 return (int)s;
}
 int Math::Add(double a, double b, double c)
{
	 double s = a + b + c;
	 return (int)s;
}

 int Math::Mul(int a, int b)
{
	 int p = a * b;
	 return p;
}

 int Math::Mul(int a, int b, int c)
{
	 int p = a * b * c;
	 return p;
}

 int Math::Mul(double a, double b)
{
	 double p = a * b;
	 return (int)p;
}

 int Math::Mul(double a, double b , double c)
{
	 double p = a * b * c;
	 return (int)p;
}

 int Math::Add(int count, ...)
{
	 int s = 0;
	 va_list vl;
	 va_start(vl, count);
	 for (int i = 0; i < count; i++)
	 {
		 int  val = va_arg(vl, int);
		 s += val;
	 }
	 va_end(vl);
	 return s;
}

 char* Math::Add(const char* sir1, const char* sir2)
{
	 if (sir1 == nullptr or sir2 == nullptr)
		 return nullptr;
	 else
	 {
		 sir1 = (char*) malloc(strlen(sir1)+1);
		 sir2 = (char*) malloc(strlen(sir2)+1);
	 }

}