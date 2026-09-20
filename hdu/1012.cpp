//Thu Aug 13 12:08:41 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cerr << #x << ": " << x << nl; 
using i64 = long long;
using i128 = __int128;
const int MOD = 998244353;
void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::pair<int, int>> edge;
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        if (u > v) std::swap(u, v);
        edge.push_back({u, v});
    }
    if (k > 2) {
        std::cout << 0 << nl;
        return;
    }
    std::sort(edge.begin(), edge.end());
    i64 cnt = 1;
    i64 ans = 0;
    for (int i = 1; i < m; ++i) {
        if (edge[i] == edge[i - 1]) {
            cnt++;
        }else {
            ans = (ans + cnt * (cnt - 1) / 2) % MOD;
            cnt = 1;
        }
    }
    ans = (ans + cnt * (cnt - 1) / 2) % MOD;
    std::cout << ans << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
