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
int comb(int n, int m){
    if (m == 0) return 1;
    ll ans = 1;
    for (int i = n; i > n - m; --i) ans *= i;
    for (int i = m; i > 1; --i) ans /= i;
    return ans;
}
void solve() {
    string s;
    cin >> s;
    uint sz = s.size();
    ll ans = 0;
    for (uint i = 1; i < sz; ++i){
        if (s[i] <= s[i-1]){cout << 0; return ;}
    }
    for (uint i = 1; i < sz; ++i) ans += comb(26, i); // abc位数6, 位数1~5的总和
    for (uint i = 0; i < sz; ++i){
        char j;
        if (i == 0) j = 'a';
        else j = s[i-1] + 1;
        for (; j < s[i]; ++j){ // cgx 前面的a.. b..
            ans += comb('z' - j , sz - i - 1);
        }
    }
    cout << ++ans;

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
