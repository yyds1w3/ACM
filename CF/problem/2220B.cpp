//Sat May 30 03:43:29 PM CST 2026
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
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    int c = 1;
    int mx = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] == a[i - 1]) {
            c++;
        }else {
            c = 1;
        }
        mx = std::max(mx, c);
    }
    if (mx >= m) {
        std::cout << "NO" << nl;
    }else{
        std::cout << "YES" << nl;
    }
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
    while (t--) {
        solve();
    }
}
