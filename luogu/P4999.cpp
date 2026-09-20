//Fri Jul 31 02:24:13 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#endif
using i64 = long long;
const int MOD = 1e9 + 7;
struct Node {
    i64 f, g;
}dp[20];
void solve() {
    i64 L, R;
    std::cin >> L >> R;
    std::string s;
    int n;
    // {45, 10} -> {450 + 45,100}
    auto dfs = [&](auto self, int pos, bool lim) -> Node {
        if (pos == n) return {0, 1};
        if (!lim && dp[pos].f != -1) return dp[pos];
        Node res = {0, 0};
        int up = lim ? s[pos] - '0' : 9;
        for (int i = 0; i <= up; ++i) {
            Node t = self(self, pos + 1, lim && (i == up));
            res.f = (res.f + t.f + i * t.g % MOD) % MOD;
            res.g = (res.g + t.g) % MOD;
        }
        if (!lim) dp[pos] = res;
        return res;
    };
    i64 ans = 0;
    s = std::to_string(R);
    n = s.size();
    for (int i = 0; i < 20; ++i) dp[i] = {-1, 0};
    ans = (ans + dfs(dfs, 0, 1).f) % MOD;
    s = std::to_string(L - 1);
    n = s.size();
    for (int i = 0; i < 20; ++i) dp[i] = {-1, 0};
    ans = ((ans - dfs(dfs, 0, 1).f) % MOD + MOD) % MOD;
    std::cout << ans << nl;
}

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
