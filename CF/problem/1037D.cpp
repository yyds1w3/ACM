#include <bits/stdc++.h>
#include <vector>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
#define nl "\n"
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using lll = __int128;
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
int a[MAXN];
int pos[MAXN];
int vis[MAXN];
void solve() {
    int n; cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    for (int i = 1; i <= n; ++i) {
        sort(adj[i].begin(), adj[i].end(), [&](int a, int b) {return pos[a] < pos[b];});
    }
    queue<int> q;
    if (a[1] != 1) {
        cout << "NO" << nl;
        return;
    }
    q.push(1);
    vis[1] = 1;
    vector<int> res;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        res.push_back(u);
        for (int v : adj[u]) {
            if (vis[v]) continue;
            vis[v] = 1;
            q.push(v);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (res[i] != a[i+1]) {
            cout << "NO" << nl;
            return;
        }
    }
    cout << "YES" << nl;


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
