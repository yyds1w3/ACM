//Tue Jul 14 04:22:17 PM CST 2026
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
    int n, m;
    std::cin >> n >> m;
    std::vector<int> ans;
    auto dfs = [&](auto self, int x) -> void {
        if ((int)ans.size() > m || ((int)ans.size() + (n + 1 - x) < m)) {
            return;
        }
        if (x == n + 1) {
            for (int i = 0; i < (int)ans.size(); ++i) {
                std::cout << ans[i] << " ";
            }
            std::cout << nl;
            return;
        }
        ans.push_back(x);
        self(self, x + 1);
        ans.pop_back();

        self(self, x + 1);

    };

    dfs(dfs, 1);
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    solve();
}
