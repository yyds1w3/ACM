//Thu May 14 01:03:23 PM CST 2026
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


int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    int t;
    std::cin >> t;
    while (t--) {
        int n, m, k;
        std::cin >> n >> m >> k;
        std::vector<std::pair<int, int>> W, B;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if ((i + j) & 1) W.push_back({i, j});
                else B.push_back({i, j});
            }
        }
        if (n >= m) {
            std::sort(W.begin(), W.end(), [](auto& lhs, auto& rhs){
                if (lhs.first != rhs.first) return lhs.first > rhs.first;
                return false;
            });
            std::sort(B.begin(), B.end(), [](auto& lhs, auto& rhs){
                if (lhs.first != rhs.first) return lhs.first > rhs.first;
                return false;
            });
        }else {
            std::sort(W.begin(), W.end(), [](auto& lhs, auto& rhs){
                if (lhs.second != rhs.second) return lhs.second > rhs.second;
                return false;
            });
            std::sort(B.begin(), B.end(), [](auto& lhs, auto& rhs){
                if (lhs.second != rhs.second) return lhs.second > rhs.second;
                return false;
            });
        }
        std::vector<std::pair<int, int>> cells;
        cells.insert(cells.end(), W.begin(), W.end());
        cells.insert(cells.end(), B.begin(), B.end());
        std::vector<std::vector<int>> ans(n, std::vector<int>(m));
        int c = n * m / k;
        for (int i = 0; i < n * m; ++i) {
            ans[cells[i].first][cells[i].second] = (i / c) + 1;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                std::cout << ans[i][j] << " ";
            }
            std::cout << nl;
        }
    }
}
