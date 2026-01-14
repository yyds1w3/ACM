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
const int MAXN = 1e5 + 5;
int fa[MAXN];
int sz[MAXN];
int a[MAXN];
bool active[MAXN];
ll ans[MAXN];
int n;
ll curr;
vector<int> cnt[MAXN];
void init() {
    for (int i = 1; i <= n - 1; ++i) {
        fa[i] = i;
        sz[i] = 1;
        active[i] = false;
        cnt[i].clear();
    }
}
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y) {
    int rx = find(x);
    int ry = find(y);
    if (rx != ry) {
        curr -= (1LL * sz[rx] * (sz[rx] + 1) / 2);
        curr -= (1LL * sz[ry] * (sz[ry] + 1) / 2);
        fa[rx] = ry;
        sz[ry] += sz[rx];
        curr += (1LL * sz[ry] * (sz[ry] + 1) / 2);
    }
}

void solve() {
    cin >> n;
    init();
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i < n; ++i) cnt[abs(a[i+1] - a[i])].push_back(i);
    curr = 0;
    for (int k = n - 1; k >= 1; --k) {
        for (int i : cnt[k]) {
            active[i] = true;
            curr++;
            if (i > 1 && active[i-1]) {
                merge(i, i-1);
            }
            if (i < n - 1 && active[i+1]) {
                merge(i, i+1);
            }
        }
        ans[k] = curr;
    }
    for (int i = 1; i < n; ++i) cout << ans[i] << " ";
    cout << nl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int tt = 1;
    cin >> tt;
    while (tt--) solve();
}
