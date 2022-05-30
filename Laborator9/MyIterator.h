#pragma once
#include "Element.h"
template<class T1, class T2>
class MyIterator
{
public:
	elem<T1,T2> *p;
	MyIterator<T1,T2>& operator++() { p++; return (*this);}
	bool operator!=(MyIterator<T1,T2>& m) { return p != m.p; }
	elem<T1,T2> operator*() { return *p; }
};

