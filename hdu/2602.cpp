//Mon Jul 27 07:24:39 PM CST 2026
#include <iostream>
#include <vector>
#include <algorithm>
#define nl "\n"
using i64 = long long;
void solve() {
    int n, v;
    std::cin >> n >> v;
    std::vector<int> a(n), b(n), dp(v + 1);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    for (int i = 0; i < n; ++i) std::cin >> b[i];
    for (int i = 0; i < n; ++i) {
        for (int j = v; j >= b[i]; --j) {
            dp[j] = std::max(dp[j - b[i]] + a[i], dp[j]);
        }
    }
    std::cout << dp[v] << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
