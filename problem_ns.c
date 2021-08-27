#include <assert.h>
#include <stdio.h>
#include <math.h>

int max(int a, int b);

int binpow(int c, int n);

int main()
{
	int x, y;
	int res;
	int i = 0;
	int arr[1013] = {0};

	res = scanf("%d %d", &x, &y);
	assert(res == 2);

	while (x > 0)
	{
		arr[i] = x % y;
		x /= y;
		if (x == 0)
			break;
		++i;
	}
	for (int j = i; j >= 0; --j)
	{
		printf("%d", arr[j]);
	}
}