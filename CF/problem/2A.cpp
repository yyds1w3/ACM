#include <bits/stdc++.h>
#include <vector>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
#define nl "\n"
#define rep(i,s,e) for (int i = s; i <= e; ++i)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using lll = __int128;
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;

void solve() {
    int n; cin >> n;
    vector<pair<string, int>> v(n+1);
    map<string, ll> scores;
    rep(i, 1, n) {
        cin >> v[i].first >> v[i].second;
        scores[v[i].first] += v[i].second;
    }
    ll mx = -LINF;
    for (auto& sc : scores) {
        mx = max(mx, sc.second);
    }
    map<string, ll> now;
    rep(i, 1, n) {
        now[v[i].first] += v[i].second;
        if (now[v[i].first] >= mx && scores[v[i].first] == mx) {cout << v[i].first << nl; return;}
    }


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
