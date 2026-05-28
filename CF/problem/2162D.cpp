//Mon May  4 06:54:34 PM CST 2026
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

i64 query(int l, int r) {
    i64 psum, asum;
    std::cout << 1 << " " << l << " " << r << std::flush << std::endl;
    std::cin >> psum;
    std::cout << 2 << " " << l << " " << r << std::flush << std::endl;
    std::cin >> asum;
    return asum - psum;
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
        int n;
        std::cin >> n;
        i64 len = query(1, n);
        int l = 1, r = n;
        while (l < r) {
            int mid = (l + r) / 2;
            if (query(l, mid) == 0) {
                l = mid + 1;
            }else {
                r = mid;
            }
        }
        std::cout << "!" << " " << l << " " << l + len - 1 << std::flush << std::endl;
    }
}
