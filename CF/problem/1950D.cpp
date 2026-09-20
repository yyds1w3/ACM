//Fri May 29 10:40:32 PM CST 2026
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
std::vector<bool> can(1e5 + 1);
std::vector<int> a;
void init() {
    auto dfs = [&](auto self, int x) -> void {
        if (x > 1e5) return;
        can[x] = true;
        a.push_back(x);
        self(self, 10 * x + 1);
        self(self, 10 * x);
    };
    dfs(dfs, 10);
    dfs(dfs, 11);
}
void solve() {
    int n;
    std::cin >> n;
    auto f = [](auto self, int n) -> bool {
        if (n == 1 || can[n]) return true;
        for (int x : a) {
            if (n % x == 0) {
                if (self(self, n / x)) {
                    return true;
                }
            }
        }
        return false;
    };
    if (f(f, n)) std::cout << "YES" << nl;
    else std::cout << "NO" << nl;
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
    init();
    while (t--) {
        solve();
    }
}
