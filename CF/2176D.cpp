//Sun Aug 23 08:32:00 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cout << #x << ": " << x << nl 
#define debugv(v, sz) do{std::cout << #v << "[]:" << nl;\
for (int i = 0; i < sz; ++i) std::cout << v[i] << " "; std::cout << nl;}while(0)
#define debugvv(v, sz1, sz2) do{std::cout << #v << "[][]:" << nl;\
for (int i = 0; i < sz1; ++i) {std::cout << i << ":";for (int j = 0; j < sz2; ++j) std::cout << v[i][j] << " "; std::cout<<nl;}}while(0)
using i64 = long long;
using i128 = __int128;
const i64 MOD = 998244353;
struct st {
};
std::ostream& operator<<(std::ostream& os, st& rhs) {
    return os;
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::map<i64, i64>> dp(n);
    std::vector<std::pair<i64, i64>> a(n);
    std::map<i64, i64> mp;
    std::vector<std::vector<int>> radj(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i].first;
        a[i].second =  i;
        mp[i] = a[i].first;
    }
    std::sort(a.begin(), a.end());
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        radj[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) {
        auto [val, id] = a[i];
        for (int v : radj[id]) {
            dp[id][val + mp[v]] = (dp[id][val + mp[v]] + dp[v][val] + 1) % MOD;
        }
    }
    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
        for (auto [t1,t2] : dp[i]) {
            ans = (ans + t2) % MOD;
        }
    }
    std::cout << ans << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
