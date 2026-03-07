#include <bits/stdc++.h>
#include <vector>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
#define nl "\n"
#define popcount(x) __builtin_popcount(x)
#define popcountll(x) __builtin_popcountll(x)
#define ctz(x) __builtin_ctz(x)
#define ctzll(x) __builtin_ctzll(x)
#define clz(x) __builtin_clz(x)
#define clzll(x) __builtin_clzll(x)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using lll = __int128;
int lg2(int x) {return 31 - clz(x);}
int lg2(ll x) {return 63 - clzll(x);}
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;

void tfirst() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> dist(n + 1, INF);
    dist[1] = 0;

    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; ++i) cout << "rgb"[dist[i]%3];
    cout << nl;
}
void tsecond() {
    int dv; string col; cin >> dv >> col;
    int fr = 0, fg = 0, fb = 0;
    for (char c : col) {
        if (c == 'r') fr = 1;
        if (c == 'g') fg = 1;
        if (c == 'b') fb = 1;
    }
    if (fr + fg + fb == 1) {cout << 1 << nl; return;}
    char target;
    if (fr & fg) target = 'g';
    if (fr & fb) target = 'r';
    if (fg & fb) target = 'b';
    for (int i = 0; i < dv; ++i) {
        if (col[i] == target) {cout << i + 1 << nl; return;}
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int tt = 1;
    string s;
    cin >> s >> tt;
    if (s == "first") while (tt--) tfirst();
    else while (tt--) {
        int q; cin >> q;
        while (q--) tsecond();
    }
}

