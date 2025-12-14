#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(x) 42
#endif
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b.begin(), b.end());
    vector<ll> pi_a(n+1, 0), pi_b(n+1, 0);
    for (int i = 0; i < n; ++i){
        pi_a[i+1] = pi_a[i] + a[i];
        pi_b[i+1] = pi_b[i] + b[i];
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i){
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 1){
            cout << pi_a[r] - pi_a[l-1] << '\n';
        }else{
            cout << pi_b[r] - pi_b[l-1] << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) {
        freopen("in.txt", "r", stdin);
    }
    auto _clock_start = chrono::high_resolution_clock::now();
#endif
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
#ifdef LOCAL
    auto _clock_end = chrono::high_resolution_clock::now();
    cerr << "Run Time: " 
         << chrono::duration_cast<chrono::milliseconds>(_clock_end - _clock_start).count() 
         << " ms" << endl;
#endif
    return 0;
}
