// Extended DSU
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
struct DSU{
    vector<int> fa, sz;
    DSU(int n){
        fa.resize(n + 1);
        sz.assign(n + 1, 1);
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int x){
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }

    void merge(int x, int y){
        int rx = find(x);
        int ry = find(y);
        if (rx != ry){
            fa[rx] = ry;
            sz[ry] += sz[rx];
        }
    }

    bool ask(int x, int y){
        return find(x) == find(y);
    }

    bool size(int x){
        return sz[find(x)];
    }
};
void solve() {
    int n, m;
    cin >> n >> m;
    DSU dsu(2 * n);
    for (int i = 1; i <= m; ++i){
        char opt;
        int p, q;
        cin >> opt >> p >> q;
        if (opt == 'F'){
            dsu.merge(p, q);
        }else if (opt == 'E'){
            dsu.merge(p + n, q);
            dsu.merge(q + n, p);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i){
        if (dsu.fa[i] == i) ans++;
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
