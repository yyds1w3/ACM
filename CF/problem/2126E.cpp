//Tue May 19 04:24:04 PM CST 2026
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

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> p(n), s(n);
    for (int i = 0; i < n; ++i) std::cin >> p[i];
    for (int i = 0; i < n; ++i) std::cin >> s[i];
    auto lcm = [](int a, int b) -> i64 {
        return 1LL * a * b / std::gcd(a, b);
    };
    std::vector<i64> ans(n);
    for (int i = 0; i < n; ++i) {
        ans[i] = lcm(p[i], s[i]);
    }
    std::vector<i64> pi(n), si(n);
    pi[0] = ans[0];
    if (pi[0] != p[0]) {
        std::cout << "NO" << nl;
        return;
    }
    for (int i = 1; i < n; ++i) {
        pi[i] = std::gcd(pi[i - 1], ans[i]); 
        if (pi[i] != p[i]) {
            std::cout << "NO" << nl;
            return;
        }
    }
    si[n - 1] = ans[n - 1];
    if (si[n - 1] != s[n - 1]) {
        std::cout << "NO" << nl;
        return;
    }
    for (int i = n - 2; i >= 0; --i) {
        si[i] = std::gcd(si[i + 1], ans[i]);
        if (si[i] != s[i]) {
            std::cout << "NO" << nl;
            return;
        }
    }
    std::cout << "YES" << nl;
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
