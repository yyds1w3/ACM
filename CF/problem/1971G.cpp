//Mon May 25 03:19:18 PM CST 2026
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
        std::map<int, std::vector<int>> m;
        std::vector<int> f(n);
        for (int i = 0; i < n; ++i) {
            int x;
            std::cin >> x;
            f[i] = x >> 2;
            m[x >> 2].push_back(x);
        }
        for (auto &[c, v] : m) {
            std::sort(v.rbegin(), v.rend());
        }
        for (int i = 0; i < n; ++i) {
            std::cout << m[f[i]].back() << " ";
            m[f[i]].pop_back();
        }
        std::cout << nl;
    }
}
