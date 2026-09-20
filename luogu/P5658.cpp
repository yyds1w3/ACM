//Sat Aug  8 09:20:22 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
using i128 = __int128;
#define debug(x) std::cerr << #x << ": " << x << nl; 

int fa[500001];
i64 dp[500001];
int cnt[500001];
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    s = ' ' + s;

    std::vector<std::vector<int>> adj(n + 1);
    for (int i = 1; i < n; ++i) {
        int u;
        std::cin >> u;
        adj[u].push_back(i + 1);
        fa[i + 1] = u;
    }
    std::vector<int> stk;
    auto dfs = [&](auto self, int u) -> void {
        int v = 0;
        if (s[u] == '(') {
            stk.push_back(u);
            cnt[u] = 0;
        }else {
            if (!stk.empty()) {
                v = stk.back();
                stk.pop_back();
                cnt[u] = cnt[fa[v]] + 1;
            }else {
                cnt[u]= 0;
            }
        }
        dp[u] = dp[fa[u]] + cnt[u];
        for (int v : adj[u]) {
            self(self, v);
        }
        if (s[u] == '(') {
            stk.pop_back();
        }else {
            if (v) {
                stk.push_back(v);
            }
        }
    };
    dfs(dfs, 1);
    i64 ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans ^= i * dp[i];
    }
    std::cout << ans << nl;
}
