// Fri May  8 11:11:12 PM CST 2026
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
        std::string s;
        std::cin >> n >> s;
        std::vector<int> posa, posb;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'a') {
                posa.push_back(i);
            } else {
                posb.push_back(i);
            }
        }
        auto f = [&](std::vector<int> &pos) -> i64 {
            int sz = pos.size();
            if (sz == 0)
                return 0;

            std::vector<i64> pi(sz + 1);
            for (int i = 0; i < sz; ++i) {
                pi[i + 1] = pi[i] + pos[i];
            }
            i64 ans = 1e18;
            for (int k = 0; k <= sz; ++k) {
                // k -> [0, 1, k-1]
                // sz - k -> [n - 1, n - (sz - k)]
                ans = std::min(ans, pi[k] - 1LL * k * (k - 1) / 2 + 1LL * (2 * n - 1 - sz + k) * (sz - k) / 2 - (pi[sz] - pi[k]));
            }
            return ans;
        };
        i64 ans = std::min(f(posa), f(posb));
        std::cout << ans << nl;
    }
}
