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
const int MAXN = 2e5 + 1;
int head[MAXN], pos[MAXN], nxt[MAXN], tot;
int c[MAXN];
int n, k;
void init() {
    for (int i = 1; i <= n; ++i) {head[i] = -1; c[i] = 0;}
    tot = 0;
}
void insert(int val, int p) {
    ++tot;
    pos[tot] = p;
    nxt[tot] = head[val];
    head[val] = tot;
}
void solve() {
    cin >> n >> k;
    init();
    int mx_val = 0;
    for (int i = 1; i <= n; ++i) {
        int v; cin >> v;
        insert(v, i);
        mx_val = max(v, mx_val);
    }
    vector<int> paint;
    for (int i = mx_val; i >= 1; --i) {
        if (head[i] == -1) continue;
        int count = 0;
        for (int j = head[i]; j != -1; j = nxt[j]) {
            if (count < k) {
                paint.push_back(pos[j]);
                count++;
            }
        }
    }
    int painted = paint.size() / k * k;
    for (int i = 0; i < painted; ++i) c[paint[i]] = i % k + 1;
    for (int i = 1; i <= n; ++i) cout << c[i] << " ";
    cout << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
