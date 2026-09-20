//Wed Jul 22 03:26:41 PM CST 2026
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
    std::vector<int> cnt(3);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            char c;
            std::cin >> c;
            if (c == '?') continue;
            cnt[c - 'A']++;
        }
    }
    for (int i = 0; i < 3; ++i) {
        if (cnt[i] == 2) {
            std::cout << (char)('A' + i) << nl;
            return;
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
