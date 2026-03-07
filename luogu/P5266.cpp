#include <bits/stdc++.h>
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
map<string, int> m;
void f1(string name, int score) {
    m[name] = score;
    cout << "OK" << nl;
}
void f2(string name) {
    if (m.count(name) > 0) {
        cout << m[name] << nl;
    }else {
        cout << "Not found" << nl;
    }
}
void f3(string name) {
    if (m.count(name) > 0) {
        m.erase(name);
        cout << "Deleted successfully" << nl;
    }else {
        cout << "Not found" << nl;
    }
}
void f4() {
    cout << m.size() << nl;
}
void solve() {
    int Q; cin >> Q;
    rep(i, 1, Q) {
        int op, score;
        string name;
        cin >> op;
        if (op == 1) {
            cin >> name >> score;
            f1(name, score);
        }else if (op == 2 || op == 3) {
            cin >> name;
            if (op == 2) f2(name);
            else if (op == 3) f3(name);
        }else {
            f4();
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
