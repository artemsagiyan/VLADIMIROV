#include <stdio.h>
#include <assert.h>

#define kek unsigned long long

kek fib(int N, int x);

int main()
{
    int N = 0, x = 0;
    kek ans = 0;
    int res = 0;

    res = scanf("%d %d", &N, &x);
    assert(res == 2);

    ans = fib(N, x);

    printf("%llu", ans);

    return 0;
}

kek fib(int N, int x)
{
    int i = 1;
    kek f1 = 0, f2 = 1, f3 = 1;

    if (N == 0) 
        return 0;

    while (i != N)
    {
        f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
        f1 %= x;
        f2 %= x;
        f3 %= x;
        ++i;
    }

    return f3;
}