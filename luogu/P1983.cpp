#include <bits/stdc++.h>
#include <vector>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
#define nl "\n"
#define rep(i,s,e) for (int i = s; i <= (int)e; ++i)
#define per(i,e,s) for (int i = e; i >= (int)s; --i) 
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using lll = __int128;
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXN = 1e3 + 5;
bool stop[MAXN];
bool g[MAXN][MAXN];
int in[MAXN];
int level[MAXN];
void solve() {
    int n, m; cin >> n >> m;
    rep(i, 1, m) {
        int s; cin >> s;
        vector<int> a(s);
        memset(stop, 0, sizeof(stop));
        rep(j, 0, s-1) {
            cin >> a[j];
            stop[a[j]] = true;
        }
        int l = a[0];
        int r = a.back();
        rep(j, l, r) {
            if (!stop[j]) {
                for (int v : a) {
                    if (!g[j][v]){
                        g[j][v] = true;
                        in[v]++;
                    }
                }
            }
        }
    }
    queue<int> q;
    rep(i, 1, n) {
        if (in[i] == 0) {
            q.push(i);
            level[i] = 1;
        }
    }
    int ans = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans = max(ans, level[u]);
        rep(i, 1, n) {
            if (g[u][i]) {
                level[i] = max(level[i], level[u] + 1);
                in[i]--;
                if (in[i] == 0)
                    q.push(i);
            }
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
