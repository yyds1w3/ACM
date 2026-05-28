//Tue May 19 03:54:37 PM CST 2026
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
    i64 n, m;
    std::cin >> n >> m;
    if (m < n || m > n * (n + 1) / 2) {
        std::cout << -1 << nl;
        return;
    }
    i64 k = m - n;
    std::vector<bool> vis(n);
    std::vector<int> ans;
    for (int j = n - 1; j >= 1; j--) {
        if (k >= j) {
            vis[j] = true;
            k -= j;
            ans.push_back(j);
        }
    }
    ans.push_back(0);
    vis[0] = true;
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            ans.push_back(i);
        }
    }
    std::cout << ans[0] + 1 << nl;
    for (int i = 0; i < n - 1; ++i) {
        std::cout << ans[i] + 1 << " " << ans[i + 1] + 1 << nl;
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
    while (t--) {
        solve();
    }
}
