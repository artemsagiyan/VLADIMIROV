#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct sieve_t {
  long long n;
  unsigned char *s;
};

long long mink(long long a, long long b);

void fill_sieve(struct sieve_t *sv);

long long is_prime(struct sieve_t *sv, unsigned n);

long long Convert(long long *to, long long v); 

long long Sdvig(long long *arr, long long k, long long count);

long long Made(long long count, long long *arr);

bool CheckSimpleCircle(struct sieve_t *sv, long long *arr, long long count);

long long PoiskNeerCircle(long long *arr, struct sieve_t *sv, long long N);

void swap(long long *a, long long *b);

void Reverse(long long *arr, long long count);

int main() { 
    long long N = 0; 
    long long p = 0;
    long long res = 0;

    long long *arr = NULL;

    struct sieve_t sv;

    res = scanf("%llu", &N);
    assert(res == 1);

    sv.n = 4000000 / 8 + (4000000 % 8 != 0);
    sv.s = (unsigned char *) calloc(sv.n, sizeof(unsigned char));

    arr = (long long *)calloc(30, sizeof(long long));
    assert(arr);

    fill_sieve(&sv);

    p = PoiskNeerCircle(arr, &sv, N);

    printf("%lld \n", p);

    free(arr);
    free(sv.s);
}

void fill_sieve(struct sieve_t *sv) {
    sv->s[0] |= 1u;
    sv->s[0] = sv->s[0] | 2u;
    for (long long i = 2; i * i <= sv->n * 8; ++i) {
        if ((sv->s[i / 8] >> (i % 8)) & 1u) {
            continue;
        }
        for (long long j = i * i; j <= sv->n * 8; j += i) {
            sv->s[j/8] = sv->s[j / 8] | (1u << (j % 8));
        }        
    }
}

long long is_prime(struct sieve_t *sv, unsigned n) {
    if ((sv->s[n / 8] >> (n % 8)) & 1u)
        return 0;
    return 1;
}

long long Convert(long long *to, long long v) {
    long long count = 0;
    long long V = v;

    while (V != 0) {
        to[count] = V % 10;
        V /= 10;
        count++;
    }

    return count;
} 

long long Sdvig(long long *arr, long long k, long long count) {

    for (long long i = count - 1; i >= 0; --i) {
        arr[i + k] = arr[i];
    }
    for (long long i = count; i < count + k; ++i) {
        arr[i - count] = arr[i]; 
        arr[i] = 0;
    }
    return 0;
}

long long Made(long long count, long long *arr) {
    long long num = 0;
    long long c = 1;
    for (long long i = 0; i < count; ++i) {
        num += arr[i] * c;
        c *= 10;
    }
    return num;
}

bool CheckSimpleCircle(struct sieve_t *sv, long long *arr, long long count) {
    long long N = 0;
    bool k = 0;

    N = Made(count, arr);

    if (count == 1 || (!is_prime(sv, N)))
        return 0;

    for (long long i = 1; i <= count; ++i) {
        N = Made(count, arr);
        Sdvig(arr, 1, count);
        k = is_prime(sv, N);
        if (!k) return 0;
        N = 0;
    }
    return 1;
}

long long PoiskNeerCircle(long long *arr, struct sieve_t *sv, long long N) {

    long long min_1 = 0, min_2 = 0;
    long long p = 0;
    long long f = 0;

    for (long long i = N; i >= 2; --i) {
        f = Convert(arr, i);
        p = CheckSimpleCircle(sv, arr, f);

        if (p == 1) {
            min_1 = i;
            break;
        }

    }

    for (long long i = N; ; ++i) {
        if (i - N > N - min_1)
            return min_1;
        f = Convert(arr, i);
        p = CheckSimpleCircle(sv, arr, f);

        if (p == 1) {
            min_2 = i;
            break;
        }

    }

    // printf("MIN_1: %lld\n", min_1);
    // printf("MIN_2: %lld\n", min_2);

    if (N - min_1 < min_2 - N)
        return min_1;
    return min_2;
}

long long mink(long long a, long long b) {
    if (a < b)
        return a;
    return b;
}

void swap(long long *a, long long *b) {
    long long tmp = *a;
    *a = *b;
    *b = tmp;
}

void Reverse(long long *arr, long long count) {
    for (long long i = 0; i < count / 2; ++i) {
        swap(&arr[i], &arr[count - i - 1]);
    }
}