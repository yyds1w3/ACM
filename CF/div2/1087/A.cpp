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
    i64 n, c, k;
    std::cin >> n >> c >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        if (c < a[i]) {
            std::cout << c << nl;
            return ;
        }else {
            int add = std::min(c - a[i], k);
            k -= add;
            c += a[i] + add;
        }
    }
    std::cout << c << nl;

}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
}
