int majority_element(const int *parr, int len)
{
    int a[1000000] = {0};
    int k = 0;

    for (int i = 0; i < len; ++i)
    {
        ++a[parr[i]];
    }

    for (int i = 0; i < len; ++i)
    {
        if (a[i] > len / 2)
        {
            return i;
        }
    }    
    return -1;
}