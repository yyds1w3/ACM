//2026-04-09 21:09:40
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


int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    #endif
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    int mx = 0;
    int dp = 0;
    for (int i = 0; i < n; ++i) {
        dp = std::max(0, dp + a[i]);
        mx = std::max(mx, dp);
    }
    int mx_v = *std::max_element(a.begin(), a.end());
    if (mx_v < 0) {
        std::cout << mx_v << nl;
    }else {
        std::cout << mx << nl;
    }
}
