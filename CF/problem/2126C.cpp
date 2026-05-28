//Tue May 19 04:13:42 PM CST 2026
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
    int n, k;
    std::cin >> n >> k;
    std::vector<int> h(n);
    for (int i = 0; i < n; ++i) std::cin >> h[i];
    int hi = h[k - 1];
    std::sort(h.begin(), h.end());
    h.erase(std::unique(h.begin(), h.end()), h.end());
    int s = std::lower_bound(h.begin(), h.end(), hi) - h.begin();
    for (int i = s; i < h.size() - 1; ++i) {
        if (h[i + 1] - h[i] > hi) {
            std::cout << "NO" << nl;
            return;
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
