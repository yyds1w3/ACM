#include <bits/stdc++.h>
#include <vector>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
#define nl "\n"
#define rep(i,s,e) for (int i = s; i <= e; ++i)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using lll = __int128;
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MAXN = 2e5 + 5;
int a[MAXN];
void solve() {
    int n; cin >> n;
    int mx = 0, idx = -1;
    rep(i, 0, n-1) {
        cin >> a[i];
        if (mx < a[i]) {
            mx = a[i];
            idx = i;
        }
    }
    rotate(a, a + idx, a + n);
    vector<int> st;
    st.push_back(a[0]);
    ll ans = 0;
    for (int i = 1; i < n; ++i) {
        while (st.size() >= 2 && st.back() <= a[i]) {
            st.pop_back();
            ans += min(st.back(), a[i]);
        }
        if (st.size() == 1 && st.back() <= a[i]) ans += st.back();
        else st.push_back(a[i]);
    }
    while (st.size() > 1) {
        st.pop_back();
        ans += st.back();
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
    cin >> tt;
    while (tt--) solve();
}
