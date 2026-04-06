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
};
int dayInMonth[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool is_leap(int x) {
    return (x % 4 == 0 && x % 100 != 0) || (x % 400 == 0);
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int t;
    std::cin >> t;
    Sieve sieve(10000);
    std::vector<std::string> valid;
    std::vector<int> valid_mmdd;
    for (int m = 1; m <= 12; ++m) {
        for (int d = 1; d <= dayInMonth[m]; ++d) {
            if (sieve.is_prime(d) && sieve.is_prime(m * 100 + d)) {
                valid_mmdd.push_back(m * 100 + d);
            }
        }
    }
    for (int y = 1; y <= 9999; ++y) {
        bool is_lea = is_leap(y);
        for (int mmdd : valid_mmdd) {
            if (!is_lea && mmdd == 229) continue;
            int yymmdd = 10000 * y + mmdd;
            if (sieve.is_prime(yymmdd)) {
                std::string ds = std::to_string(yymmdd);
                ds = std::string(8-ds.size(), '0') + ds;
                valid.push_back(ds);
            }
        }
    }
    while (t--) {
        std::string s;
        std::cin >> s;
        int ans = 0;
        for (auto& date : valid) {
            bool match = true;
            for (int i = 0; i < 8; ++i) {
                if (s[i] != '-' && s[i] != date[i]) {
                    match = false;
                    break;
                }
            }
            if (match) ans++;
        }
        std::cout << ans << nl;
    }
}
