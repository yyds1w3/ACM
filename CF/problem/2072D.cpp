//Sun May 31 03:58:10 PM CST 2026
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
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    // less - greater;
    int mx = -1;
    std::pair<int, int> ans;
    for (int l = 0; l < n; ++l) {
        int cur = 0;
        for (int r = l; r < n; ++r) {
            if (a[r] > a[l]) {
                cur--;
            }else if (a[r] < a[l]) {
                cur++;
            }
            if (cur > mx) {
                mx = cur;
                ans = {l, r};
            }
        }
    }
    std::cout << ans.first + 1 << " " << ans.second + 1 << nl;
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
