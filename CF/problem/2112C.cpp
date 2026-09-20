//Sun May 31 11:35:41 AM CST 2026
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
    std::sort(a.begin(), a.end());
    i64 ans = 0;
    for (int i = 2; i < n; ++i) {
        int target = std::max(a[i] , a[n - 1] - a[i]);
        int l = 0, r = i - 1;
        while (l < r) {
            if (a[l] + a[r] > target) {
                ans += r - l; // [l, r), r;
                r--;
            }else {
                l++;
            }
        }
    }
    std::cout << ans << nl;
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
