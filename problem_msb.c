#include <stdio.h>
#include <assert.h>

int convert_two(int *arr, unsigned long long number);

int main()
{
    unsigned long long N = 0;
    int arr[100] = {0};
    int res = 0, result = 0;
    
    res = scanf("%llu", &N);
    assert(res == 1);

    result = convert_two(arr, N);
    printf("%d", result);
}

int convert_two(int *arr, unsigned long long number)
{
    unsigned long long i = 0;
    if (number == 1)
        return 0;
    while (number != 0)
    {
        arr[i] = number % 2;
        number /= 2;
        ++i;
    }
    for(; i > 0; --i)
    {
        if (arr[i] == 1)
            return i;
    }
    return -1;
}