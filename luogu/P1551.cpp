#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
struct DSU{
    int fa[5001];
    void init(int n){
        for (int i = 1; i <= n; ++i){
            fa[i] = i;
        }
    }
    int find(int x){
        if (fa[x] == x) return x;
        return fa[x] = find(fa[x]);
    }
    void merge(int x, int y){
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY)
            fa[rootX] = rootY;
    }
    bool ask(int x, int y){
        return find(x)== find(y);
    }
}dsu;
void solve() {
    int n, m, p;
    cin >> n >> m >> p;
    dsu.init(n);
    for (int i = 1; i <= m; ++i){
        int x, y;
        cin >> x >> y;
        dsu.merge(x, y);
    }
    for (int i = 1; i <= p; ++i){
        int x, y;
        cin >> x >> y;
        cout << (dsu.ask(x, y) ? "Yes" : "No") << '\n';
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
