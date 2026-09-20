//Fri May 29 08:21:58 PM CST 2026
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
    std::vector<int> p(n);
    for (int i = 0; i < n; ++i) std::cin >> p[i];
    i64 tot = 0;
    for (int i = 1; i <= n; ++i) {
        tot += 1LL * i * (n + 1 - i);
    }
    for (int i = 0; i < n - 1; ++i) {
        if (p[i] < p[i + 1]) {
            tot -= 1LL * (i + 1) * (n - i - 1);
        }
    }
    std::cout << tot << nl;
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
