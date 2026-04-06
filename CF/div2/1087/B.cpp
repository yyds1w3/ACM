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
    int t;
    std::cin >> t;
    while(t--){
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            int gre = 0, les = 0;
            for (int j = i + 1; j < n; ++j) {
                if (a[j] > a[i]) {
                    gre++;
                }else if(a[j] < a[i]) {
                    les++;
                }
            }
            std::cout << std::max(gre, les) << " ";
        }
        std::cout << nl;
    }

}
