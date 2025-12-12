#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define Open(s) freopen(s ".in", "r", stdin); freopen(s ".out", "w", stdout);
const int N = 2e5 + 1;
int n, m, k, a[N];
vector<int> adj[N];
ll dist[N];
ll ans[N];
void bfs(){
    memset(dist, -1, sizeof(dist));
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (int v : adj[u]){
            if (dist[v] == -1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}
int main() {
    IOS;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    int u, v;
    for (int i = 1; i <= m; ++i){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs();
    for (int i = 1; i <= n; ++i){
        ans[a[i]] = max(ans[a[i]], dist[i]);
    }
    for (int i = 1; i <= k; ++i){
        cout << ans[i] << ' ';
    }
    return 0;
}