//Thu Aug 27 01:52:25 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cout << #x << ": " << x << nl 
#define debugv(v, sz) do{std::cout << #v << "[]:" << nl;\
for (int i = 0; i < sz; ++i) std::cout << v[i] << " "; std::cout << nl;}while(0)
#define debugvv(v, sz1, sz2) do{std::cout << #v << "[][]:" << nl;\
for (int i = 0; i < sz1; ++i) {std::cout << i << ":";for (int j = 0; j < sz2; ++j) std::cout << v[i][j] << " "; std::cout<<nl;}}while(0)
using i64 = long long;
using i128 = __int128;
struct st {
};
std::ostream& operator<<(std::ostream& os, st& rhs) {
    return os;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::vector<int> lc(n, -1), rc(n, -1);
    std::vector<int> stk;
    for (int i = 0; i < n; ++i) {
        int lst = -1;
        while (!stk.empty() && a[stk.back()] < a[i]) {
            lst = stk.back();
            stk.pop_back();
        }
        if (!stk.empty()) {
            rc[stk.back()] = i;
        }
        lc[i] = lst;
        stk.push_back(i);
    }
    int root = stk[0];
    std::vector<std::pair<int, int>> dp(n);
    auto dfs = [&](auto self, int u) -> void {
        if (u == -1) return;
        self(self, lc[u]);
        self(self, rc[u]);
        int costL = 0, szL = 0, costR = 0, szR = 0;
        if (lc[u] != -1) {
            costL = dp[lc[u]].first;
            szL = dp[lc[u]].second;
        }
        if (rc[u] != -1) {
            costR = dp[rc[u]].first;
            szR = dp[rc[u]].second;
        }
        int cost = std::min(szL + costR, szR + costL);
        dp[u] = {cost, szL + szR + 1};
    };
    dfs(dfs, root);
    std::cout << dp[root].first << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
