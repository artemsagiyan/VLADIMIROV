int arrpopcount(const unsigned char *parr, int len)
{
    int sum = 0;

    for (int count = 0; count < len; ++count)
    {
        int solution = parr[count];
        int number = 0;

        while (solution != 0)
        {
            if (solution == 0)
                continue;
            if (solution % 2 == 1)
                ++number;
            solution /= 2;
        }
        sum += number;
    }
    return sum;
}