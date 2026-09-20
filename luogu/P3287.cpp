//Tue Aug 11 02:25:44 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
using i128 = __int128;
#define debug(x) std::cerr << #x << ": " << x << nl; 
int dp[5502][502];
void insert(int posX, int posY, int x) {
    for (int i = posX; i <= 5501; i += i & -i) {
        for (int j = posY; j <= 501; j += j & -j) {
            dp[i][j] = std::max(dp[i][j], x);
        }
    }
}
// [1, posX];
int query(int posX, int posY) {
    int res = 0;
    for (int i = posX; i >= 1; i -= i & -i) {
        for (int j = posY; j >= 1; j -= j & -j) {
            res = std::max(res, dp[i][j]);
        }
    }
    return res;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        for (int j = k + 1; j >= 1; --j) {
            int h = a[i] + j;
            int cur = query(h, j) + 1;
            ans = std::max(ans, cur);
            insert(h, j, cur);
        }
    }
    std::cout << ans << nl;
}
