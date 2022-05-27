#include "catch_amalgamated.hpp"

void sort(int v[],int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (v[i] > v[j])
			{
				int aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
}
bool is_sorted(int v[], int n)
{
	//sort(v, n);
	for (int i = 0; i < n - 1; i++)
		if (v[i] > v[i+1])
			return false;
	return true;
}
bool is_prime(int x)
{
	if (x < 2)
		return false;
	for (int d = 2; d * d <= x; d++)
		if (x % d == 0)
			return false;
	return true;
}

TEST_CASE("primes")
{
	REQUIRE(is_prime(2));
	REQUIRE_FALSE(is_prime(0));
	REQUIRE_FALSE(is_prime(25));
	REQUIRE(is_prime(3));
	REQUIRE(is_prime(19));
}
TEST_CASE("sorted")
{
	int a[5] = {1,2,3,4,5};
	REQUIRE(is_sorted(a, 5));
	int b[5] = { 1,2,4,3,5 };
	REQUIRE_FALSE(is_sorted(b, 5));
	int c[5] = { 5,6,7,8,9 };
	REQUIRE(is_sorted(c, 5));
	int d[5] = { 1,3,4,2,5 };
	REQUIRE_FALSE(is_sorted(d, 5));
}
