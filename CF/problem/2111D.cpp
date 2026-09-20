//Sun May 31 07:10:48 PM CST 2026
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
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(m);
    for (int i = 0; i < m; ++i) std::cin >> a[i];
    std::sort(a.begin(), a.end());
    for (int i = 0; i < n; i += 2) {
        if (i != n - 1) {
            for (int j = 0; j < 3; ++j) {
                std::cout << a[i / 2] << " " << a[m - 1 - i / 2] << " ";
            }
            std::cout << nl;
            for (int j = 0; j < 3; ++j) {
                std::cout << a[m - 1 - i / 2] << " " << a[i / 2] << " ";
            }
            std::cout << nl;
        }else {
            for (int j = 0; j < 3; ++j) {
                std::cout << a[i / 2] << " " << a[m - 1 - i / 2] << " ";
            }
            std::cout << nl;
        }
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
    while (t--) solve();
}
