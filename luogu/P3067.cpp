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
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::vector<std::pair<int, int>> lft;
    auto dfs1 = [&](auto self, int idx, int sum, int mask) -> void {
        if (idx == n / 2) {
            lft.push_back({sum, mask});
            return;
        }
        self(self, idx + 1, sum + a[idx], mask | (1 << idx));
        self(self, idx + 1, sum, mask);
        self(self, idx + 1, sum - a[idx], mask | (1 << idx));
    };
    dfs1(dfs1, 0, 0, 0);
    std::sort(lft.begin(), lft.end());
    lft.erase(std::unique(lft.begin(), lft.end()), lft.end());
    std::vector<bool> vis(1 << n);
    auto dfs2 = [&](auto self, int idx, int sum, int mask) -> void {
        if (idx == n) {
            auto it = std::lower_bound(lft.begin(), lft.end(), std::make_pair(-sum, 0));
            while (it != lft.end() && it->first == -sum) {
                vis[mask | it->second] = true;
                it++;
            }
            return;
        }
        self(self, idx + 1, sum + a[idx], mask | (1 << idx));
        self(self, idx + 1, sum, mask);
        self(self, idx + 1, sum - a[idx], mask | (1 << idx));
    };
    dfs2(dfs2, n / 2, 0, 0);
    int ans = 0;
    for (int i = 1; i < (1 << n); ++i) {
        if (vis[i]) {
            ans++;
        }
    }
    std::cout << ans << nl;
}
