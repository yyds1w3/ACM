//Wed Apr 29 12:33:38 PM CST 2026
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
    std::vector<int> a(n);
    std::vector<std::pair<int, int>> v;
    int c0 = 0, c1 = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        v.push_back({a[i], i});
        if (a[i] & 1) c1++;
        else c0++;
    }
    if (std::is_sorted(a.begin(), a.end())) {
        std::cout << "YES" << nl;
        return;
    }
    if (!c0 || !c1) {
        std::cout << "NO" << nl;
        return;
    }
    std::sort(v.begin(), v.end());
    int l = 0, r = n - 1;
    for (int i = 0; i < n; ++i) {
        auto [val, p] = v[i];
        if (val & 1) break;
        l = std::max(l, p);
    }
    for (int i = n - 1; i >= 0; --i) {
        auto [val, p] = v[i];
        if (val & 1) break;
        r = std::min(r, p);
    }
    if (l > r) {
        std::cout << "NO" << nl;
        return;
    }
    l = 0, r = n - 1;
    for (int i = 0; i < n; ++i) {
        auto [val, p] = v[i];
        if (!(val & 1)) break;
        l = std::max(l, p);
    }
    for (int i = n - 1; i >= 0; --i) {
        auto [val, p] = v[i];
        if (!(val & 1)) break;
        r = std::min(r, p);
    }
    if (l > r) {
        std::cout << "NO" << nl;
        return;
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
