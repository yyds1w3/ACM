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
struct Fenwick {
    int n;
    std::vector<int> treeA;
    Fenwick(int n_) : n(n_) {
        treeA.assign(n + 1, 0);
    }
    void add(int pos, int val) {
        for (int i = pos + 1; i <= n; i += i & -i) {
            treeA[i] += val;
        }
    }
    i64 query(int pos) {
        i64 res = 0;
        for (int i = pos; i > 0; i -= i & -i) {
            res += treeA[i];
        }
        return res;
    }
};

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n;
    std::cin >> n;
    std::vector<int> p(n);
    std::vector<int> nums;
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
        nums.push_back(p[i]);
    }
    std::sort(nums.begin(), nums.end());
    nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
    auto getRank = [&](int val) {
        return std::lower_bound(nums.begin(), nums.end(), val) - nums.begin();
    };
    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; ++i) {
        int j;
        std::cin >> j;
        j--;
        adj[j].push_back(i);
    }
    std::vector<int> ans(n);
    Fenwick bit(n);
    auto dfs = [&](auto self, int u) -> void {
        int rk = getRank(p[u]);
        int cnt1 = bit.query(n) - bit.query(rk + 1);
        for (int v : adj[u]) {
            self(self, v);
        }
        int cnt2 = bit.query(n) - bit.query(rk + 1);
        ans[u] = cnt2 - cnt1;
        bit.add(rk, 1);
    };
    dfs(dfs, 0);
    for (int as : ans) {
        std::cout << as << nl;
    }
}
