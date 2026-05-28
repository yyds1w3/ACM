//Fri May 22 07:31:53 PM CST 2026
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
    int n, s, m;
    std::cin >> n >> s >> m;
    std::vector<std::pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i].first >> a[i].second;
    }
    std::sort(a.begin(), a.end());
    for (int i = 0; i <= n; ++i) {
        if (i == 0) {
            if (a[i].first >= s) {
                std::cout << "YES" << nl;
                return;
            }
        }else if (i == n) {
            if (m - a[n-1].second >= s) {
                std::cout << "YES" << nl;
                return;
            }
        }else {
            if (a[i].first - a[i-1].second >= s) {
                std::cout << "YES" << nl;
                return;
            }
        }
    }
    std::cout << "NO" << nl;

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
