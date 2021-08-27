#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ll long long

ll gcd(ll x, ll y);

void swap(ll *a, ll *b);

int main() {
    ll a = 0, b = 0;
    ll N = 0;
    ll res = 0;
    ll nd = 0, nk = 0;

    res = scanf("%lld", &N);
    assert(res == 1);

    // nd = gcd (a, b);

    // nk = a / nd * b;

    //printf("%lld %lld", a, b);

    nk = 2;

    for (ll i = 3; i <= N; ++i) {
        nd = gcd (i, nk);
        nk = i / nd * nk;
    }

    printf("%lld", nk);

    return 0;
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

void swap(ll *a, ll *b) {
    ll tmp = *a;
    *a = *b;
    *b = tmp;
}