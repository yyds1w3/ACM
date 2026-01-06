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
    int ans = 1e9;
    for (uint i = 0; i < s.size(); ++i) {
        int cnt[3] = {0};
        for (int k = 0; k < 7; ++k){
            if (i + k >= s.size()) break;
            cnt[s[i+k]-'a']++;
            if (k >= 1 && cnt[0] > cnt[1] && cnt[0] > cnt[2]) {
                ans = min(ans, k+1);
                break;
            }
        }
    }
    cout << (ans == 1e9 ? -1 : ans) << "\n";
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
