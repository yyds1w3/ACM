#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 1;
int t, n, q;
ll child[N];
vector<int> adj[N];
void dfs(int u, int fa){
    if (adj[u].size() == 1 && u != 1) {child[u] = 1; return;}
    for (int v : adj[u]){
        if (v == fa) continue;
        dfs(v, u);
        child[u] += child[v];
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    for (int i = 1; i <= t; ++i){
        cin >> n;
        for (int j = 1; j <= n; ++j) {adj[j].clear(); child[j] = 0;};
        for (int j = 1; j <= n-1; ++j){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1, 0);
        cin >> q;
        for (int j = 1; j <= q; ++j){
            int x, y;
            cin >> x >> y;
            cout << child[x] * child[y] << '\n';
        }
    }

    
}