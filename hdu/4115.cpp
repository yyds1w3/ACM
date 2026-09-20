//Sun Aug 16 04:45:35 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cerr << #x << ": " << x << nl; 
using i64 = long long;
using i128 = __int128;
const int N = 10000;
int n, m;
int tot, cnt, top = -1;
std::vector<std::vector<int>> adj(2*N);
std::vector<int> dfn(2*N), low(2*N), stk(2*N), id(2*N);
void init(int n) {
    tot = cnt = 0;
    top = -1;
    adj.assign(2*n, std::vector<int>());
    dfn.assign(2*n, 0);
    low.assign(2*n, 0);
    id.assign(2*n, 0);
}
void dfs(int u) {
    dfn[u] = low[u] = ++tot;
    stk[++top] = u;
    for (int v : adj[u]) {
        if (!dfn[v]) {
            dfs(v);
            low[u] = std::min(low[u], low[v]);
        }else if (!id[v]) {
            low[u] = std::min(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u]) {
        cnt++;
        while (true) {
            int x = stk[top--];
            id[x] = cnt;
            if (x == u) break;
        }
    }
}
void solve() {
    std::cin >> n >> m;
    init(n);
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < m; ++i) {
        int u, v, k;
        std::cin >> u >> v >> k;
        u--, v--;
        
        for (int cu = 0; cu < 2; ++cu) {
            for (int cv = 0; cv < 2; ++cv) {
                int gu = (cu + a[u]) % 3;
                int gv = (cv + a[v]) % 3;
                if ((k == 0 && gu != gv) || (k == 1 && gu == gv)) {
                    adj[2*u+cu].push_back(2*v+!cv);
                    adj[2*v+cv].push_back(2*u+!cu);
                }
            }
        }
    }
    for (int i = 0; i < 2 * n; ++i) {
        if (!dfn[i]) dfs(i);
    }
    for (int i = 0; i < n; ++i) {
        if (id[2*i] == id[2*i+1]) {
            std::cout << "no" << nl;
            return;
        }
    }
    std::cout << "yes" << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    int idx = 1;
    while (t--) {
        std::cout << "Case #" << idx << ": ";
        idx++;
        solve();
    }
}
