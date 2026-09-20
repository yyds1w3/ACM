//Thu Jun 11 06:07:47 PM CST 2026
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
    // b => wi = std::min(hi, hi-1);
    // l => wi = std::min(l, r);
    int n;
    std::cin >> n;
    std::vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> h[i];
    }
    for (int i = 0; i < n; ++i) {
        std::vector<int> w(n, 1e9);
        w[i] = 0;
        int l = h[(i + n - 1) % n];
        int r = h[i];
        for (int j = i + 1; j < n; ++j) {
            r = std::max(r, h[j - 1]);
            w[j] = std::min(w[j], r);
        }
        for (int j = 0; j < i; ++j) {
            r = std::max(r, h[(j + n - 1) % n]);
            w[j] = std::min(w[j], r);
        }
        for (int j = i - 1; j >= 0; --j) {
            l = std::max(l, h[j]);
            w[j] = std::min(w[j], l);
        }
        for (int j = n - 1; j > i; --j) {
            l = std::max(l, h[j]);
            w[j] = std::min(w[j], l);
        }
        i64 ans = std::accumulate(w.begin(), w.end(), 0LL);
        std::cout << ans << " ";
    }
    std::cout << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
