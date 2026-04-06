#include <bits/stdc++.h>
#include <vector>
using i64 = long long;
using i128 = __int128;
#define nl "\n"
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n, m;
    std::cin >> n >> m;
    std::vector<int> mp(n);
    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < m; ++j) {
            if (s[j] == 'H') {
                mp[i] |= (1 << j);
            }
        }
    }
    std::vector<int> valid;
    for (int s = 0, ms = (1 << m); s < ms; ++s) {
        if ((s & (s << 1)) || (s & (s << 2))) continue;
        valid.push_back(s);
    }
    int sz = valid.size();
    std::vector memo(n, std::vector(sz, std::vector<int>(sz, -1)));
    auto dfs = [&](auto self, int row, int pidx, int ppidx) -> i64 {
        if (row == n) return 0;
        if (memo[row][pidx][ppidx] != -1) {
            return memo[row][pidx][ppidx];
        }
        i64 res = 0;
        int ps = valid[pidx];
        int pps = valid[ppidx];
        for (int i  = 0, sz = valid.size(); i < sz; ++i) {
            int s = valid[i];
            if ((s & ps) || (s & pps) || (s & mp[row])) continue;
            int cnt = __builtin_popcount(s);
            res = std::max(res, cnt + self(self, row + 1, i, pidx));
        }
        return memo[row][pidx][ppidx] = res;
    };
    std::cout << dfs(dfs, 0, 0, 0) << nl;
}
