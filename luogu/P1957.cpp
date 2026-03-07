#include <bits/stdc++.h>
#include <string>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
#define nl "\n"
#define rep(i,s,e) for (int i = s; i <= (int)e; ++i)
#define per(i,e,s) for (int i = e; i >= (int)s; --i) 
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using lll = __int128;
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;

void solve() {
    int n; cin >> n;
    char op; int x, y;
    rep(i, 1, n) {
        string s; cin >> s;
        if (isalpha(s[0])) {
            op = s[0];
            cin >> x >> y;
        }else {
            x = stoi(s);
            cin >> y;
        }
        if (op == 'a') {
            string ss = to_string(x) + '+' + to_string(y) + '=' + to_string(x + y);
            cout << ss << nl << ss.size() << nl;
        }else if (op == 'b') {
            string ss = to_string(x) + '-' + to_string(y) + '=' + to_string(x - y);
            cout << ss << nl << ss.size() << nl;
        }else {
            string ss = to_string(x) + '*' + to_string(y) + '=' + to_string(x * y);
            cout << ss << nl << ss.size() << nl;;
        }
    }
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
