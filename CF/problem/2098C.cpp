//Wed Jun 17 02:44:26 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#endif
using i64 = long long;
using i128 = __int128;
void solve() {
    int n;
    std::cin >> n;
    std::map<int, int> m;
    bool f = false;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        m[x]++;
        if (m[x] >= 4) f = true;
    }
    if (f) {
        std::cout << "YES" << nl;
        return;
    }
    int tot = 0;
    for (auto it = m.begin(); it != m.end(); ++it) {
        if (it != m.begin() && it->first != std::prev(it)->first + 1) {
            tot = 0;
        }
        if (it->second >= 2) {
            tot++;
            if (tot >= 2) {
                std::cout << "YES" << nl;
                return;
            }
        }
    }
    std::cout << "NO" << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
