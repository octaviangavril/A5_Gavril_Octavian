#pragma once
#include <stdlib.h>
#include "Element.h"
#include "MyIterator.h"
template <class T1, class T2>
class Map
{
private:
	elem<T1,T2> *list;
	int count;
public:
	Map() {
		list = (elem<T1, T2>*)(malloc(sizeof(elem<T1, T2>) * 100));
		count = 0;
	}
	~Map()
	{
		list = nullptr;
		delete(list);
	}
	T2& operator[](T1 key)
	{
		for (int i = 0; i < count; i++)
			if (list[i].key == key)
				return list[i].value;
		elem<T1,T2> x;
		x.key = key;
		x.index = count;
		list[count] = x;
		return list[count++].value;
	}
	MyIterator<T1,T2> begin() { MyIterator<T1, T2> tmp; tmp.p = &list[0]; return tmp; }
	MyIterator<T1,T2> end() { MyIterator<T1, T2> tmp; tmp.p = &list[count]; return tmp; }
	void Set(T1 key, T2 value)
	{
		for (int i = 0; i < count; i++)
			if (list[i].key == key)
				list[i].value = value;
	}
	bool Get(const T1& key, T2& value)
	{
		int ok = 0;
		for (int i = 0; i < count; i++)
		{
			if (list[i].key == key)
			{
				for (int j = 0; j < count; j++)
					if (list[j].value == value)
					{
						list[j].value = list[i].value;
						return true;
					}
				ok = 1;
			}
		}
		if (ok == 0)
			return false;
	}
	int Count() { return count; }
	void Clear()
	{
		list = nullptr;
		delete(list);
		list = (elem<T1, T2>*)(malloc(sizeof(elem<T1, T2>) * 100));
		count = 0;
	}
	bool Delete(const T1& key)
	{
		int ok = 0;
		for(int i=0;i<count;i++)
			if (list[i].key == key)
			{
				ok = 1;
				for (int j = i; j < count; j++)
					list[i] = list[i + 1];
				count--;
				return true;
			}
		if (ok == 0) return false;
	}
	bool Includes(const Map<T1, T2>& map)
	{
		for (int i = 0; i < map.count; i++)
		{
			int ok = 0;
			for (int j = 0; j < count; j++)
				if (map.list[i].key == list[j].key)
					ok = 1;
			if (ok == 0)
				return false;
		}
		return true;
	}
};

