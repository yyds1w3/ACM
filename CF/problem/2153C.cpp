//Mon Apr 20 06:47:46 PM CST 2026
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
        std::map<int, int> cnt;
        for (int i = 0; i < n; ++i) {
            int x;
            std::cin >> x;
            cnt[x]++;
        }
        std::vector<int> odd, even;
        i64 base = 0;
        for (auto [v, c] : cnt) {
            base += (i64)v * (c / 2);
            if (c % 2 == 1) {
                odd.push_back(v);
            }else {
                even.push_back(v);
            }
        }
        if (base == 0) {
            std::cout << 0 << nl;
            continue;
        }
        i64 ans = 0;
        for (int x : even) {
            if (base > x) {
                ans = std::max(ans, 2 * base);
            }
        }
        for (int v : odd) {
            if (2 * base > v) {
                ans = std::max(ans, 2 * base + v);
            }
        }
        for (int i = 1, sz = odd.size(); i < sz; ++i) {
            if (odd[i-1] + 2 * base > odd[i]) {
                ans = std::max(ans, odd[i-1] + 2 * base + odd[i]);
            }
        }
        std::cout << ans << nl;
    }
}
