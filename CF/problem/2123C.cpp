//Mon May 25 07:54:58 PM CST 2026
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
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        std::vector<bool> f(n);
        std::vector<int> pre(n), suff(n + 1);
        suff[n] = 0;
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            if (i > 0) {
                pre[i] = std::min(pre[i - 1], a[i]);
            }else {
                pre[i] = a[i];
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            suff[i] = std::max(suff[i + 1], a[i]);
        }
        // 左边最小 || 右边最大
        for (int i = 0; i < n; ++i) {
            if (a[i] == pre[i] || a[i] == suff[i]) {
                std::cout << 1;
            }else {
                std::cout << 0;
            }
        }
        std::cout << nl;
    }
}
