//Sat Jun 20 12:29:46 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
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
}sieve(5e5);
std::vector<int> cnt1(5e5 + 1);
std::vector<int> cnt(5e5 + 1);
void solve() {
    int n, x;
    std::cin >> n >> x;
    std::vector<int> a(n);
    auto res1 = sieve.factorize(x); 
    for (auto [p, c] : res1) {
        cnt1[p] += c;
    }
    std::vector<int> prim;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        auto res = sieve.factorize(a[i]);
        for (auto [p, c] : res)  {
            if (cnt[p] == 0) prim.push_back(p);
            cnt[p] += c;
        }
    }
    i64 ans = 1;
    for (int i = 0; i < n; ++i) {
        auto res = sieve.factorize(a[i]);
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
