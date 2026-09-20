//Sat Aug 22 08:35:18 PM CST 2026
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
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int top = -1;
    std::vector<int> dfn(n), stk(n), ans;
    bool find = false;
    auto dfs = [&](auto self, int u, int p) -> void {
        if (find) return;
        stk[++top] = u;
        for (int v : adj[u]) if (!find && v != p){
            if (!dfn[v]) {
                dfn[v] = dfn[u] + 1;
                self(self, v, u);
            }else {
                int len = dfn[u] - dfn[v] + 1;
                if (len >= 3 && len & 1) {
                    find = true;
                    while (true) {
                        int x = stk[top--];
                        ans.push_back(x);
                        if (x == v) {
                            break;
                        }
                    }
                }
            }
        }
        if (!find) top--;
    };
    for (int i = 0; i < n; ++i) {
        if (!dfn[i]) {
            dfn[i] = 1;
            top = -1;
            dfs(dfs, i, -1);
        }
    }
    if (ans.empty()) {
        std::cout << -1 << nl;
    }else {
        std::cout << ans.size() << nl;
        for (int v : ans) {
            std::cout << v + 1 << " ";
        }
        std::cout << nl;
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
