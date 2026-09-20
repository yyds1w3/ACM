//Tue Jul 14 03:05:11 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#endif
using i64 = long long;
using i128 = __int128;
void solve() {
    int n, m;
    std::cin >> n >> m;
    //
    std::vector<std::pair<std::string, int>> ops(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> ops[i].first >> ops[i].second;
    }
    // 
    auto calc = [&](int bit, int w) -> int {
        for (int i = 0; i < n; ++i) {
            int x = (ops[i].second >> bit) & 1;
            if (ops[i].first == "AND") {
                w &= x;
            }else if (ops[i].first == "XOR") {
                w ^= x;
            }else {
                w |= x;
            }
        }
        return w;
    };
    int ans = 0;
    int val = 0;
    for (int bit = 29; bit >= 0; --bit) {
        int res0 = calc(bit, 0);
        int res1 = calc(bit, 1);
        if (((val + (1 << bit)) <= m) && (res1 > res0)) {
            val += (1 << bit);
            ans += (res1 << bit);
        }else {
            ans += (res0 << bit);
        }
    }
    std::cout << ans << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    solve();
}
