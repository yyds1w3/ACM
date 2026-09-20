//Sat May 30 11:55:09 AM CST 2026
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
    int a, b, c;
    std::cin >> a >> b >> c;
    if (a + 1 != c) {
        std::cout << -1 << nl;
        return;
    }
    if (a + b + c == 1) {
        std::cout << 0 << nl;
        return;
    }
    int cur = 1, nxt = 0, h = 0;
    for (int i = 0; i < a + b; ++i) {
        if (!cur) {
            std::swap(cur, nxt);
            h++;
        }
        nxt++;
        cur--;
        if (i < a) nxt++;
    }
    std::cout << h + 1<< nl;
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
