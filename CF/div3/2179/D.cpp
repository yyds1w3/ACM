#include <bits/stdc++.h>
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
struct st {
    int v;
    int w;
    bool operator<(const st& other) const {
        if (w != other.w) return w > other.w;
        return v < other.v;
    }
};
st a[MAXN];
void solve() {
    int n; cin >> n;
    n = (1 << n); 
    memset(a, 0, sizeof(a));
    for (int i = 0; i < n; ++i) {
        a[i].v = i;
        int temp = i;
        while (temp & 1) {
            temp >>= 1;
            a[i].w++;
        }
    }
    sort(a, a+n);
    for (int i = 0; i < n; ++i) cout << a[i].v << " ";
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
