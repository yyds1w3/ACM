//Sun May 10 01:09:19 PM CST 2026
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
        int n;
        std::cin >> n;
        std::vector<int> g(n);
        int idx1 = 1;
        int idx2 = n - 1;
        for (int i = 1; i < n; ++i){
            if (i & 1) g[i] = idx1++;
            else g[i] = idx2--;
        }
        for (int i = 1; i <= n; ++i) {
            if (i == 1) std::cout << g[i] << " ";
            else if (i == n) std::cout << g[i - 1] << " ";
            else std::cout << g[i-1] * g[i] << " ";
        }
        std::cout << nl;
    }
}
