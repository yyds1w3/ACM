#include <bits/stdc++.h>
#include <vector>
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

void solve() {
    int n; cin >> n;
    vector<int> ans;
    ll product = 1;
    for (int i = 1; i < n; ++i) {
        if (gcd(n, i) == 1) {
            product = (product * i) % n;
            ans.push_back(i);
        }
    }
    cout << (product==1?ans.size(): ans.size()-1) << endl;
    for (int v : ans) {
        if (v == product && v != 1) continue;
        else cout << v << " ";
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
    while (tt--) {
        solve();
    }
    return 0;
}
