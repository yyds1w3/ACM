/**
 * Algorithm: Difference Array (1D & 2D)
 * Verified: CF 220B
 * Author: Qingw
 */
#include <bits/stdc++.h>
#define nl "\n"
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using lll = __int128;
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 1;
// ================start===============================
int a[MAXN], cnt[MAXN], ans;
int answer[MAXN];
int blo_sz;
struct Query {
    int l, r, id;
    bool operator<(const Query& other) const {
        int block_a = l / blo_sz;
        int block_b = other.l / blo_sz;
        if (block_a != block_b) return block_a < block_b;
        return (block_a & 1) ? r < other.r : r > other.r;
    }
}q[MAXN];
void add(int x) {
    if (x >= MAXN) return;
    if (cnt[x] == x) ans--;
    cnt[x]++;
    if (cnt[x] == x) ans++;
}
void del(int x) {
    if (x >= MAXN) return;
    if (cnt[x] == x) ans--;
    cnt[x]--;
    if (cnt[x] == x) ans++;
}
void solve() {
    int n, m; cin >> n >> m;
    blo_sz = sqrt(n);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) {
        cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }
    sort(q + 1, q+1+m);
    int curL = 1, curR = 0;
    for (int i = 1; i <= m; ++i) {
        int L = q[i].l;
        int R = q[i].r;
        while (curL > L) add(a[--curL]);
        while (curR < R) add(a[++curR]);
        while (curL < L) del(a[curL++]);
        while (curR > R) del(a[curR--]);
        answer[q[i].id] = ans;
    }
    for (int i = 1; i <= m; ++i) cout << answer[i] << nl;
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
