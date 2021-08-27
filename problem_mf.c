#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define ll long long

struct Matrix {
    ll a11;
    ll a12;
    ll a21;
    ll a22;
};

void MultMatrix(struct Matrix *m, struct Matrix *k, ll p);

struct Matrix DegreeMatrix(struct Matrix *m, ll k, ll p);

int main() {

    struct Matrix m = {0};
    ll k = 0, p = 0;
    int res = 0;

    res = scanf("%lld %lld %lld %lld %lld %lld", &m.a11, &m.a12, &m.a21, &m.a22, &k, &p);
    assert(res == 6);

    DegreeMatrix(&m, k, p);
    
    return 0;
}

void MultMatrix(struct Matrix *m, struct Matrix *k, ll p) {
    ll b11, b12, b21, b22;

    b11 = (m->a11) * (k->a11) + (m->a12) * (k->a21); 
    b12 = (m->a11) * (k->a12) + (m->a12) * (k->a22); 
    b21 = (m->a21) * (k->a11) + (m->a22) * (k->a21); 
    b22 = (m->a21) * (k->a12) + (m->a22) * (k->a22);

    m->a11 = b11 % p;
    m->a12 = b12 % p;
    m->a21 = b21 % p;
    m->a22 = b22 % p;
}

struct Matrix DegreeMatrix(struct Matrix *m, ll k, ll p) {
    
    struct Matrix acc;
    struct Matrix prod;

    if (k == 1)
        printf("%lld %lld %lld %lld\n", m->a11, m->a12, m->a21, m->a22);

    acc.a11 = m->a11 % p;
    acc.a12 = m->a12 % p;
    acc.a21 = m->a21 % p;
    acc.a22 = m->a22 % p;

    prod.a11 = 1;
    prod.a12 = 0;
    prod.a21 = 0;
    prod.a22 = 1;

    assert(k > 0);

    if (k == 1) {
        return *m;
    }

    for (; k > 0 ;) {
        if (k % 2 == 1) {
            MultMatrix(&prod, &acc, p);
            --k;
        }
        else {
            MultMatrix(&acc, &acc, p);
            k /= 2; 
        }
    }

    printf("%lld %lld %lld %lld\n", prod.a11, prod.a12, prod.a21, prod.a22);

    return prod;
}