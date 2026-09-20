//Fri Aug 28 12:47:37 PM CST 2026
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
const int INF = 1e9;
void solve() {
    int n, s, t;
    std::cin >> n >> s >> t;
    s--, t--;
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    std::vector<bool> ok(n);
    std::vector<int> stk, dfn(n);
    auto dfs = [&](auto self, int u) -> void {
        stk.push_back(u);
        for (int v : adj[u]) {
            if (!dfn[v]) {
                dfn[v] = dfn[u] + 1;
                self(self, v);
            }else if (dfn[v] < dfn[u]){
                int len = dfn[u] - dfn[v] + 1;
                if (len < 3) continue;
                std::vector<int> comp;
                while (true) {
                    int x = stk.back();
                    comp.push_back(x);
                    stk.pop_back();
                    if (x == v) break;
                }
                for (int node : comp) ok[node] = true;
                while (!comp.empty()) {
                    int node = comp.back();
                    comp.pop_back();
                    stk.push_back(node);
                }
            }
        }
        stk.pop_back();
    };
    for (int i = 0; i < n; ++i) {
        if (!dfn[i]) {
            dfn[i] = 1;
            dfs(dfs, i);
        }
    }
    std::vector<int> dist1(n, INF), dist2(n, INF);
    std::queue<int> q1, q2;
    q1.push(s), q2.push(t);
    dist1[s] = 0, dist2[t] = 0;
    while (!q1.empty()) {
        int u = q1.front();
        q1.pop();
        for (int v : adj[u]) {
            if (dist1[v] > dist1[u] + 1) {
                dist1[v] = dist1[u] + 1;
                q1.push(v);
            }
        }
    }
    while (!q2.empty()) {
        int u = q2.front();
        q2.pop();
        for (int v : adj[u]) {
            if (dist2[v] > dist2[u] + 1) {
                dist2[v] = dist2[u] + 1;
                q2.push(v);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (ok[i] && (dist1[i] > dist2[i])) {
            std::cout << "YES" << nl;
            return;
        }
    }
    std::cout << "NO" << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
