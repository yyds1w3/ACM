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
int n, a, b;
void solve() {
    cin >> n >> a >> b;
    if (a == 1) {
        if ((n - 1) % b == 0) cout << "Yes\n";
        else cout << "No\n";
        return;
    }
    ll curr = 1;
    while (curr <= n) {
        if ((n - curr) % b == 0){
            cout << "Yes\n";
            return;
        }
        curr *= a;
    }
    cout << "No\n";
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
