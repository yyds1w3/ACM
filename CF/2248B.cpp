//Mon Aug  3 07:30:43 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
#define debug(x) std::cerr << #x << ": " << x << nl; 

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    for (int i = 0; i < m; ++i) std::cin >> b[i];
    if (n < 2 * m) {
        std::cout << "NO" << nl;
        return;
    }
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    for (int i = 0; i < m; ++i) {
        int down = std::lower_bound(a.begin(), a.end(), b[i]) - a.begin();
        if (i + 1 > down) {
            std::cout << "NO" << nl;
            return;
        }
    }
    for (int i = m - 1; i >= 0; --i) {
        int down = std::lower_bound(a.begin(), a.end(), b[i]) - a.begin();
        int up = n - down;
        if (m - i > up) {
            std::cout << "NO" << nl;
            return;
        }
    }
    
    std::cout << "YES" << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
