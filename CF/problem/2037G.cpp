//Thu Jun 18 02:06:05 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#endif
using i64 = long long;
using i128 = __int128;
const int MOD = 998244353;
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
void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    Sieve sieve(1e6);
    std::vector<i64> v(1e6 + 1);
    
    i64 dp = 0;
    for (int i = 0; i < n; ++i) {
        int temp = a[i];
        std::vector<int> pri;
        while (temp > 1) {
            int p = sieve.minP[temp];
            pri.push_back(p);
            while (sieve.minP[temp] == p) temp /= p;
        }
        int k = pri.size();
        dp = 0;
        if (i == 0) {
            dp = 1;
        }else {
            for (int mask = 1; mask < (1 << k); ++mask) {
                int d = 1;
                int bits = 0;
                for (int j = 0; j < k; ++j) {
                    if ((mask >> j) & 1) {
                        d *= pri[j];
                        bits++;
                    }
                }
                if (bits % 2 == 1) {
                    dp = (dp + v[d]) % MOD;
                }else {
                    dp = (dp - v[d] + MOD) % MOD;
                }
            }
        }
        for (int mask = 1; mask < (1 << k); ++mask) {
            int d = 1;
            for (int j = 0; j < k; ++j) {
                if ((mask >> j) & 1) {
                    d *= pri[j];
                }
            }
            v[d] = (v[d] + dp) % MOD;
        }
    }
    std::cout << dp << nl;

}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    solve();
}
