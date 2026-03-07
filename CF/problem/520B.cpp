#include <bits/stdc++.h>
#include <queue>
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
const int MAXN = 2e4 + 5;
int dist[MAXN];
int n, m;
void bfs() {
    rep(i, 0, MAXN) dist[i] = -1;
    queue<int> q;
    q.push(n);
    dist[n] = 0;
    while (!q.empty()) {
        int now = q.front();
        q.pop(); 
        if (now < m && dist[now * 2] == -1) {
            dist[now * 2] = dist[now] + 1;
            q.push(now*2);
        }
        if (now > 1 && dist[now - 1] == -1) {
            dist[now - 1] = dist[now] + 1;
            q.push(now - 1);
        }
    }
}
void solve() {
    cin >> n >> m;
    bfs();
    cout << dist[m] << nl;
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
