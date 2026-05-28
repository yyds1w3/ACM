//Thu Apr 23 05:41:41 PM CST 2026
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
    int n, m;
    std::cin >> n >> m;
    std::map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        mp[x]++;
    }
    for (int i = 0; i < m; ++i) {
        int x;
        std::cin >> x;
        if (mp.find(x) != mp.end()) {
            if (mp[x] > 0) {
                mp[x]--;
            }
        }
    }
    for (auto [num, tim] : mp) {
        for (int i = 0; i < tim; ++i) {
            std::cout << num << " "; 
        }
    }
}
