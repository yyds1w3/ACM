//Thu Sep 10 02:31:32 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cout << #x << ": " << x << nl 
#define debugv(v, sz) do{std::cout << #v << "[]:" << nl;\
for (int i = 0; i < sz; ++i) std::cout << v[i] << " "; std::cout << nl;}while(0)
#define debugvv(v, sz1, sz2) do{std::cout << #v << "[][]:" << nl;\
for (int i = 0; i < sz1; ++i) {std::cout << i << ":";for (int j = 0; j < sz2; ++j) std::cout << v[i][j] << " "; std::cout<<nl;}}while(0)
using i64 = long long;
using i128 = __int128;
struct Node {
};
std::ostream& operator<<(std::ostream& os, Node& rhs) {
    return os << "[" << "," << "]";
}

const int N = 100;
int dp[N][N];
void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++i) dp[i][i] = 1;
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i + len - 1 < n; ++i) {
            int j = i + len - 1;
            dp[i][j] = dp[i][j-1] + 1;
            for (int k = i; k < j; ++k) { // [i, k] [k + 1, j - 1]
                if (a[k] == a[j]) {
                    dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k+1][j-1]);
                }
            }
        }
    }
    std::cout << dp[0][n-1] << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    int kcse = 1;
    while (t--) {
        std::cout << "Case " << kcse << ": ";
        solve();
        kcse++;
    }
}
