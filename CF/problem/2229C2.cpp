//Sat May 23 11:02:42 PM CST 2026
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

// 选择一个锚点  > 0
// 我们可以让锚点之前的所有点先变成负数, 然后我们再翻转锚点
// 这就是之前的值
// 我们要让总值之和最大
// 就要让前面的值尽量大
// 为什么?
// 因为后面的值是有负有正的
// 你前面能占的值越多 说明占的正数越多, 
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
        std::vector<int> ops;
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        i64 sum = 0;
        i64 ans = 0;
        int p = -1;
        for (int i = 0; i < n; ++i) {
            ans += a[i];
            if (a[i] > 0) {
                if (sum - a[i] > ans) {
                    ans = sum - a[i];
                    p = i;
                }
            }
            sum += std::abs(a[i]);
        }
        int sgn = 1;
        for (int i = p - 1; i >= 0; --i) {
            if (sgn * a[i] > 0) {
                sgn *= -1;
                ops.push_back(i);
            }
        }
        if (p != -1) {
            ops.push_back(p);
        }
        std::cout << ops.size() << nl;
        for (int v : ops) {
            std::cout << v + 1 << " ";
        }
        std::cout << nl;
    }
}
