#include <algorithm>
#include <bits/stdc++.h>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using i128 = __int128;
const int MAXN = 1e3 + 5;
const int MAXM = 1e5 + 5;
int fa[MAXN];
struct Edge{
    int u, v, w;
    bool operator<(const Edge& other)const {return w < other.w;}
}adj[MAXM];
int find(int x){
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
bool merge(int x, int y){
    int rx = find(x);
    int ry = find(y);
    if (rx != ry) {
        fa[rx] = ry;
        return true;
    }
    return false;
}
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) cin >> adj[i].u >> adj[i].v  >> adj[i].w;
    sort(adj + 1, adj + 1 + m);
    for (int i = 1; i <= n; ++i) fa[i] = i;
    int ans = 0, cnt = 0;
    for (int i = 1; i <= m; ++i){
        if (merge(adj[i].u, adj[i].v)){
            ans = adj[i].w;
            cnt++;
            if (cnt == n-1){
                cout << ans << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
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
