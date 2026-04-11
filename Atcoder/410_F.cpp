#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#define debug_range(...) 43
#endif
using i64 = long long;
using i128 = __int128;
void solve() {
    int h, w;
    std::cin >> h >> w;
    std::vector<std::vector<int>> a(h + 1, std::vector<int>(w + 1));
    for (int i = 1; i <= h; ++i){
        for (int j = 1; j <= w; ++j) {
            char c;
            std::cin >> c;
            a[i][j] = (c == '#' ? 1 : -1);
        }
    }
    if (h > w) {
        std::vector<std::vector<int>> trans(w + 1, std::vector<int>(h + 1));
        for (int i = 1; i <= h; ++i) {
            for (int j = 1; j <= w; ++j) {
                trans[j][i] = a[i][j];
            }
        }
        a = std::move(trans);
        std::swap(h, w);
    }
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            a[i][j] = a[i][j] + a[i-1][j] + a[i][j-1] - a[i-1][j-1];
        }
    }
    i64 ans = 0;
    int offset = h * w;
    std::vector<int> cnt(2 * offset + 1, 0);
    for (int u = 1; u <= h; ++u) {
        for (int d = u; d <= h; ++d) {
            for (int j = 0; j <= w; ++j) {
                int sum = a[d][j] - a[u-1][j];
                ans += cnt[sum + offset];
                cnt[sum + offset]++;
            }
            for (int j = 0; j <= w; ++j) {
                int sum = a[d][j] - a[u - 1][j];
                cnt[sum + offset]--;
            }
        }
    }
    std::cout << ans << nl;

}

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int t;
    std::cin >> t;
    while(t--) {
        solve();
    }
}
