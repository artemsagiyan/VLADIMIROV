#include <assert.h> 
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define ll long long

ll Nsimple(ll N);

bool CheckSimple(ll N);

int main() {
    ll N = 0;
    ll ans = 0;
    int res = 0;

    res = scanf("%lld", &N);

    ans = Nsimple(N);

    printf("%lld\n", ans);
    
}

bool CheckSimple(ll N) {
    
    if (N == 2)
        return true;

    for (ll  i = 2; i <= sqrt(N) + 1; ++i) {
        if (N % i == 0)
            return false;
    }
    return true;
}

ll Nsimple(ll N) {
    
    ll k = 0;
    ll i;

    for ( i = 2; ; ++i) {
        if (CheckSimple(i) == 1)
            ++k;
        if (k == N)
            break;
    }
    return i;
}