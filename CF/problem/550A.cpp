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
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
int x = INF, y = INF;
void solve() {
    string s; cin >> s;
    int sz = s.size();
    for (int i = 0; i < sz; ++i) {
        if (s[i] == 'A' && s[i + 1] == 'B') {
            x = min(x, i);
            if (i - y > 1) {cout << "YES\n"; return;}
        }else if (s[i] == 'B' && s[i + 1] == 'A') {
            y = min(y, i);
            if (i - x > 1) {cout << "YES\n"; return;}
        }
    }
    cout << "NO\n";
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
