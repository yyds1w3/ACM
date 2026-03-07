#include <bits/stdc++.h>
#include <vector>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using ll = long long;
using lll = __int128;
using namespace std;
#define nl "\n"
#define rep(i,s,e) for (ll i = s; i <= (e); ++i)
#define per(i,e,s) for (ll i = e; i >= (s); --i) 
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;
vector<pair<int, int>> odd, even;
void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int m = 0;
    rep(i, 0, n-1) {
        if (s[i] == 'o') {
            m++;
            if (i+1 <= n-1) if (s[i+1] == '?') s[i+1] = '.';
            if (i-1 >= 0) if (s[i-1] == '?') s[i-1] = '.';
        }
    }
    if (m == k) {
        rep(i, 0, n-1) {
            if (s[i] == '?') s[i] = '.';
        }
        cout << s << nl;
    }else if (m < k) {
        int mx = 0;
        int cons = 0;
        rep(i, 0, n) {
            if (i < n && s[i] == '?') cons++;
            else if (cons > 0){
                mx += (cons + 1) / 2;
                if (cons % 2 == 0) even.push_back({i - cons, i - 1});
                else odd.push_back({i - cons, i - 1});
                cons = 0;
            }
        }
        if (mx == (k - m)) {
            for (auto [l, r] : odd) {
                for (int i = l; i <= r; i += 2) {
                    s[i] = 'o';
                }
                for (int i = l + 1; i <= r; i += 2) {
                    s[i] = '.';
                }
            }
            cout << s << nl;
        }else cout << s << nl;
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
