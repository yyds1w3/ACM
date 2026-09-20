//Tue Jul 14 04:18:16 PM CST 2026
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
    std::vector<int> a(n);
    auto dfs = [&](auto self, int idx) -> void {
        if (idx == n) {
            for (int i = 0; i < n; ++i) {
                std::cout << a[i] << " ";
            }
            std::cout << nl;
            return;
        }
        for (int i = 1; i <= k; ++i) {
            a[idx] = i;
            self(self, idx + 1);
        }
    };
    dfs(dfs, 0);
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    solve();
}
