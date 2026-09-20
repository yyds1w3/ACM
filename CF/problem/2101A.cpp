//Sun May 31 02:35:13 PM CST 2026
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
    std::vector<std::vector<int>> a(n, std::vector<int>(n));
    int l = n / 2, r = n / 2;
    for (int k = 0; k < n; ++k) {
        int mid = k * (k + 1);
        if (k & 1) {
            a[l][l] = mid;
            for (int i = l + 1; i <= r; ++i) {
                a[l][i] = mid + (i - l);
                a[i][l] = mid - (i - l);
            }
            r++;
        }else {
            a[r][r] = mid;
            for (int i = r - 1; i >= l; --i) {
                a[r][i] = mid + (r - i);
                a[i][r] = mid - (r - i);
            }
            l--;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << a[i][j] << " ";
        }
        std::cout << nl;
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
