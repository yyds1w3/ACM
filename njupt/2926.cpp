//Sat Jul 25 02:16:50 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#endif
using i64 = long long;
using i128 = __int128;
const int MOD = 1e9 + 7;
void solve() {
    std::string s;
    std::cin >> s;
    int n = s.size();

    std::vector<i64> h1(n + 1), h2(n + 2), p(n + 1);
    p[0] = 1;
    for (int i = 0; i < n; ++i) {
        h1[i + 1] = (h1[i] * 131 + (s[i] - 'a' + 1)) % MOD;
        p[i + 1] = p[i] * 131 % MOD;
    }
    for (int i = n; i >= 1; --i) {
        h2[i] = (h2[i + 1] * 131 + (s[i - 1] - 'a' + 1)) % MOD;
    }
    auto hash1 = [&](int l, int r) -> i64 {
        return (h1[r] - h1[l - 1] * p[r - l + 1] % MOD + MOD) % MOD;
    };
    auto hash2 = [&](int l, int r) -> i64 {
        return (h2[l] - h2[r + 1] * p[r - l + 1] % MOD + MOD) % MOD;
    };
    auto check = [&](int len) -> bool {
        for (int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1;
            if (hash1(i, i + len / 2 - 1) == hash2(j - len / 2 + 1, j)) {
                return true;
            }
        }
        return false;
    };
    int ll = 0, rr = (n - 1) / 2;
    while (ll < rr) {
        int mid = (ll + rr + 1) >> 1;
        if (check(2 * mid + 1)) {
            ll = mid;
        }else {
            rr = mid - 1;
        }
    }
    int ans = 2 * ll + 1;
    ll = 0, rr = n / 2;
    while (ll < rr) {
        int mid = (ll + rr + 1) >> 1;
        if (check(2 * mid)) {
            ll = mid;
        }else {
            rr = mid - 1;
        }
    }
    ans = std::max(ans, 2 * ll);
    std::cout << ans << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
