//Sat Jul 25 09:26:38 PM CST 2026
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
    std::cin >> s;
    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int len = 0; i - len >= 0 && i + len < n; ++len) {
            if (s[i + len] != s[i - len]) {
                cnt++;
                if (cnt > 1) break;
            }
            ans++;
        }
    }
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int len = 0; i - len >= 0 && i + len + 1 < n; ++len) {
            if (s[i - len] != s[i + len + 1]) {
                cnt++;
                if (cnt > 1) break;
            }
            ans++;
        }
    }
    std::cout << ans << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    solve();
}
