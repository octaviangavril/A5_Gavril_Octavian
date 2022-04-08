#pragma once

template<typename T>
int functieDeComparare(T a, T b)
{
	return a > b;
}

template<typename T>
int functieDeEgalitate(T a, T b)
{
	return a - 1 == b;
}

template <class T>
class VECTOR
{
private:
	T* v;
	int nr_elem;
	int nr_max_of_elements;
public:
	VECTOR() {
		nr_elem = 0;
		nr_max_of_elements = 100;
		v = (T*)(malloc(sizeof(T) * nr_max_of_elements));
	}
	void push(T value) {
		if (nr_elem < nr_max_of_elements)
			v[nr_elem++] = value;
	}
	T pop() {
		return v[nr_elem-1];
	}
	void remove(int index) {
		
		if (nr_elem > 0)
		{
			if (index < nr_elem)
			{
				for (int i = index; i < nr_elem - 1; i++)
					v[i] = v[i + 1];
				nr_elem--;
			}
			else printf("Index invalid!");
		}
		
	}
	void insert(T elem, int index)
	{
		if (nr_elem < nr_max_of_elements)
		{		for (int i = nr_elem; i > index; i--)
				v[i] = v[i - 1];
		v[index] = elem;
		nr_elem++;
		}
	}
	void sort(int (* callback)(T,T))
	{
		if (callback != nullptr)
		{
         for (int i = 0; i < nr_elem - 1; i++)
			for (int j = i + 1; j < nr_elem; j++)
				if (callback(v[i], v[j]))
				{
					T aux;
					aux = v[i];
					v[i] = v[j];
					v[j] = aux;
				}
		}
		else
		{
			for (int i = 0; i < nr_elem - 1; i++)
				for (int j = i + 1; j < nr_elem; j++)
					if (v[i] < v[j])
					{
						T aux;
						aux = v[i];
						v[i] = v[j];
						v[j] = aux;
					}
		}
	}
	T get(int index)
	{
		return v[index];
	}
	void set(int index, T elem)
	{
		v[index] = elem;
	}
	int count()
	{
		return this->nr_elem;
	}
	int firstIndexOf(int  (*callback)(T,T),T elem)
	{
		if (callback != nullptr)
		{
		for (int i = 0; i < nr_elem; i++)
			if (callback(v[i], elem))
				return i;
		}
		else
		{
			for (int i = 0; i < nr_elem; i++)
				if (v[i] == elem)
					return i;
		}
	}
};