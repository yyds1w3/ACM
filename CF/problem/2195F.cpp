//Fri Jun 26 01:37:46 PM CST 2026
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
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i] >> b[i] >> c[i];
    }
    std::vector<std::vector<int>> adj(n), radj(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            i64 da = a[i] - a[j];
            i64 db = b[i] - b[j];
            i64 dc = c[i] - c[j];
            if (da == 0 && db == 0 && dc > 0) {
                adj[i].push_back(j);
                radj[j].push_back(i);
            }else if (da > 0 && db * db - 4 * da * dc < 0){
                adj[i].push_back(j);
                radj[j].push_back(i);
            }
        }
    }
    std::vector<int> dpin(n), dpout(n);
    auto dfs1 = [&](auto self, int u) -> int {
        if (dpin[u] != 0) return dpin[u];
        int res = 1;
        for (int v : adj[u]) {
            res = std::max(res, self(self, v) + 1);
        }
        return dpin[u] = res;
    };
    auto dfs2 = [&](auto self, int u) -> int {
        if (dpout[u] != 0) return dpout[u];
        int res = 1;
        for (int v : radj[u]) {
            res = std::max(res, self(self, v) + 1);
        }
        return dpout[u] = res;
    };
    for (int i = 0; i < n; ++i) {
        std::cout << dfs1(dfs1, i) + dfs2(dfs2, i) - 1 << " ";
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
