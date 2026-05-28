//Tue Apr 21 06:11:42 PM CST 2026
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#define nl "\n"

using i64 = long long;



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
        int n, m;
        std::cin >> n >> m;
        std::vector<std::vector<bool>> dist(n, std::vector<bool>(n, 0));
        for (int i = 0; i < m; ++i) {
            int u, v;
            std::cin >> u >> v;
            u--, v--;
            dist[u][v] = 1;
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                if (dist[i][k] == 0) continue;
                for (int j = 0; j < n; ++j) {
                    dist[i][j] = dist[i][j] | (dist[i][k] & dist[k][j]);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ans += (!dist[i][j] && !dist[j][i]); 
            }
        }
        std::cout << ans << nl;
    }
}
