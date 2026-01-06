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
void solve() {
    string s; cin >> s;
    uint sz = s.size();
    int cnt = 0;
    for (uint i = 0; i < sz; ++i) {
        if (s[i] == 'u') {
            if (i == 0 || i == sz - 1) {
                s[i] = 's';
                cnt++;
            }else {
                if (s[i-1] == 's' && s[i+1] == 'u') {
                    s[i+1] = 's'; cnt++;
                }
            }
        }
    }
    cout << cnt << endl;
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
