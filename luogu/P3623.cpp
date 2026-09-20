//Mon Jul 20 03:23:34 PM CST 2026
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
    int n, k;
    std::cin >> n >> k;
    std::vector<int> ans(k);
    std::vector<bool> vis(n + 1);
    auto dfs = [&](auto self, int idx) -> void {
        if (idx == k) {
            for (int i = 0; i < k; ++i) {
                std::cout << ans[i] << " ";
            }
            std::cout << nl;
            return;
        }
        for (int i = 1; i <= n; ++i) {
            if (!vis[i]) {
                ans[idx] = i; 
                vis[i] = true;
                self(self, idx + 1);
                vis[i] = false;
            }
        }
    };
    dfs(dfs, 0);
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    solve();
}
