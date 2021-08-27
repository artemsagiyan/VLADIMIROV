#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Poly
{
    unsigned n;
    unsigned *p;
};

void mult(struct Poly *lhs, struct Poly *rhs, struct Poly *ret);

int main()
{
    unsigned len1 = 0, len2 = 0;
    unsigned num = 0;
    int res = 0;

    struct Poly lhs;
    struct Poly rhs;
    struct Poly ret;

    res = scanf("%d %d", &len1, &len2);
    assert(res == 2);

    lhs.n = len1;
    lhs.p = (unsigned *)calloc(lhs.n, sizeof(unsigned));

    for (unsigned i = 0; i < len1; ++i)
        scanf("%d", &lhs.p[i]);

    rhs.n = len2;
    rhs.p = (unsigned *)calloc(rhs.n, sizeof(unsigned));

    for (unsigned i = 0; i < len2; ++i)
        scanf("%d", &rhs.p[i]);

    ret.n = len1 + len2 - 1;
    ret.p = (unsigned *)calloc(ret.n, sizeof(unsigned));

    mult(&lhs, &rhs, &ret);

    for (num = ret.n - 1; num != 0; --num)
        if (ret.p[num] != 0)
            break;

    for (unsigned i = 0; i <= num; ++i)
        printf("%d ", ret.p[i]);
}

void mult(struct Poly *lhs, struct Poly *rhs, struct Poly *ret)
{

    for (unsigned i = 0; i < lhs->n; ++i)
        for (unsigned j = 0; j < rhs->n; ++j)
        {
            ret->p[i + j] += lhs->p[i] * rhs->p[j];
        }
}