void fill_sieve(struct sieve_t *sv) {
    sv->s[0] |= 1u;
    sv->s[0] = sv->s[0] | 2u;
    for (int i = 2; i * i <= sv->n * 8; ++i) {
        if ((sv->s[i / 8] >> (i % 8)) & 1u) {
            continue;
        }
        for (int j = i * i; j < sv->n * 8; j += i) {
            sv->s[j/8] = sv->s[j / 8] | (1u << (j % 8));
        }        
    }
}

int is_prime(struct sieve_t *sv, unsigned n) {
    if ((sv->s[n / 8] >> (n % 8)) & 1u)
        return 0;
    return 1;
}