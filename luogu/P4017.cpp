// 利用了kahn算法，拓扑排序
#include <bits/stdc++.h>
#include <queue>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
const int MAXN = 5005;
const int MOD = 80112002;
vector<int> adj[MAXN];
int inD[MAXN], outD[MAXN];
int dp[MAXN];
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        outD[u]++;
        inD[v]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; ++i){
        if (inD[i] == 0){
            q.push(i);
            dp[i] = 1;
        }
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for (int v : adj[u]){
            dp[v] = (dp[v] + dp[u]) % MOD;
            inD[v]--;
            if (!inD[v]){
                q.push(v);
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i){
        if (outD[i] == 0){
            ans = (ans + dp[i]) % MOD;
        }
    }
    cout << ans;

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
