//Sun May 31 07:59:50 PM CST 2026
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
}sieve(1e7);
std::vector<i64> sumP(4e5 + 1);
void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.rbegin(), a.rend());
    std::vector<i64> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }
    for (int k = n; k >= 0; --k) {
        if (pref[k] >= sumP[k]) {
            std::cout << n - k << nl;
            return;
        }
    }

}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    int t;
    std::cin >> t;
    for (int i = 0; i < 4e5; ++i) {
        sumP[i + 1] = sumP[i] + sieve.primes[i]; 
    }
    while (t--) solve();
}
