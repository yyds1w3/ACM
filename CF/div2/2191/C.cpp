#include <bits/stdc++.h>
#include <system_error>
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
const int MAXN = 1e5 + 5;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    bool f = false;
    rep(i, 0, n-2) {
        if (s[i] > s[i+1]) f = true;
    }
    if (!f) {cout << "Bob" << nl; return;}
    cout << "Alice" << nl;
    int n0 = 0;
    rep(i, 0, n-1) if (s[i] == '0') n0++;
    vector<int> ans;
    rep(i, 0, n-1) {
        if (i < n0) {
            if (s[i] == '1') ans.push_back(i+1);
        }else {
            if (s[i] == '0') ans.push_back(i+1);
        }
    }
    cout << ans.size() << nl;
    for (int i : ans) cout << i << " ";
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
