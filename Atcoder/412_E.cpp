#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#define debug_range(...) 43
#endif
using i64 = long long;
using i128 = __int128;

struct Sieve {
    int n;
    std::vector<int> minP, primes;

    Sieve(int n_) : n(n_), minP(n_ + 1) {
        for (int i = 2; i <= n; ++i) {
            if (minP[i] == 0) {
                primes.push_back(i);
                minP[i] = i;
            }
            for (int p : primes) {
                if (i * p > n) break;
                minP[i * p] = p;
                if (p == minP[i]) break;
            }
        }
    }
    // x in [n, n^2]
    bool is_prime(int x) const {
        if (x < 2) return false;
        if (x <= n) return minP[x] == x;
        for (int p : primes) {
            if (1LL * p * p > x) break;
            if (x % p == 0) return false;
        }
        return true;
    }

    std::vector<std::pair<int, int>> factorize(int x) const {
        std::vector<std::pair<int, int>> res;
        while (x > 1) {
            int p = minP[x];
            int cnt = 0;
            while (minP[x] == p) {
                x /= p;
                cnt++;
            }
            res.push_back({p, cnt});
        }
        return res;
    }
};

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    i64 L, R;
    std::cin >> L >> R;

    int mxP = std::sqrt(R) + 1;
    Sieve sieve(mxP);

    int ans = 1;
    i64 start = L + 1 ;
    i64 end = R;
    int n = end - start + 1;
    std::vector<bool> isP(n, true);
    for (int p : sieve.primes) {
        i64 fir = (start + p - 1) / p * p;
        if (fir == p) fir += p;
        for (i64 j = fir; j <= end; j += p) {
            isP[j - start] = false;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (isP[i]) {
            ans++;
        }
    }
    for (int p : sieve.primes) {
        i64 power = 1LL * p * p;
        while (power <= R) {
            if (power >= start) {
                ans++;
            }
            if (R / p < power) break;
            power *= p;
        }
    }
    std::cout << ans << nl;

}
