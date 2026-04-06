#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128;
#define nl "\n"

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n;
    std::cin >> n;
   
    std::vector a(n + 1, std::vector<int>(n + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            std::cin >> a[i][j];
            a[i][j] += a[i - 1][j];
        }
    }
    int ans = -1e9;
    for (int tp = 1; tp <= n; ++tp) {
        for (int bt = tp; bt <= n; ++bt) {
            int cur = 0;
            for (int j = 1; j <= n; ++j) {
                int val = a[bt][j] - a[tp - 1][j];
                cur = std::max(val, cur + val);
                ans = std::max(ans, cur);
            }
        }
    }
    std::cout << ans << nl;
        
}
