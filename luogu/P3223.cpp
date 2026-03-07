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
struct BigInt {
    vector<int> digits;
    BigInt(int v = 0) {
        if (v == 0) digits.push_back(0);
        while (v > 0) {
            digits.push_back(v % 10);
            v /= 10;
        }
    }
    void operator*=(int v) {
        if (v == 0) {
            digits = {0};
            return;
        }
        ll carry = 0;
        for (int &d : digits) {
            ll cur = (ll)d * v + carry;
            d = cur % 10;
            carry = cur / 10;
        }
        while (carry) {
            digits.push_back(carry % 10);
            carry /= 10;
        }
    }
    void operator-=(BigInt &other) {
        int carry = 0;
        rep(i, 0, digits.size()-1) {
            int sub = digits[i] - carry;
            if (i < other.digits.size()) sub -= other.digits[i];
            if (sub < 0) {
                sub += 10;
                carry = 1; 
            }else {
                carry = 0;
            }
            digits[i] = sub;
        }
        while (digits.size() > 1 && digits.back() == 0) digits.pop_back();
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
    int n, m; cin >> n >> m;
    if (m > n + 3) {
        cout << 0 << nl;
        return;
    }
    BigInt tot(1);
    rep(i, 1, n+2) tot *= i;
    per(i, n+3, n-m+4) tot *= i;
    BigInt bad(1);
    rep(i, 1, n+1) bad *= i;
    bad *= 2;
    per(i, n+2, n-m+3) bad *= i;
    tot -= bad;
    tot.print();
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
