//Wed Aug 19 10:12:03 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cout << #x << ": " << x << nl; 
#define debugv(v, sz) std::cout << #v << "[]:" << nl;\
for (int i = 0; i < sz; ++i) std::cout << v[i] << " "; std::cout << nl;
#define debugvv(v, sz1, sz2) std::cout << #v << "[][]:" << nl;\
for (int i = 0; i < sz1; ++i) {std::cout << i << ":";for (int j = 0; j < sz2; ++j) std::cout << v[i][j] << " "; std::cout<<nl;}
using i64 = long long;
using i128 = __int128;
const int INF = 1e9;
int p[25] = {1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71};
void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 2), b(n + 2), c(n + 2), lc(n + 2);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }
    a[0] = a[n + 1] = 1;
    c[0] = c[n + 1] = 1;
    for (int i = 1; i <= n; ++i) {
        std::cin >> b[i];
    }
    for (int i = 1; i <= n; ++i) {
        lc[i] = std::lcm(std::gcd(a[i - 1], a[i]), std::gcd(a[i], a[i + 1]));
    }
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(25, -INF));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        if (lc[i] <= b[i] && lc[i] <= a[i]) c[i] = lc[i];
        else c[i] = a[i];
        for (int j = 0; j <= 20; ++j) {
            for (int k = 0; k <= 20; ++k) {
                if (std::gcd(c[i-1]*p[j], c[i]*p[k]) == std::gcd(a[i-1], a[i])) {
                    if (c[i] * p[k] == a[i]) {
                        dp[i][k] = std::max(dp[i][k], dp[i-1][j]);
                    }else if (1LL * c[i] * p[k] <= b[i]) dp[i][k] = std::max(dp[i][k], dp[i-1][j]+1);
                }
            }
        }
    }
    int ans = -INF;
    for (int i = 0; i <= 20; ++i) {
        ans = std::max(ans, dp[n][i]);
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
