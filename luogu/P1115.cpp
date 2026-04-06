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
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n;
    std::cin >> n;
    int dp = 0;
    int mx = -1e9;
    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        dp = std::max(dp + a, a);
        mx = std::max(mx, dp);
    }
    std::cout << mx << nl;
}
