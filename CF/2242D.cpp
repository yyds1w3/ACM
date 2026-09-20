//Fri Aug 28 02:57:29 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cout << #x << ": " << x << nl 
#define debugv(v, sz) do{std::cout << #v << "[]:" << nl;\
for (int i = 0; i < sz; ++i) std::cout << v[i] << " "; std::cout << nl;}while(0)
#define debugvv(v, sz1, sz2) do{std::cout << #v << "[][]:" << nl;\
for (int i = 0; i < sz1; ++i) {std::cout << i << ":";for (int j = 0; j < sz2; ++j) std::cout << v[i][j] << " "; std::cout<<nl;}}while(0)
using i64 = long long;
using i128 = __int128;
struct st {
};
std::ostream& operator<<(std::ostream& os, st& rhs) {
    return os;
}

void solve() {
    std::string s, t;
    std::cin >> s >> t;
    int n = s.size();
    int m = t.size();
    std::vector<int> p1(n + 1), p2(m + 1);
    for (int i = 0; i < n; ++i) {
        p1[i + 1] = (p1[i] + (s[i] - '0')) % 10;
    }
    for (int i = 0; i < m; ++i) {
        p2[i + 1] = (p2[i] + (t[i] - '0')) % 10;
    }
    if (p1[n] != p2[m]) {
        std::cout << -1 << nl;
        return;
    }
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (p1[i] == p2[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            dp[i][j] = std::max(dp[i][j], std::max(dp[i-1][j], dp[i][j-1]));
        }
    }
    std::cout << dp[n][m] << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
