#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
typedef long long ll;

#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
int fa[1000001];
int find(int x){
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}
void merge(int x, int y){
    int rx = find(x);
    int ry = find(y);
    if (rx != ry){
        fa[rx] = ry;
    }
}
void solve() {
    while(true){
        int n, m, x, y;
        scanf("%d", &n);
        if (n == 0){
            break;
        }
        scanf("%d", &m);
        for (int i = 1; i <= n; ++i){
            fa[i] = i;
        }
        for (int j = 1; j <= m; ++j){
            scanf("%d %d", &x, &y);
            merge(x, y);
        }
        int ind = 0;
        for (int i = 1; i <= n; ++i){
            if (fa[i] == i) ind++;
        }
        cout << ind - 1 << "\n";
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
