#include <bits/stdc++.h>
#include <cstring>
#include <vector>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
int cow[101];
vector<int> adj[1001];
bool vis[1001];
map<int ,int> mp;
int ans;
int k, n, m;
void dfs(int x){
    vis[x] = true;
    mp[x]++;
    if (mp[x] == k) ans++;
    for (int v : adj[x]){
        if (vis[v] == false){
            dfs(v);
        }
    }
}
void solve() {
    cin >> k >> n >> m;
    for (int i = 1; i <= k; ++i){
        cin >> cow[i]; 
    }
    for (int i = 1; i <= m; ++i){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for (int i = 1; i <= k; ++i){
        memset(vis, 0, n + 1);
        dfs(cow[i]);
    }
    cout << ans;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
