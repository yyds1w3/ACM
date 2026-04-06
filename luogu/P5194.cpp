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
    int n, c;
    std::cin >> n >> c;
    std::vector<i64> a;
    for (int i = 0; i < n; ++i) {
        int val;
        std::cin >> val;
        if (val <= c) {
            a.push_back(val);
        }
    }
    std::vector<i64> pi(n + 1);
    for (int i = 1; i <= n; ++i) {
        pi[i] = pi[i - 1] + a[i - 1];
    }
    n = a.size();
    i64 mx = 0;
    auto dfs = [&] (auto self, int idx, i64 ans) -> void {
        ans += a[idx];
        if (ans > c) {
            return;
        }
        mx = std::max(mx, ans);
        if (ans + pi[idx + 1] <= mx) {
            return;
        }
        for (int j = idx - 1; j >= 0; --j) {
            self(self, j, ans);
        }
    };
    for (int i = n - 1; i >= 0; --i) {
        dfs(dfs, i, 0);
    }
    std::cout << mx << nl;
}
