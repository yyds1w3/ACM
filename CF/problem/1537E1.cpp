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

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int pre = 1;
    for (int i = 1; i < n; ++i) {
        if (s[i] < s[i % pre]) pre = i + 1;
        else if (s[i] > s[i % pre]) break;
    }
    string ans;
    for (int i = 0; i < k; ++i) ans += s[i % pre];
    cout << ans;
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
