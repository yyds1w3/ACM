//Fri Jun 12 10:41:05 PM CST 2026
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
    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;
    for (int i = 0; i < n - k; ++i) {
        if (s[i] == '1') {
            s[i] = '0';
            if (s[i + k] == '1') {
                s[i + k] = '0';
            }else {
                s[i + k] = '1';
            }
        }
    }
    int c = std::count(s.begin(), s.end(), '0');
    if (c == (int)s.size()) {
        std::cout << "YES" << nl;
    }else {
        std::cout << "NO" << nl;
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
