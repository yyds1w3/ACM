//Sun May 31 10:41:29 AM CST 2026
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
    i64 ans = 0;
    i64 c1 = 0;
    i64 cap = 0;
    int kind = 0;
    i64 tot = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        if (x == 1) {
            c1++;
        }else {
            kind++;
            ans += x;
            cap += x / 2 - 1;
        }
        tot += x;
    }
    if (c1 == n || tot < 3) {
        std::cout << 0 << nl;
    }else {
        if (kind == 1) {
            std::cout << std::min(cap + 1, c1) + ans << nl;
        }else {
            std::cout << std::min(cap, c1) + ans << nl;
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
    while (t--) solve();
}
