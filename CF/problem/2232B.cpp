//Sat May 30 10:48:50 PM CST 2026
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
    std::vector<i64> a(n);
    i64 tot = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        tot += a[i];
        if (i > 0) {
            a[i] = std::min(a[i-1], tot / (i + 1));
        }
    }
    for (int i = 0; i < n; ++i) std::cout << a[i] << " ";
    std::cout << nl;
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
