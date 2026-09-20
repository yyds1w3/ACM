//Thu Jul 23 03:23:19 PM CST 2026
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
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        if (x <= k) {
            a[i] = b[n - 1 - i] = 1;
        }else {
            a[i] = b[n - 1 - i] = -1;
        }
    }
    auto check = [&](const std::vector<int>& arr) -> bool {
        std::vector<int> p(n + 1);
        std::vector<int> msp(n + 2, -1e9);
        for (int i = 0; i < n; ++i) {
            p[i + 1] = p[i] + arr[i];
        }
        for (int i = n; i >= 1; --i) {
            msp[i] = std::max(msp[i + 1], p[i]);
        }
        for (int i = 1; i <= n; ++i) {
            if (p[i] >= 0 && msp[i + 1] >= p[i]) {
                return true;
            }
        }
        return false;
    };
    if (check(a) || check(b)) {
        std::cout << "YES" << nl;
        return;
    }
    int x = n + 1, y = 0;
    int pp = 0;
    for (int i = 1; i <= n; ++i) {
        pp += a[i - 1];
        if (pp >= 0) {
            x = i;
            break;
        }
    }
    int sp = 0;
    for (int i = n; i >= 1; --i) {
        sp += a[i - 1];
        if (sp >= 0) {
            y = i;
            break;
        }
    }
    if (x <= y - 2) {
        std::cout << "YES" << nl;
        return;
    }
    std::cout << "NO" << nl;


}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
