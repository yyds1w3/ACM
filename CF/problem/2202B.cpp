//Thu Apr 30 07:40:40 PM CST 2026
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
    std::string s;
    std::cin >> s;
    if (n & 1) {
        if (s[0] == 'b') {
            std::cout << "NO" << nl;
            return;
        }
        for (int i = 1; i < n; i += 2) {
            if (s[i] != '?' && s[i] == s[i + 1]) {
                std::cout << "NO" << nl;
                return;
            }
        }
    }else {
        for (int i = 0; i < n; i += 2) {
            if (s[i] != '?' && s[i] == s[i + 1]) {
                std::cout << "NO" << nl;
                return;
            }
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
