// 拓展并查集size (2 * n)
// u 本身 u+n 敌人的监狱
// 如果uv有仇
// u 应该和 v+n在一起
// v 应该和 u+n在一起
// 如果uu 和 u 有仇, 那么 uu 应该和u+n在一起, 此时uu和v在一起了
// 假如uu 和 v 有仇, 那么 uu 应该和v+n在一起, 此时v和u就在一起了,(u和v+n在一起),就会有矛盾
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long ll;

#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
struct DSU{
    vector<int> fa;
    DSU(int n){
        fa.resize(n + 1);
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int x){
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }
    void merge(int x, int y){
        int rx = find(x);
        int ry = find(y);
        if (rx != ry) fa[rx] = ry;
    }
};
struct crim{
    int u, v, w;
    bool operator<(const crim &other) const {return w > other.w;}
};
crim crims[100001];
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        int u, v, w;
        cin >> crims[i].u >> crims[i].v >> crims[i].w;
    }
    sort(crims + 1, crims + m + 1);
    ll ans = 0;
    DSU dsu(2 * n);
    for (int i = 1; i <= m; ++i){
        int u = crims[i].u;
        int v = crims[i].v;
        int w = crims[i].w;
        if (dsu.find(u) == dsu.find(v)){
            cout << w << '\n';
            return;
        }
        dsu.merge(u, v + n);
        dsu.merge(v, u + n);
    }
    cout << "0\n";
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
