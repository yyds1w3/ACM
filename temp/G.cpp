#include <bits/stdc++.h>
#include <vector>
using i64 = long long;
using i128 = __int128;
#define nl "\n"
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }
    int k;
    std::cin >> k;
    for (int q = 1; q <= k; ++q) {
        std::vector<int> xz(m + 1);   
        int id;
        while (std::cin >> id) {
            if (id == 0) break;
            xz[a[id]]++;
        }
        bool f = true;
        for (int i = 1; i <= m; ++i) {
            if (xz[i] != 0) {
                if (!f) {
                    std::cout << " ";
                }
                std::cout << "B" << i << "-" << xz[i];
                f = false;
            }
        }
        std::cout << nl;
    }
}
