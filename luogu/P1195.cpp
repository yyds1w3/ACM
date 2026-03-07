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
const int MAXN = 1e3 + 5;
struct Edge{
    int u, v, w;
    bool operator<(const Edge& other) const {return w < other.w;}
};
vector<Edge> vec;
int fa[MAXN];
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y ) {
    int rx = find(x);
    int ry = find(y);
    if (rx != ry) {
        fa[rx] = ry;
    }
}
void solve() {
    int n, m, k; cin >> n >> m >> k;
    rep(i, 1, n) fa[i] = i;
    rep(i, 1, m) {
        int u, v, w; cin >> u >> v >> w;
        vec.push_back({u, v, w});
    }
    sort(vec.begin(), vec.end());
    ll ans = 0;
    ll cnt = n;
    for (auto [u, v, w] : vec) {
        if (cnt == k) break;
        if (find(u) == find(v)) continue;
        merge(u, v);
        ans += w;
        cnt--;
    }
    if (cnt == k) cout << ans << nl;
    else cout << "No Answer" << nl;


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
