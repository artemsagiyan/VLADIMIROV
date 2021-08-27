#include <assert.h>
#include <stdio.h>
#include <math.h>

int fib_pizo(int m);

int fib_mod(int x, int m);

int main() {
	unsigned long long x, m;
	int res = 0, period = 0, mod = 0;

	res = scanf("%llu %llu", &x, &m);
	assert(res == 2);
	period = fib_pizo(m);
	x = x % period;
	mod = fib_mod(x, m) % m;
	printf("%d %d", mod, period);
}



int fib_pizo(int m) {
	int f_0 = 0, f_1 = 1, f_prom = 1;
	int per = 1;
	while (1 == 1)
	{
		f_0 = f_1;
		f_1 = f_prom;
		f_prom = (f_0 + f_1) % m;
		++per;
		if (f_prom == 1 && f_1 == 0)
			break;
	}
	return per;
}

int fib_mod(int x1, int m1) {
	int f_0 = 0, f_1 = 1, f_prom = 1;
	int i = 2;
	int k = fib_pizo(m1);
	if (x1 == 0)
		return 0;
	while (i != (x1 % k)) {
		f_0 = f_1;
		f_1 = f_prom;
		f_prom = f_0 % m1 + f_1 % m1;
		++i;
	}
	return f_prom;
}