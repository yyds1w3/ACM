#include <bits/stdc++.h>
#include <iomanip>
#include <vector>
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
vector<int> adj[MAXN];
double sum;
int n;
void dfs(int u, int fa, int d, double p) {
    if (adj[u].size() == 1) {
        sum += d*p;
        debug(d,p,u);
    }else {
        for (int v : adj[u]) {
            if (v == fa) continue;
            dfs(v, u, d+1, p / (adj[u].size()-1));
        }
    }
}
void solve() {
    cin >> n;
    rep(i, 1, n-1) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    adj[1].push_back(0);
    dfs(1, 0, 0, 1);
    cout << setprecision(6) << fixed << sum << nl;
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
