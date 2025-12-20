#include <bits/stdc++.h>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
struct fraction{
    ll up, down;
    fraction(ll u = 0, ll d = 1){
        if (d < 0){
            u = -u;
            d = -d;
        }
        up = u;
        down = d;
        simplify();
    }
    void simplify(){
        if (up == 0){
            down = 1;
            return;
        }
        ll cd = gcd(up, down);
        up /= cd;
        down /= cd;
    }
    fraction operator+(const fraction& other) const{
        return fraction{up*other.down + down*other.up, down * other.down};
    }
    fraction operator-(const fraction& other) const{
        return fraction{up*other.down - down*other.up, down * other.down};
    }
    void print(){
        if (down == 1) cout << up << endl;
        else cout << up << "/" << down << endl;
    }

};
void solve() {
    ll up, down;
    char slash, op;
    cin >> up >> slash >> down;
    fraction res(up, down);
    while (cin >> op){
        ll u, d;
        cin >> u >> slash >> d;
        fraction f(u, d);
        if (op == '+'){
            res = res + f;
        }else {
            res = res - f;
        }
    }
    res.print();

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
