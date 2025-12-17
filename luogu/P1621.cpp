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
const int N = 1e5 + 1;
bool vis[N];
vector<int> primes;
void euler_sieve(int n){
    vis[0] = vis[1] = true; // init
    for (int i = 2; i <= n; ++i){ // 遍历每个数
        if (!vis[i]) primes.push_back(i); // 推质数
        for (int p : primes){ // 标记合数
            if (i * p > n) break;
            vis[i * p] = true;
            if (i % p == 0) break;// 保证每个合数都是由他的最小质因子标记
        }
    }
}
void solve() {
    int a, b, p;
    cin >> a >> b >> p;
    DSU dsu(b);
    euler_sieve(b);
    for (int prim : primes){
        int start;
        if (prim < p) continue;
        if (prim >= a){
            start = prim;
        }else{
            start = ((a - 1) / prim + 1) * prim;
        }
        for (int j = start + prim; j <= b; j += prim){
            dsu.merge(j, start);
        }
    }
    int ans = 0;
    for (int i = a; i <= b; ++i){
        if (dsu.find(i) == i) ans++;
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
