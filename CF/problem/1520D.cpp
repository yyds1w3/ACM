// 错在了没有开ll， 整数相乘很有可能溢出
#include <bits/stdc++.h>
#include <map>
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
    map<int, int> mp;
    for (int i = 1; i <=n; ++i){
        int x;
        cin >> x;
        if (mp[x-i]) mp[x-i]++;
        else mp[x-i] = 1;
    }
    ll ans = 0;
    for (auto p : mp){
        debug(p);
        ans += (ll)p.second * (p.second - 1) / 2;
    }
    cout << ans << endl;
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
    cin >> tt;
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
