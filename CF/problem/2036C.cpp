//Sat Jun 20 04:37:18 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#endif
using i64 = long long;
using i128 = __int128;
void solve() {
    std::string s;
    int q;
    std::cin >> s >> q;
    int n = s.size();
    int h = 0;
    for (int i = 0; i < n - 3; ++i) {
        if (s.substr(i, 4) == "1100") {
            h += 1;
        }
    }
    while (q--) {
        int idx, v;
        std::cin >> idx >> v;
        idx--;
        int l = std::max(0, idx - 3);
        int r = std::min(n - 4, idx);
        int d1 = 0;
        for (int i = l; i <= r; ++i) {
            if (s.substr(i, 4) == "1100") {
                d1 += 1;
            }
        }
        s[idx] = '0' + v;
        int d2 = 0;
        for (int i = l; i <= r; ++i) {
            if (s.substr(i, 4) == "1100") {
                d2 += 1;
            }
        }
        h += d2 - d1;
        if (h > 0) {
            std::cout << "YES" << nl;
        }else {
            std::cout << "NO" << nl;
        }
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
