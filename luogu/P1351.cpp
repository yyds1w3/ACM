// (w1 + w2)^2 == w1^2 + w2^2 + 2*w1w2
// (w1 + w2 + w3)^2 == w1^2 + w2^2 + w3^2 + 2(w1w2 + w1w3 + w2w3)
// ==> sum(wi)^2 == sum(wi^2) + sum(wiwj)
#include <bits/stdc++.h>
#include <vector>
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
const int MAXN = 2e5 + 1;
const int MOD = 10007;
vector<int> adj[MAXN];
int w[MAXN];
ll mx, sm;
void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n - 1; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
    }
    for (int u = 1; u <= n; ++u) {
        int mx1 = 0, mx2 = 0;
        ll sum_w = 0, sum_sq = 0;
        for (int v : adj[u]) {
            if (w[v] > mx1) {
                mx2 = mx1;
                mx1 = w[v];
            }else if (w[v] > mx2) {
                mx2 = w[v];
            }
            sum_w = (sum_w + w[v]) % MOD;
            sum_sq = (sum_sq + w[v] * w[v]) % MOD;
        }
        if (mx2 > 0) mx = max(mx, (ll)mx1 * mx2);
        sm = (sm + (sum_w * sum_w - sum_sq) % MOD) % MOD;
    }
    cout << mx << " " << sm << "\n";
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
