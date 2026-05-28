//Thu May 14 04:48:00 PM CST 2026
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
}sieve(2e5 + 1);

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        int m = 0;
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            m = std::max(m, a[i]);
        }
        std::vector<i64> cnt(m+1);
        for (int i = 0; i < n; ++i) {
            cnt[a[i]]++;
        }
        i64 ans = 0;
        i64 temp = 0;
        i64 cntP = 0;
        for (int i = 2; i <= m; ++i) {
            if (sieve.minP[i] == i) {
                cntP += cnt[i];
            }
        }
        for (int i = 2; i <= m; ++i) {
            int p = sieve.minP[i];
            int q = i / p;
            if (p == i) {
                temp += cnt[i] * (cntP - cnt[i]); // p q;
            }else if (sieve.minP[q] == q) {
                if (cnt[i] > 0) {
                    if (p != q) {
                        ans += cnt[i] * (cnt[q] + cnt[p]); // i q ; i q;
                    }else {
                        ans += cnt[i] * cnt[p]; // i p;
                    }
                    ans += cnt[i] * (cnt[i] + 1) / 2; // i i;
                }
            }
        }
        std::cout << ans + temp / 2 << nl;
    }
}
