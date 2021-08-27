int next_turn(int total, int possible)
{
    int fib[50] = { 0 }, c = 0;
    int ind = 0, num_fib = 0;

    fib[0] = 1;
    fib[1] = 2;
    do
    {
        ++ind;
        fib[ind] = fib[ind - 1] + fib[ind - 2];
        ++num_fib;
    } while (fib[ind] <= total);

    if (total == fib[num_fib - 1])
        return 1;

    while (fib[num_fib - 1] != total)
    {
        if (fib[num_fib - 1] < total)
        total -= fib[num_fib - 1];
        --num_fib;
    }

    if (fib[num_fib - 1] <= 2 * possible)
        return fib[num_fib - 1];

    c = next_turn(fib[num_fib - 1], possible);
    return c;
}