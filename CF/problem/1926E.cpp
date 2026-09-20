//Sat May 30 12:57:30 PM CST 2026
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
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a;
    while (n) {
        a.push_back((n + 1) / 2);
        n /= 2;
    }
    int tot = 0, p2 = 1;
    for (int x : a) {
        if (tot < k && k <= tot + x) {
            std::cout << p2 * (2 * (k - tot) - 1) << nl;
            return;
        }
        tot += x;
        p2 *= 2;
    }

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
