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

void solve() {
    int n, m;
    string s;
    cin >> n >> s >> m;
    ll value = 0;
    for (char c : s){
        value *= n;
        if (n >= 10){
            if (c >= 'A')
                value += c - 'A' + 10;
            else
                value += c - '0';
        }else{
            value += c - '0';
        }
    }
    string ans = "";
    while (value){
        if (m >= 10){
            if (value % m >= 10){
                ans += value % m - 10 + 'A';
            }else{
                ans += value % m + '0';
            }
        }else{
            ans += value % m + '0';
        }
        value /= m;
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
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
