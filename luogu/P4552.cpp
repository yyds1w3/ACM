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
    std::vector<i64> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }
    for (int i = n; i >= 1; --i) {
        a[i] = a[i] - a[i - 1];
    }
    i64 m1 = 0, m2 = 0;
    for (int i = 2; i <= n; ++i) {
        if (a[i] > 0) {
            m1 += a[i];
        }else if (a[i] <= 0) {
            m2 -= a[i];
        }
    }
    std::cout << std::max(m1, m2) << nl;
    std::cout << std::abs(m1 - m2) + 1 << nl;
}
