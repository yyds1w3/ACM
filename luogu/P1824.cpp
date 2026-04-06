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
    int n, m;
    std::cin >> n >> m;
    std::vector<int> x(n);
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> x[i];
        mx = std::max(mx, x[i]);
    }
    std::sort(x.begin(), x.end());
    auto check = [&](int v) -> bool {
        int lst = x[0];
        int tot = 1;
        for (int i = 1;i < n; ++i) {
            if (x[i] - lst >= v) {
                lst = x[i];
                tot++;
            }
        }
        return tot >= m;
    };
    int L = 1, R = mx;
    while (L < R) {
        int mid = (L + R + 1) >> 1;
        if (check(mid)) {
            L = mid;
        }else {
            R = mid - 1;
        }
    }
    std::cout << L << nl;
}
