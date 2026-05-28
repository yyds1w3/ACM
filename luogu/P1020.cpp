//Thu Apr 16 10:52:16 PM CST 2026
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
    std::vector<int> a;
    int x;
    while (std::cin >> x) {
        a.push_back(x);
    }
    int n = a.size();
    std::vector<int> dp;
    // >=  
    for (int i = 0; i < n; ++i) {
        auto it = std::upper_bound(dp.begin(), dp.end(), a[i], std::greater<int>());
        if (it == dp.end()) dp.push_back(a[i]);
        else *it = a[i];
    }
    std::cout << dp.size() << nl;
    dp.clear();
    // <
    for (int i = 0; i < n; ++i) {
        auto it = std::lower_bound(dp.begin(), dp.end(), a[i]);
        if (it == dp.end()) dp.push_back(a[i]);
        else *it = a[i];
    }
    std::cout << dp.size() << nl;
}
