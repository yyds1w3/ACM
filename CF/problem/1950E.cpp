//Fri May 29 11:02:03 PM CST 2026
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
    auto check = [](std::string s1, std::string s2) -> int {
        int n = s1.size();
        int c = 0;
        for (int i = 0; i < n; ++i) {
            if (s1[i] != s2[i]) {
                c++;
            }
            if (c > 1) break;
        }
        return c;
    };
    for (int len = 1; len <= n / 2; ++len) {
        if (n % len == 0) {
            std::string s1 = s.substr(0, len);
            std::string s2 = s.substr(len, len);
            int c1 = 0, c2 = 0;
            for (int i = 0; i < n; i += len) {
                int diff = check(s1, s.substr(i, len));
                c1 += diff;
            }
            for (int i = 0; i < n; i += len) {
                int diff = check(s2, s.substr(i, len));
                c2 += diff;
            }
            if (c1 <= 1 || c2 <= 1) {
                std::cout << len << nl;
                return;
            }
        }
    }
    std::cout << n << nl;
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
