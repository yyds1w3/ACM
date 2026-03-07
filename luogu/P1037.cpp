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
const int MAXN = 15; 
int dist[MAXN][MAXN];
int cnt[MAXN];
struct BigInt {
    vector<int> digits;
    BigInt(string s) {
        per(i, s.size()-1, 0) digits.push_back(s[i] - '0');
    }
    void operator*=(int x) {
        int carry = 0; 
        for (int &d : digits) {
            d = d * x + carry;
            carry = d / 10;
            d %= 10;
        }
        while (carry) {
            digits.push_back(carry % 10);
            carry /= 10;
        }
    }
    void print() {
        if (digits.empty()) cout << 0 << nl; 
        else {
            per(i, digits.size()-1, 0) cout << digits[i];
            cout << nl;
        }
    }
};
void solve() {
    string s; cin >> s;
    int k; cin >> k;
    rep(i, 0, 9) dist[i][i] = 1;
    rep(i, 1, k) {
        int u, v; cin >> u >> v;
        dist[u][v] = 1;
    }
    rep(k, 0, 9) {
        rep(i, 0, 9) {
            rep(j, 0, 9) {
                dist[i][j] = dist[i][j] | (dist[i][k] & dist[k][j]);
            }
        }
    }
    rep(i, 0, 9) {
        cnt[i] = 0;
        rep(j, 0, 9) {
            cnt[i] += dist[i][j]; 
        }
    }
    BigInt ans("1");
    per(i, s.size()-1, 0) {
        ans *= cnt[(s[i] - '0')];
    }
    ans.print();
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
