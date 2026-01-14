#include <bits/stdc++.h>
#include <vector>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
#define nl "\n"
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using lll = __int128;
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MAXN = 5e2 + 5;
int order[MAXN];
ll dist[MAXN][MAXN];
bool active[MAXN];
void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> dist[i][j];
        }
    }
    for (int i = n; i >=1; --i) cin >> order[i];
    vector<ll> lst;
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dist[i][j] = min(dist[i][order[k]] + dist[order[k]][j], dist[i][j]);
            }
        }
        active[order[k]] = true;
        ll ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (active[i] && active[j]) ans += dist[i][j];
            }
        }
        lst.push_back(ans);
    }
    reverse(lst.begin(), lst.end());
    for (ll as : lst) cout << as << " ";
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
