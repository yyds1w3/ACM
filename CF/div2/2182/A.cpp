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

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int t1 = 0;
    size_t pos = s.find("2025");
    while (pos != string::npos) {
        t1++;
        pos = s.find("2025", pos + 1);
    }
    int t2 = 0;
    pos = s.find("2026");
    while (pos != string::npos) {
        t2++;
        pos = s.find("2026", pos + 1);
    }
    if (t2 >= 1){
        cout << 0 << "\n";
    }else {
        cout << min(1, t1) << "\n";
    }
    
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
