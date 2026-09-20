//Fri May 29 07:34:56 PM CST 2026
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
    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
        int lft = 0, rgt = 0;
        for (int j = 0; j < i; ++j) {
            if (p[j] > p[i]) lft++;
        }
        for (int j = i + 1; j < n; ++j) {
            if (p[j] > p[i]) rgt++;
        }
        ans += std::min(lft, rgt);
    }
    std::cout << ans << nl;
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
