//Tue May  5 07:25:44 PM CST 2026
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
    std::vector<int> minP, primes;
    Sieve(int n) {
        minP.resize(n + 1);
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
    int mnp(int n) {
        if (n == 1) return 1;
        return minP[n];
    }
    int mxp(int n) {
        if (n == 1) return 1;
        while (n != minP[n]) {
            n /= minP[n];
        }
        return n;
    }
}sieve(1000000);

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    if (std::is_sorted(a.begin(), a.end())) {
        std::cout << "Bob" << nl;
    }else {
        for (int i = 0; i < n; ++i) {
            if (sieve.mnp(a[i]) != sieve.mxp(a[i])) {
                std::cout << "Alice" << nl;
                return;
            }else {
                a[i] = sieve.mnp(a[i]);
            }
        }
        if (std::is_sorted(a.begin(), a.end())) {
            std::cout << "Bob" << nl;
        }else {
            std::cout << "Alice" << nl;
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
    while (t--) {
        solve();
    }
}
