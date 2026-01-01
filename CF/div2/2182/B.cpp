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
const int MAXL = 20;
int p[MAXL]; // 1 2 5 10... 
void solve() {
    int a, b; cin >> a >> b;
    int t1, t2;
    if (a < b) swap(a, b); // a > b;
    t1 = log2(a) + 1;
    t2 = log2(b) + 1;
    if (a < p[t1]) {
        t1--;
    }
    if (b < p[t2]) {
        t2--;
    }
    cout << min(t2 + 1, t1) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int tt = 1;
    cin >> tt;
    for (int i = 1; i <= MAXL; ++i) {
        p[i] = p[i-2] + pow(2, i-1);
    }
    while (tt--) {
        solve();
    }
    return 0;
}
