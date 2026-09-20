//Sat May 30 10:32:28 PM CST 2026
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
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    std::sort(a.begin(), a.end());
    int m = a[n / 2];
    int cnt = 0;
    if (n & 1) {
        for (int i = 0; i <= n / 2; ++i) {
            if (a[i] != m || a[n - 1 - i] != m) {
                cnt++;
            }
        }
    }else {
        for (int i = 0; i < n / 2; ++i) {
            if (a[i] != m || a[n - 1 - i] != m) {
                cnt++;
            }
        }
    }
    std::cout << cnt << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    int t;
    std::cin >> t;
    while (t--) solve();
}
