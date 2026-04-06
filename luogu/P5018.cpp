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


int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n;
    std::cin >> n;
    std::vector<int> w(n + 1), l(n + 1), r(n + 1), sz(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> w[i];
    }
    for (int i = 1; i <= n; ++i) {
        std::cin >> l[i] >> r[i];
    }
    auto dfs1 = [&](auto self, int u) ->void {
        if (l[u] == -1 && r[u] == -1) {
            sz[u] = 1;
            return;
        }
        sz[u] = 1;
        if (l[u] != -1) {
            self(self, l[u]);
            sz[u] += sz[l[u]];
        }
        if (r[u] != -1) {
            self(self, r[u]);
            sz[u] += sz[r[u]];
        }
    };
    dfs1(dfs1, 1);
    debug(sz);
    auto check = [&] (auto self, int u, int v) -> bool {
        if (u == -1 && v == -1) {
            return true;
        }
        if (u == -1 || v == -1) {
            return false;
        }
        if (sz[u] != sz[v]) {
            return false;
        }
        return w[u] == w[v] && self(self, l[u], r[v]) && self(self, r[u], l[v]);
    };
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (check(check, l[i], r[i])) {
            ans = std::max(ans, sz[i]);
        }
    }
    std::cout << ans << nl;
}
