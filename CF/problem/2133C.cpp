//Thu May 21 09:46:18 AM CST 2026
#include <bits/stdc++.h>
#define nl std::endl
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
        int n;
        std::cin >> n;
        std::vector<int> len(n);
        int k = 0;
        int u = -1;
        for (int i = 0; i < n; ++i) {
            std::cout << "?" << " " << i + 1 << " " << n;
            for (int j = 0; j < n; ++j) {
                std::cout << " " << j + 1;
            }
            std::cout << std::endl;
            std::cin >> len[i];
            if (len[i] > k) {
                u = i;
                k = len[i];
            }
        }
        std::vector<int> ans(n);
        std::iota(ans.begin(), ans.end(), 0);
        for (int i = 0; i < n; ++i) {
            if (i != u) {
                std::cout << "?" << " " << u + 1 << " " << ans.size() - 1;
                for (int j : ans) {
                    if (j != i) {
                        std::cout << " " << j + 1;
                    }
                }
                std::cout << std::endl;
                int l;
                std::cin >> l;
                if (l == k) {
                    std::erase(ans, i);
                }
            }
        }
        std::sort(ans.begin(), ans.end(), [&](int i, int j){
            return len[i] > len[j];
        });
        std::cout << "!" << " " << k;
        for (int i = 0; i < k; ++i) std::cout << " " << ans[i] + 1;
        std::cout << nl;
    }
}
