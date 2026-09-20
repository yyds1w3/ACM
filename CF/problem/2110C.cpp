//Fri May 29 03:50:46 PM CST 2026
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
    std::vector<int> d(n);
    for (int i = 0; i < n; ++i) std::cin >> d[i];
    std::vector<int> l(n + 1), r(n + 1);
    // 0 -> d[0] -> 1 -> d[1] -> 2;
    bool ok = true;
    for (int i = 1; i <= n; ++i) {
        std::cin >> l[i] >> r[i];
        l[i] = std::max(l[i], l[i - 1] + (d[i - 1] == 1 ? 1 : 0)); // 尽量让l小
        r[i] = std::min(r[i], r[i - 1] + (d[i - 1] == 0 ? 0 : 1)); // 尽量让r大
        if (l[i] > r[i]) {
            ok = false;
        }
    }
    if (!ok) {
        std::cout << -1 << nl;
        return;
    } 
    int x = l[n];
    for (int i = n - 1; i >= 0; --i) {
        if (d[i] == -1) {
            int nx = std::max(x - 1, l[i]);
            d[i] = x - nx;
        }
        x -= d[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cout << d[i] << " ";
    }
    std::cout << nl;
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
