//Thu Apr 16 06:54:49 PM CST 2026
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
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> a(n);
    for (int i = 0; i < n; ++i) {
        int m;
        std::cin >> m;
        for (int j = 0; j < m; ++j) {
            int x;
            std::cin >> x;
            a[i].push_back(x);
        }
        std::sort(a[i].begin(), a[i].end());
        a[i].erase(std::unique(a[i].begin(), a[i].end()), a[i].end());
    }
    int q;
    std::cin >> q;
    while (q--) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        auto i = a[u].begin();
        auto j = a[v].begin();
        int Nc = 0;
        while (i != a[u].end() && j != a[v].end()) {
            if (*i < *j) {
                i++;
            }else if (*i > *j){
                j++;
            }else {
                Nc++;
                i++;
                j++;
            }
        }
        int Nt = a[u].size() + a[v].size() - Nc;
        std::cout << std::setprecision(2) << std::fixed << (double)Nc / Nt * 100 << "%" << nl; 
    }
}
