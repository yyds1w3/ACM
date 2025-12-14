#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
int adj[201];
int dist[201];
void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 1; i <= n; ++i){
        cin >> adj[i];
    }
    if (a == b) {cout << 0; return;}
    queue<int> q;
    q.push(a);
    memset(dist, -1, sizeof(dist));
    dist[a] = 0;
    while (!q.empty()){
        int u = q.front();
        debug(u, dist[u]);
        q.pop();

        int up = u + adj[u];
        if (up <= n && dist[up] == -1){
            dist[up] = dist[u] + 1;
            q.push(up);
        }
        int down = u - adj[u];
        if (down >= 1 && dist[down] == -1){
            dist[down] = dist[u] + 1;
            q.push(down);
        }
        if (dist[b] != -1){
            cout << dist[b] << "\n";
            return;
        }
    }
    cout << "-1" << '\n';
    
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
