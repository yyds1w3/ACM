//Fri May 29 07:09:47 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#define debug_range(...) 43
#endif
using i64 = long long;
using i128 = __int128;
void solve() {
    i64 n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    int idx = n / 2;
    i64 add = 0;
    for (int i = n / 2 + 1; i < n; ++i) {
        i64 cnt = (i - n / 2);
        i64 mx = cnt * (a[i] - a[i - 1]);
        if (k >= mx) {
            k -= mx;
            idx = i;
        }else {
            break;
        }
    }
    i64 cnt = (idx - n / 2 + 1);
    add += k / cnt;
    std::cout << a[idx] + add << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    int t;
    t = 1;
    while (t--) {
        solve();
    }
}
