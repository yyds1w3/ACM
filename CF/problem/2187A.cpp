//Fri May  1 09:37:21 PM CST 2026
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
    if (std::is_sorted(a.begin(), a.end())) {
        std::cout << -1 << nl;
        return;
    }
    auto b = a;
    std::sort(b.begin(), b.end());
    auto check = [&](int x) -> bool {
        for (int i = 0; i < n; ++i) {
            if ((a[i] != b[i]) && (a[i] - b[0] < x) && (b[n-1] - a[i] < x)) {
                return false;
            }
        }
        return true;
    };
    int l = 0, r = b[n-1] - b[0];
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (check(mid)) {
            l = mid;
        }else {
            r = mid - 1;
        }
    }
    std::cout << l << nl;
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
