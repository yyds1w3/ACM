//Mon Aug 24 12:41:29 PM CST 2026
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
const int N = 8000;
int n;
std::vector<int> f(N), sz(N);
void init(int n) {
    std::iota(f.begin(), f.begin() + n, 0);
    sz.assign(n, 1);
}
int find(int x) {
    if (f[x] == x) return x;
    return f[x] = find(f[x]);
}
void merge(int x, int y) {
    int rx = find(x);
    int ry = find(y);
    if (rx != ry) {
        f[rx] = ry;
        sz[ry] += sz[rx];
    }
}
bool same(int x, int y) {
    return find(x) == find(y);
}
int size(int x) {
    return sz[find(x)];
}
void solve() {
    int n;
    std::cin >> n;
    init(n);
    std::vector<std::vector<int>> si(n, std::vector<int>(n));
    std::vector<std::vector<int>> g(n, std::vector<int>(n));
    std::vector<int> in(n);
    bool ok = true;
    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < n; ++j) {
            if (i == j && s[j] == '0') ok = false;
            si[i][j] = s[j] - '0';
            g[j][i] = s[j] - '0';
            if (g[j][i] && i != j) in[i]++;
        }
    }
    if (!ok) {
        std::cout << "NO" << nl;
        return;
    }
    // debugvv(g,n,n);
    // debugv(in,n);
    std::queue<int> q;
    std::vector<std::vector<int>> dp(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        if (!in[i]) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        dp[u][u] = 1;
        for (int v = 0; v < n; ++v) if (v != u && g[u][v]){
            for (int j = 0; j < n; ++j) if (v != j) dp[v][j] = std::min(2, dp[u][j] + dp[v][j]);
            in[v]--;
            if (!in[v]) {
                q.push(v);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (g[j][i] && dp[i][j] > 1) {
                g[j][i] = 0;
                dp[i][j]--;
            }
        }
    }
    std::vector<bool> vis(n);
    std::vector<std::vector<int>> gg(n, std::vector<int>(n));
    std::vector<std::vector<int>> so(n, std::vector<int>(n));

    int edge_count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            gg[i][j] = g[j][i];
            if (gg[i][j] && i != j) {
                edge_count++;
                merge(i, j);
            }
        }
    }

    if (edge_count != n - 1) {
        std::cout << "NO" << nl;
        return;
    }
    std::set<int> s;
    for (int i = 0; i < n; ++i) {
        s.insert(find(i));
    }
    if (s.size() > 1) {
        std::cout << "NO" << nl;
        return;
    }
    auto dfs = [&](auto self, int u) -> void {
        vis[u] = true;
        so[u][u] = 1;
        for (int v = 0; v < n; ++v) {
            if (gg[u][v]) {
                if (!vis[v]) {
                    self(self, v);
                }
                for (int j = 0; j < n; ++j) {
                    so[u][j] |= so[v][j]; 
                }
            }
        }
    };

    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            dfs(dfs, i);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (so[i][j] != si[i][j]) {
                std::cout << "NO" << nl;
                return;
            }
        }
    }

    std::cout << "YES" << nl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (gg[i][j] && i != j) {
                std::cout << i + 1 << " " << j + 1 << nl;
            }
        }
    }}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
