//Tue Aug  4 12:29:29 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
using u64 = unsigned long long;
#define debug(x) std::cerr << #x << ": " << x << nl; 
const int MOD = 998244353;
void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    std::vector<bool> valid(n + 1);
    std::vector<int> cnt(n + 1);
    int cur = 0;
    for (int i = 1; i <= n; ++i) {
        cnt[a[i]] = (cnt[a[i]] + 1) % 4;
        if (cnt[a[i]] == 1) cur++;
        if (cnt[a[i]] == 0) cur--;
        if (cur == 0) valid[i] = true;
    }
    if (cur > 0) {
        std::cout << 0 << nl;
        return;
    } 
    std::vector<int> dp(n + 1);
    dp[0] = 1;
    int sum = 1;
    for (int i = 0, j = 1; j <= n; ++j) {
        cnt[a[j]] = cnt[a[j]] + 1;
        while (cnt[a[j]] > 4) {
            cnt[a[i + 1]]--;
            sum = (sum - dp[i] + MOD) % MOD;
            i++;
        }
        if (valid[j]) {
            dp[j] = sum;
        }
        sum = (sum + dp[j]) % MOD;
    }
    std::cout << dp[n] << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
