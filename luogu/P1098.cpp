#include <bits/stdc++.h>
#include <cctype>
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
    int p1, p2, p3; cin >> p1 >> p2 >> p3;
    string s; cin >> s;
    int n = s.size();
    rep(i, 0, n-1) {
        char curr = s[i];
        if (curr == '-' && i > 0 && i < n-1) {
            char l = s[i-1];
            char r = s[i+1];
            bool is_digit = (isdigit(l) && isdigit(r));
            bool is_lower = (islower(l) && islower(r));
            if ((is_digit || is_lower) && l < r) {
                if (l == r-1) continue;
                if (p1 == 1 && is_lower) {
                    if (p3 == 1)
                    for (char c = l + 1; c < r; ++c) cout << string(p2, c);
                    else for (char c = r-1; c > l; --c) cout << string(p2, c);
                }else if (p1 == 2 && is_lower) {
                    if (p3 == 1)
                    for (char c = l + 1; c < r; ++c) cout << string(p2, toupper(c));
                    else for (char c = r-1; c > l; --c) cout << string(p2, toupper(c)); 
                } else if (p1 == 3) {
                    cout << string(p2 * (r - l - 1), '*');
                }else {
                    if (p3 == 1) 
                    rep(j, l+1, r-1) cout << string(p2, j);
                    else per(j, r-1, l+1) cout << string(p2, j);
                }
            }else cout << curr;
        }else cout << curr; 
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
