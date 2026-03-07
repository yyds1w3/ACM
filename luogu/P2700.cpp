#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using ll = long long;
using lll = __int128;
using namespace std;
#define nl "\n"
#define rep(i,s,e) for (ll i = s; i <= (e); ++i)
#define per(i,e,s) for (ll i = e; i >= (s); --i) 
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
bool enemy[MAXN];
int fa[MAXN];
struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {return w > other.w;}
};
vector<Edge> vec;
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y) {
    int rx = find(x);
    int ry = find(y);
    if (rx != ry) {
        fa[rx] = ry;
        enemy[rx] = enemy[ry] = enemy[rx] | enemy[ry];
    }
}
void solve() {
    int n, k; cin >> n >> k;
    rep(i, 1, n) fa[i] = i;
    rep(i, 1, k) {
        int x; cin >> x;
        enemy[x] = true;
    }
    rep(i, 1, n-1) {
        int u, v, w; cin >> u >> v >> w;
        vec.push_back({u, v, w});
    }
    sort(vec.begin(), vec.end());
    ll ans = 0;
    for (auto [u, v, w] : vec) {
        int ru = find(u), rv = find(v);
        if (ru == rv) continue;
        if (enemy[ru] && enemy[rv]) {
            ans += w;
        }else {
            merge(u, v);
        }
    }
    cout << ans << nl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
}
