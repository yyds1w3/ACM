//Wed May 13 06:33:48 PM CST 2026
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
    std::vector<int> a(n);
    std::vector<int> b(n + 1);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        b[a[i]]++;
    }
    for (int i = 1; i <= n; ++i) {
        if (b[i] % k != 0) {
            std::cout << 0 << nl;
            return;
        }else {
            b[i] /= k;
        }
    }
    std::vector<int> cnt(n + 1);
    i64 ans = 0;
    for (int l = 0, r = 0; l < n; ++l) {
        while (r < n && cnt[a[r]] < b[a[r]]) {
            cnt[a[r]]++;
            r++;
        }
        ans += r - l;
        cnt[a[l]]--;
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
    while (t--) {
        solve();
    }
}
