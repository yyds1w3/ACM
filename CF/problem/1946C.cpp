#include <bits/stdc++.h>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
#define nl "\n"
#define rep(i,s,e) for (int i = s; i <= e; ++i)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using lll = __int128;
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;
int n, k, cnt;
vector<int> adj[MAXN];
int sz[MAXN];
void dfs(int u, int fa, int x) {
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v == fa) continue;
        dfs(v, u, x);
        if (sz[v] >= x) cnt++; 
        else sz[u] += sz[v];
    }
}
bool check(int x) {
    cnt = 0;
    dfs(1, 0, x);
    if (sz[1] >= x) cnt++;
    if (cnt >= k + 1) return true;
    return false;
}
void solve() {
    cin >> n >> k;
    rep(i, 1, n) adj[i].clear();
    rep(i, 1, n-1) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int l = 0, r = n / k;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (check(mid)) {
            l = mid;
        }else {
            r = mid - 1;
        }
    }
    cout << l << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int tt = 1;
    cin >> tt;
    while (tt--) solve();
}
