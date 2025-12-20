#include <bits/stdc++.h>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
const int MAXN = 1e8 + 1;
const int MAXM = 6e6 + 1;
bool not_prime[MAXN];
int primes[MAXM];
void euler_sieve(int n){
    int cnt = 0;
    not_prime[0] = not_prime[1] = 0;
    for (int i = 2; i <= n; ++i){
        if (!not_prime[i]) primes[cnt++] = i;
        for (int p : primes){
            if (1LL * i * p > n) break;
            not_prime[i * p] = true;
            if (i % p == 0) break;
        }
    }
}
void solve() {
    int n, q;
    cin >> n >> q;
    euler_sieve(n);
    for (int i = 1; i <= q; ++i){
        int x;
        cin >> x;
        cout << primes[x - 1] << "\n";
    }

    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
