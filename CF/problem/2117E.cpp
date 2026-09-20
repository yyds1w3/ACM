//Fri May 29 08:31:04 PM CST 2026
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
    std::vector<int> a(n), b(n);
    std::vector<std::vector<int>> pa(n + 1), pb(n + 1);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        pa[a[i]].push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
        pb[b[i]].push_back(i);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == b[i]) {
            ans = i + 1;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (pa[i].size() >= 2) {
            ans = std::max(ans, pa[i][pa[i].size() - 2] + 1);
        }
        if (pb[i].size() >= 2) {
            ans = std::max(ans, pb[i][pb[i].size() - 2] + 1);
        }
        if (!pa[i].empty() && !pb[i].empty()) {
            int mb = pb[i].back();
            auto ita = std::upper_bound(pa[i].begin(), pa[i].end(), mb - 2);
            if (ita != pa[i].begin()) {
                ans = std::max(ans, *std::prev(ita) + 1);
            }
            int ma = pa[i].back();
            auto itb = std::upper_bound(pb[i].begin(), pb[i].end(), ma - 2);
            if (itb != pb[i].begin()) {
                ans = std::max(ans, *std::prev(itb) + 1);
            }
        }
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
