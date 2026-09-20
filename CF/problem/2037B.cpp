//Wed Jun 17 07:25:43 PM CST 2026
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
    int k;
    std::cin >> k;
    std::vector<bool> vis(k + 1);
    std::pair<int, int> ans;
    for (int i = 0; i < k; ++i) {
        int x;
        std::cin >> x;
        if (((k - 2) % x == 0) && vis[(k - 2) / x]) {
            ans.first = x;
            ans.second = (k - 2) / x;
        }
        vis[x] = true;
    }
    std::cout << ans.first << " " << ans.second << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
