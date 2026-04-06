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
    std::vector<int> cards(2025);
    int ans = 0;
    auto dfs = [&](auto self, int idx) -> void {
        if (idx == 2024) {
            ans++;
            debug(ans);
            if (ans >= (int)1e9 + 7) {
                ans %= (int)1e9 + 7;
            }
            return;
        }
        for (int k = 1; k <= 17600; ++k) {
            if (idx == 0 || std::gcd(cards[idx-1], k) == 1) {
                cards[idx] = k;
                self(self, idx + 1);
            }
        }
    };
    dfs(dfs, 0);
    std::cout << ans << nl;
}
