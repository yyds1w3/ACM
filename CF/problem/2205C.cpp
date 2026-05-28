//Tue May  5 12:58:52 PM CST 2026
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
    std::vector<bool> vis(1e6 + 1);
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<std::vector<int>> a(n);
        for (int i = 0; i < n; ++i) {
            int m;
            std::cin >> m;
            std::vector<int> b(m);
            for (int j = 0; j < m; ++j) {
                std::cin >> b[j];
            }
            for (int j = b.size() - 1; j >= 0; --j) {
                if (!vis[b[j]]) {
                    vis[b[j]] = true;
                    a[i].push_back(b[j]);
                }
            }
            for (int j = 0; j < (int)a[i].size(); ++j) {
                vis[a[i][j]] = false;
            }
        }
        std::vector<int> printed;
        std::vector<bool> posted(n);
        for (int s = 0; s < n; ++s) {
            int bestIdx = -1;
            std::vector<int> bestU;
            for (int i = 0; i < n; ++i) {
                if (posted[i]) continue;
                std::vector<int> u;
                for (int x : a[i]) {
                    if (!vis[x]) {
                        u.push_back(x);
                    }
                }
                if (bestIdx == -1 || u < bestU) {
                    bestIdx = i;
                    bestU = u;
                }
            }
            posted[bestIdx] = true;
            for (int x : bestU) {
                std::cout << x << " ";
                vis[x] = true;
                printed.push_back(x);
            }
        }
        std::cout << nl;
        for (int x : printed) {
            vis[x] = false;
        }

    }
}
