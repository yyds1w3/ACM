//Sat Jun 13 07:54:59 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#endif
using i64 = long long;
using i128 = __int128;
void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        a[i]--;
    }

    int ans = 0;
    std::vector<std::vector<bool>> pos(n + 1, std::vector<bool>(n + 1));
    for (int i = 0; i < n - 1; ++i) {
        std::vector<int> cnt(n + 1);
        int mn = n + 1, mx = -1;

        for (int j = i; j >= 0; --j) {
            cnt[a[j]]++;
            if (cnt[a[j]] > 1) break;
            mn = std::min(mn, a[j]);
            mx = std::max(mx, a[j]);
            int len = i - j + 1;
            if (mx - mn == len - 1) {
                pos[len][mn] = true;
            }
        }
        cnt.assign(n + 1, 0);
        mn = n + 1, mx = -1;
        for (int j = i + 1; j < n; ++j) {
            cnt[a[j]]++;
            if (cnt[a[j]] > 1) break;
            mn = std::min(mn, a[j]);
            mx = std::max(mx, a[j]);
            int len = j - i;
            if (mx - mn == len - 1) {
                if (mn - len >= 0 && pos[len][mn - len]) {
                    ans = std::max(ans, len);
                }
                if (mx + 1 < n && pos[len][mx + 1]) {
                    ans = std::max(ans, len);
                }
            }
        }
    }
    std::cout << ans << nl;

}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
