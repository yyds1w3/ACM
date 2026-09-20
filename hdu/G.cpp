//Thu Jul 30 01:38:40 PM CST 2026
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
    int n, d;
    std::cin >> n >> d;
    std::string s;
    std::cin >> s;
    // 1. i == n - 1 - i;
    // 2. i + kd == n - 1 - i - kd --> i == n - 1 - i - 2kd;
    // 1 + 2. i = i + 2kd -> i == i(mod g);

    // 1. i == n - 1 - i(mod g);
    // 2. i == g - 1 - i(mod g);

    int g = std::gcd(n, 2 * d);
    std::vector<std::vector<int>> cnt((g + 1) / 2, std::vector<int>(26));
    std::vector<int> sz((g + 1) / 2);
    for (int i = 0; i < n; ++i) {
        int id = std::min(i % g, g - 1 - i % g);
        cnt[id][s[i] - 'a']++;
        sz[id]++;
    } 
    i64 ans = 0;
    for (int i = 0; i < (g + 1) / 2; ++i) {
        ans += sz[i] - *std::max_element(cnt[i].begin(), cnt[i].end());
    }
    std::cout << ans << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
