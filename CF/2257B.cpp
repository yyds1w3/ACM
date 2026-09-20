//Mon Aug 17 10:48:27 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cerr << #x << ": " << x << nl; 
using i64 = long long;
using i128 = __int128;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    for (int i = 0; i < m; ++i) std::cin >> b[i];
    i64 tot1 = 0, tot2 = 0;
    for (int i = 0; i < n  - 1; ++i) {
        tot1 += a[i] - a[i + 1] + 1;
    }
    tot1 += a[n - 1];
    for (int i = 0; i < m - 1; ++i) {
        tot2 += b[i] - b[i + 1] + 1;
    }
    tot2 += b[m - 1];
    if (tot1 >= tot2) {
        std::cout << 1 << nl;
    }else {
        std::cout << 2 << nl;
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
