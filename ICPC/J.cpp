//Wed Sep  9 07:17:49 PM CST 2026
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
const int N = 500;
const int INF = 1e9;
int dp[N][N];
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> pos(n);
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        x--;
        pos[x] = i;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            dp[i][j] = INF;
        }
    }
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i + len - 1 < n; ++i) {
            int j = i + len - 1;
            for (int k = i; k < j; ++k) { // [i, k] [k+1, j]
                dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k+1][j] + std::abs(pos[i] - pos[k+1]));
            }
        }
    }
    std::cout << dp[0][n-1] << nl;
}
