#include <assert.h>
#include <stdio.h>

int main()
{
    int x, x1;
    int res, i = 1, nfib = 0, chetchik = 0, j = 0;
    int fib[50] = {0}, chfib[50] = {0};

    res = scanf("%d", &x);
    assert(res == 1);
    x1 = x;
    fib[0] = 1;
    fib[1] = 2;
    do
    {
        ++i;
        fib[i] = fib[i - 1] + fib[i - 2];
        ++nfib;
    } while (fib[i] <= x);

    while (x > 0)
    {
        if (x == fib[nfib])
        {
            chfib[j] = 1;
            break;
        }

        if (x > fib[nfib])
        {
            chfib[j] = 1;
            x -= fib[nfib];
            --nfib;
        }
        else
        {
            chfib[j] = 0;
            --nfib;
        }
        ++j;
    }

    for (int k = 0; k <= j; ++k)
    {   
        ++chetchik;
        printf("%d", chfib[k]);
    }

    for (int f = 0; f <i - chetchik; ++f )
    {
        printf("0");
    }
}