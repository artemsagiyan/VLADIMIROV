#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define ll long long

void swap (ll *a, ll *b)
{
	ll tmp = *a;
	*a = *b;
	*b = tmp;
}

ll gcd (ll x, ll y) {
	ll q = 0;
	ll x1 = x, y1 = y;

	do 
	{
		if (y1 > x1) 
			swap(&y1, &x1);

		q = x1 % y1;
		if (q == 0)	
			return y1;
		x1 = q;
	} while (q != 0);

	return q;
}

int main() 
{
	ll x = 0, y = 0, g = 0;
	int res = 0;

	res = scanf("%llu %llu", &x, &y);
	assert(res == 2);

	g = gcd(x, y);

	printf("%llu\n", g);
	
	return 0;
}