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
const int MAXN = 1e6 + 1;
int nxt[MAXN];
string s;
void solve() {
    cin >> s;
    int n = s.size();
    for (int i = 1, j = 0; i < n; ++i) {
        while (j > 0 && s[i] != s[j]) j = nxt[j-1];
        if (s[i] == s[j]) j++;
        nxt[i] = j;
    }
    int mx_mid = 0;
    for (int i = 1; i <= n - 2; ++i) mx_mid = max(mx_mid, nxt[i]);
    int len = nxt[n-1];
    while (len > mx_mid) len = nxt[len - 1];
    if (len > 0) cout << s.substr(0, len) << nl;
    else cout << "Just a legend" << nl;
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
