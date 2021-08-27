#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define ll long long

ll gcd (ll a, ll b, ll *x, ll *y);

void swap(ll *a, ll *b);

int main()
{
	ll x, y;
	ll a, b, d;
	int res = 0;

	res = scanf("%lld %lld", &x, &y);
	assert(res == 2);

	d = gcd(x, y, &a, &b);


	if (x > y)
		printf("%lld %lld %lld", a, b, d);
	else printf("%lld %lld %lld", b, a, d);
	
	return 0;
}

ll gcd (ll a, ll b, ll *x, ll *y) 
{
	ll x1, y1;
	ll d;

	if (b > a) 
	{
		swap(&a, &b);
	}

	if (b == 0)
	{
		*x = 1;
		*y = 0;
		return a;
	}

	d = gcd(a % b, b, &x1, &y1);
	
	*x = y1;
	*y = x1 - (a / b) * y1;

	return d;

}

void swap(ll *a, ll *b) 
{
	ll tmp = *a;
	*a = *b;
	*b = tmp;
}