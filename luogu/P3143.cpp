// 双指针
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
const int MAXN = 5e4 + 1;
ll a[MAXN], len[MAXN], len_mx[MAXN];
vector<pair<ll, ll>> v;
void solve() {
    ll n, k; cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    int mx = 0;
    for (int l = 1, r = 1; r <= n; ++r){
        while(a[r] - a[l] > k) l++;
        len[l] = r - l + 1;
        if (len[l] >= mx){
            v.push_back({l, len[l]});
        }
    }
    len_mx[n] = len[n];
    len_mx[n+1] = 0;
    for (int i = n - 1; i >= 1; --i){
        len_mx[i] = max(len_mx[i+1], len[i]);
    }
    ll ans = 0;
    for (auto p : v){
        ans = max(ans, p.second + len_mx[min(p.first + p.second, n + 1)]); 
    }
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
