#include <bits/stdc++.h>
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
const int MAXN = 1e5 + 1;
int fa[MAXN], col[MAXN];
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y) {
    fa[find(x)] = find(y);
}
bool query(int x, int y, char c) {
    int co = c == 'H' ? 0 : 1;
    if (col[x] == co) return true;
    if (find(x) == find(y)) return false;
    return true;
}
void solve() {
    int n, m; cin >> n >> m;
    string s; cin >> s;
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
        col[i] = (s[i-1] == 'H' ? 0 : 1);
    }
    for (int i = 1; i < n; ++i) {
        int x, y; cin >> x >> y;
        if (col[x] == col[y]) {
            merge(x, y);
        }
    }
    for (int i = 1; i <= m; ++i) {
        int x, y; char c;
        cin >> x >> y >> c;
        if (query(x, y, c)) cout << 1;
        else cout << 0;
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
    while (tt--) {
        solve();
    }
    return 0;
}
