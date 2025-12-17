#include <bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
const int MAXN = 1e5 + 1;
vector<int> adj[MAXN];
int dist[MAXN];
void dfs(int u, int tag){
    dist[u] = tag;
    for (int v : adj[u]){
        if (dist[v] == 0){
            dfs(v, tag);
        }
    }
}
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
    }
    for (int i = n; i >= 1; --i){
        if (dist[i] == 0)
            dfs(i,i);
    }
    for (int i = 1; i <= n; ++i){
        cout << dist[i] << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) {
        freopen("in.txt", "r", stdin);
    }
    auto _clock_start = chrono::high_resolution_clock::now();
#endif
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
#ifdef LOCAL
    auto _clock_end = chrono::high_resolution_clock::now();
    cerr << "Run Time: " 
         << chrono::duration_cast<chrono::milliseconds>(_clock_end - _clock_start).count() 
         << " ms" << endl;
#endif
    return 0;
}
