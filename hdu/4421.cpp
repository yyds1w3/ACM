//Sun Aug 16 05:16:28 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cerr << #x << ": " << x << nl; 
using i64 = long long;
using i128 = __int128;
const int N = 500;
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

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    while (std::cin >> n) {
        std::vector<std::vector<int>> b(n, std::vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                std::cin >> b[i][j];
            }
        }
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (b[i][j] != b[j][i]) ok = false;
                if (i == j && b[i][j] != 0) ok = false;
            }
        }
        if (!ok) {
            std::cout << "NO\n";
            continue;
        }
        for (int k = 0; k < 31; ++k) {
            init(n);
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (i == j) continue;
                    bool f1 = i & 1;
                    bool f2 = j & 1;
                    bool f3 = (b[i][j] >> k) & 1;
                    if (f1 & f2) {
                        if (f3) {
                            adj[2*i].push_back(2*j+1);
                            adj[2*j].push_back(2*i+1);
                        }else {
                            adj[2*i+1].push_back(2*i);
                            adj[2*j+1].push_back(2*j);
                            adj[2*i].push_back(2*j);
                            adj[2*j].push_back(2*i);
                        }
                    }else if (!f1 && !f2) {
                        if (f3) {
                            adj[2*i].push_back(2*i+1);
                            adj[2*i+1].push_back(2*j+1);
                            adj[2*j].push_back(2*j+1);
                            adj[2*j+1].push_back(2*i+1);
                        }else {
                            adj[2*i+1].push_back(2*j);
                            adj[2*j+1].push_back(2*i);
                        }
                    }else {
                        if (f3) {
                            adj[2*i].push_back(2*j+1);
                            adj[2*i+1].push_back(2*j);
                            adj[2*j].push_back(2*i+1);
                            adj[2*j+1].push_back(2*i);
                        }else {
                            adj[2*i].push_back(2*j);
                            adj[2*i+1].push_back(2*j+1);
                            adj[2*j].push_back(2*i);
                            adj[2*j+1].push_back(2*i+1);
                        }
                    }
                }
            }
            for (int i = 0; i < 2 * n; ++i) {
                if (!dfn[i]) dfs(i);
            }
            for (int i = 0; i < n; ++i) {
                if (id[2*i] == id[2*i+1]) {
                    ok = false;
                    break;
                }
            }
            if (!ok) break;
        }
        if (ok) std::cout << "YES" << nl;
        else {
            std::cout << "NO" << nl;
        }
    }
}
