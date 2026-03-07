#include <bits/stdc++.h>
#include <functional>
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
const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
ll deg[MAXN];
pair<ll, int> a[MAXN];
bool neibor[MAXN];

void solve() {
    int n; cin >> n;
    rep(i, 1, n) {deg[i] = 0; adj[i].clear();}
    rep(i, 1, n-1){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++; deg[v]++;
    }
    rep(i, 1, n) a[i] = {deg[i], i};
    sort(a + 1, a + 1 + n, greater<>());
    ll ans = 0;
    rep(u, 1, n-1) {
        for (int v : adj[a[u].second]) neibor[v] = true;
        rep(v, u+1, n) {
            if (!neibor[a[v].second]) {ans = max(ans, deg[a[u].second] + deg[a[v].second] - 1); break;}
            ans = max(ans, deg[a[u].second] + deg[a[v].second] - 2);
        }
        for (int v : adj[a[u].second]) neibor[v] =false;
    }    
    cout << ans << nl;
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
