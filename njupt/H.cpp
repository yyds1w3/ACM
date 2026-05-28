//Wed May 20 06:48:43 PM CST 2026
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
    freopen("sout.txt", "w", stdout);
    #endif
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> c(n);
    for (int i = 0; i < n; ++i) std::cin >> c[i];
    std::sort(c.begin(), c.end());
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (m >= c[i]) {
            m -= c[i];
            ans++;
        }else {
            break;
        }
    }
    std::cout << std::min(ans + k, n) << nl;
}
