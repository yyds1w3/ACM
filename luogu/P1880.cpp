//Thu Aug  6 04:22:39 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
#define debug(x) std::cerr << #x << ": " << x << nl; 
int dp1[201][201];
int dp2[201][201];
const int INF = 0x3f3f3f3f;
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> a(2 * n + 1);
    std::vector<int> pref(2 * n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        a[i + n] = a[i];
    }
    for (int i = 1; i <= 2 * n; ++i) {
        pref[i] = pref[i-1] + a[i];
    }

    for (int i = 1; i <= 2 * n; ++i) dp1[i][i] = dp2[i][i] = 0;
    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i + len - 1 <= 2 * n; ++i) {
            int j = i + len - 1;
            dp1[i][j] = INF;
            dp2[i][j] = 0;
            for (int k = i; k < j; ++k) {
                dp1[i][j] = std::min(dp1[i][j], dp1[i][k] + dp1[k+1][j] + pref[j] - pref[i-1]);
                dp2[i][j] = std::max(dp2[i][j], dp2[i][k] + dp2[k+1][j] + pref[j] - pref[i-1]);
            }
        }
    }
    int ans1 = INF;
    int ans2 = 0;
    for (int i = 1; i <= n; ++i) {
        ans1 = std::min(ans1, dp1[i][i+n-1]);
        ans2 = std::max(ans2, dp2[i][i+n-1]);
    }
    std::cout << ans1 << nl << ans2 << nl;
}
