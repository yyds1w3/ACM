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
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n, q;
    std::cin >> n >> q;
    std::vector<int> cnt(n + 1);
    for (int i = 0; i < q; ++i) {
        int x;
        std::cin >> x;
        if (x > 0) {
            std::cout << x << " ";
            cnt[x]++;
        }else {
            int mn = 1000;
            int mn_id = 1;
            for (int j = 1; j <= n; ++j) {
                if (cnt[j] < mn) {
                    mn = cnt[j];
                    mn_id = j;
                }
            }
            std::cout << mn_id << " ";
            cnt[mn_id]++;
        }
    }
}
