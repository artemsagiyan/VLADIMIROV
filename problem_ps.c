void fill_sieve(struct sieve_t *sv) {
    for (int i = 2; i < sqrt(sv->n) + 1; ++i) {
        if (sv->s[i] == 1) continue;

        for (int j = 2 * i; j < sv->n; j += i) {
            sv->s[j] = 1;
        }
    }
}

int nth_prime(struct sieve_t *sv, int N) {
    
    int i = 0;
    int k = 2;

    while (i != N) {
        if (sv->s[k] == 0) {
            ++i;
        }
        ++k;
    }

    return k - 1;
}