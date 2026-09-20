//Sat May 30 12:51:12 PM CST 2026
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
void solve() {
    int n;
    std::cin >> n;
    std::multiset<int> a;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        a.insert(x);
    }
    int mask = (1LL << 31) - 1;
    int ans = 0;
    while (!a.empty()) {
        auto it = a.begin();
        auto itt = a.find(mask - *it);
        a.erase(it);
        if (itt != a.end()) {
            a.erase(itt);
        }
        ans++;
    }
    std::cout << ans << nl;
}
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
        solve();
    }
}
