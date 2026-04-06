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
    i64 m;
    std::cin >> n >> m;
    std::vector<i64> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::vector<i64> lft;
    auto dfs1 = [&](auto self, int idx, i64 sum) -> void {
        if (idx == n / 2) {
            lft.push_back(sum);
            return;
        }
        if (sum > m) return;
        self(self, idx + 1, sum + a[idx]);
        self(self, idx + 1, sum);
    };
    dfs1(dfs1, 0, 0);
    std::sort(lft.begin(), lft.end());
    i64 ans = 0;
    auto dfs2 = [&](auto self, int idx, i64 sum) -> void {
        if (idx == n) {
            auto it = std::upper_bound(lft.begin(), lft.end(), m - sum);
            ans += it - lft.begin();
            return;
        }
        if (sum > m) return;
        self(self, idx + 1, sum + a[idx]);
        self(self, idx + 1, sum);
    };
    dfs2(dfs2, n / 2, 0);
    std::cout << ans << nl;
}
