//Fri Aug  7 10:58:29 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
using i128 = __int128;
#define debug(x) std::cerr << #x << ": " << x << nl; 
void solve() {
    int n, m, x, y;
    std::cin >> n >> m >> x >> y;
    std::vector<int> a(x), b(y);
    for (int i = 0; i < x; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < y; ++i) {
        std::cin >> b[i];
    }
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    auto f = [&](int tx, int ty) -> i64 {
        i64 res = 0;
        int i = x - 1;
        int j = y - 1;
        int k = 0;
        while ((tx > 0 || ty > 0 || k > 0) && (i >= 0 || j >= 0)) {
            int vA = (i >= 0) ? a[i] : -1;
            int vB = (j >= 0) ? b[j] : -1;
            if (vA > vB) {
                if (tx > 0) {
                    tx--;
                    res += vA;
                }else if (k > 0) {
                    k--;
                    res += vA;
                }
                i--;
            }else if (vA < vB) {
                if (ty > 0) {
                    ty--;
                    res += vB;
                }else if (k > 0) {
                    k--;
                    res += vB;
                }
                j--;
            }else {
                res += vA;
                if (tx > 0 && ty > 0) {
                    tx--;
                    ty--;
                    k++;
                }else if (tx > 0) {
                    tx--;
                }else if (ty > 0) {
                    ty--;
                }else if (k > 0) {
                    k--;
                }
                i--;
                j--;
            }
        }
        return res;
    };
    std::cout << std::max(f(n-1, m), f(n, m-1)) << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
