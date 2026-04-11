#include <bits/stdc++.h>
#include <vector>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using ll = long long;
using lll = __int128;
using namespace std;
#define nl "\n"
#define rep(i,s,e) for (ll i = s; i <= (e); ++i)
#define per(i,e,s) for (ll i = e; i >= (s); --i) 
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;
struct DSU {
    std::vector<int> f, siz;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    
    int find(int x) {
        return x == f[x] ? x : f[x] = find(f[x]);
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj1(n), adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        u--, v--;
        adj1[u].push_back(v);
        adj[v].push_back(u);
    }
    DSU dsu(n);
    vector<int> deg(n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j : adj[i]) {
            dsu.merge(i, j);
        }
        if (deg[i] > 0) {
            ans--;
        }
        for (int j : adj1[i]) {
            if (deg[j]++ == 0) ans++;
        }
        if (dsu.size(0) != i + 1) {
            cout << -1 << nl;
        }else {
            cout << ans << nl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
}
