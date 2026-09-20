//Sun May 31 09:10:01 PM CST 2026
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
    std::vector<std::pair<int, int>> p(n);
    std::map<std::pair<int, int>, int> pos;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
        b[i]--;
    }
    for (int i = 0; i < n; ++i) {
        p[i] = {a[i], b[i]};
        pos[{a[i], b[i]}] = i;
    }
    std::vector<std::pair<int, int>> ans;
    if (n & 1) {
        bool f = false;
        for (int i = 0; i < n; ++i) {
            if (p[i].first == p[i].second && !f) {
                pos[p[n / 2]] = i;
                pos[p[i]] = n / 2;
                if (n / 2 != i) {
                    ans.push_back({n / 2, i});
                    std::swap(p[n / 2], p[i]);
                }
                f = true;
            }
        }
        if (!f) {
            std::cout << -1 << nl;
            return;
        }
    }
    for (int i = 0; i < n / 2; ++i) {
        if (p[i].first == p[i].second) {
            std::cout << -1 << nl;
            return;
        }
        if (pos.count({p[i].second, p[i].first}) == 0) {
            std::cout << -1 << nl;
            return;
        }
        int targetp = pos[{p[i].second, p[i].first}];
        if (targetp == n - i - 1) continue;
        pos[p[targetp]] = n - i - 1;
        pos[p[n - i - 1]] = targetp;
        std::swap(p[targetp], p[n - i - 1]);
        ans.push_back({targetp, n - i - 1});
    }
    std::cout << ans.size() << nl;
    for (auto [i ,j] : ans) {
        std::cout << i + 1 << " " << j + 1 << nl;
    }
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
    while (t--) solve();
}
