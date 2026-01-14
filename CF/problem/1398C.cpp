#include <bits/stdc++.h>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
#define nl "\n"
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using lll = __int128;
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    ll sum = 0;
    // s_r - r == s_(l-1) - (l-1)
    map<ll, int> m;
    m[0] = 1; // 当l=1时
    ll ans = 0;
    for (int i = 1; i <= n; ++i) { // s_1表示前1个字符总和
        sum += s[i-1]-'0';
        ans += m[sum-i];
        m[sum-i]++; // s_1 - 1
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int tt = 1;
    cin >> tt;
    while (tt--) solve();
}
