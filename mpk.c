#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct Poly 
{
    int len;
    int *mas;
};

void readArr(struct Poly *poly);
void sum_poly(struct Poly *poly1, struct Poly *poly2);
void dev_poly(struct Poly *poly1, struct Poly *poly2);
void mult_digr(struct Poly *poly, int digr);
struct Poly mult_prodva(struct Poly *poly1, struct Poly *poly2, int n);
struct Poly mult(struct Poly *lhs, struct Poly *rhs);
struct Poly first_half(struct Poly *poly);
struct Poly second_half(struct Poly *poly);

int main()
{   
    int res = 0;
    int n = 0;
    int count = 0;
    int k = 0;

    struct Poly poly1;
    struct Poly poly2;

    res = scanf("%d %d", &poly1.len, &poly2.len);
    assert(res == 2);

    n = poly1.len;

    poly1.mas = (int *)calloc(n, sizeof(int));
    poly2.mas = (int *)calloc(n, sizeof(int));

    readArr(&poly1);
    readArr(&poly2);

    poly1 = mult_prodva(&poly1, &poly2, n);

    k = 2 * n - 2;

    do {
        if (poly1.mas[k] != 0)
            break;
        --k;
    }while(poly1.mas[k] == 0);

    for (int i = 0; i <=  k; ++i)
    {
        printf("%d ", poly1.mas[i]);
    }


    free(poly1.mas);
    free(poly2.mas);
}
void readArr(struct Poly *poly)
{
    int res = 0;

    for (int i = 0; i < poly->len; ++i)
    {
        res = scanf("%d", poly->mas + i);
        assert(res == 1);
    }
}

void sum_poly(struct Poly *poly1, struct Poly *poly2)
{
    for (unsigned i = 0; i < 2 * poly1->len - 1; ++i)
    {
        poly1->mas[i] = poly1->mas[i] + poly2->mas[i];
    }
}

void dev_poly(struct Poly *poly1, struct Poly *poly2)
{
    for (unsigned i = 0; i < 2 * poly1->len - 1; ++i)
    {
        poly1->mas[i] = poly1->mas[i] - poly2->mas[i];
    }
}

void mult_digr(struct Poly *poly, int sdvig)
{
    for (int i = poly->len - 1; i >= 0; --i)
    {
        poly->mas[i + sdvig] = poly->mas[i];
        poly->mas[i] = 0;
    }
}

struct Poly mult(struct Poly *lhs, struct Poly *rhs)
{
    struct Poly ret = {};
    ret.len = lhs->len + rhs->len;
    ret.mas = (int *)calloc(2 * ret.len + 3, sizeof(int));

    for (unsigned i = 0; i < lhs->len; ++i)
        for (unsigned j = 0; j < rhs->len; ++j)
        {
            ret.mas[i + j] += lhs->mas[i] * rhs->mas[j];
        }
    return ret;
}

struct Poly first_half(struct Poly *poly)
{
    struct Poly ans = {};
    ans.len = poly->len / 2;
    ans.mas = (int *)calloc(poly->len + 1, sizeof(int));

    for (int i = 0; i < ans.len; ++i)
    {
        ans.mas[i] = poly->mas[i];
    }

    return ans;
}

struct Poly second_half(struct Poly *poly)
{
    struct Poly ans = {};
    ans.len = poly->len / 2;
    ans.mas = (int *)calloc(poly->len + 1, sizeof(int));

    for (int i = 0; i < ans.len; ++i)
    {
        ans.mas[i] = poly->mas[i + ans.len];
    }

    return ans;
}

struct Poly mult_prodva(struct Poly *poly1, struct Poly *poly2, int n)
{
    struct Poly pr1 = {};
    struct Poly pol1_1 = {};
    struct Poly pol1_2 = {};
    struct Poly pol2_1 = {};
    struct Poly pol2_2 = {};
    struct Poly pr2 = {};
    struct Poly pr3 = {};
    struct Poly answer = {};

    if (n <= 2)
    {
        return mult(poly1, poly2);
    }
}
