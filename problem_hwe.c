void setbit(unsigned char *a, int k) {
    *a |= (1 << (k % 8));
}

int getbit(unsigned char a, int k) {
    return (a >> (k % 8)) & 1;
}

void fill_sieve(struct sieve_t *sv) {
    setbit(sv->mod1, 0);

    for (int i = 7; i * i < sv->n * 48; i += 6) {
        if (!getbit(sv->mod1[i / 48], (i / 6) % 8)) {
            //printf("%d kek\n", i);
            for (int j = i * i; j < sv->n * 48; j += i) {
                //printf("j:____%d\n", j);
                if ((j - 1) % 6 == 0) {
                    setbit(&sv->mod1[j / 48], (j / 6) % 8);
                }
                if ((j - 5) % 6 == 0) {
                    setbit(&sv->mod5[j / 48], (j / 6) % 8);
                }
            }
        }
    }

    for (int i = 5; i * i < sv->n * 48; i += 6) {
        if (!getbit(sv->mod5[i / 48], (i / 6) % 8)) {
            //printf("%d kek\n", i);
            for (int j = i * i; j < sv->n * 48; j += i) {
                //printf("j:____%d\n", j);
                if ((j - 5) % 6 == 0) {
                    setbit(&sv->mod5[j / 48], (j / 6) % 8);
                }
                if ((j - 1) % 6 == 0) {
                    setbit(&sv->mod1[j / 48], (j / 6) % 8);
                }
            }
        }
    }

}

int is_prime(struct sieve_t *sv, unsigned n) {
    if (n == 2 || n == 3)
        return 1;
    if ((n - 1) % 6 == 0) {
        return 1 - getbit(sv->mod1[n / 48], (n / 6) % 8);
    }
    if ((n - 5) % 6 == 0) {
        return 1 - getbit(sv->mod5[n / 48], (n / 6) % 8);
    }
    return 0;
}