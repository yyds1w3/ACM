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
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        a[i] %= k;
    }
    std::sort(a.begin(), a.end());
    int ans = 2e9;
    for (int i = 1; i <= n; ++i) {
        ans = std::min(ans, a[i-1] + k - a[i]);
    }
    ans = std::min(ans, a[n - 1] - a[0]);
    std::cout << ans << nl;
}
