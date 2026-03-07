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
#define rep(i,s,e) for (int i = s; i <= (e); ++i)
#define per(i,e,s) for (ll i = e; i >= (s); --i) 
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXN = 3e2 + 5;
struct Edge{
    int u, v, w;
    bool operator<(const Edge& other) const {return w < other.w;}
};
vector<Edge> vec;
int fa[MAXN];
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y) {
    int rx = find(x);
    int ry = find(y);
    if (rx != ry) fa[rx] = ry;
}
void solve() {
    int n; cin >> n;
    rep(i, 1, n) fa[i] = i;
    rep(i, 1, n) {
        int w; cin >> w;
        vec.push_back({0, i, w});
    }
    rep(i, 1, n) {
        rep(j, 1, n) {
            int p; cin >> p;
            vec.push_back({i, j, p});
        }
    }
    sort(vec.begin(), vec.end());
    ll ans = 0;
    ll cnt = 0;
    for (auto [u, v, w] : vec) {
        if (find(u) == find(v)) continue;
        merge(u, v);
        ans += w;
        cnt += 1;
        if (cnt >= n) break;
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
