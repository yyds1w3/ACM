//Fri Jun 12 11:01:30 PM CST 2026
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
    // odd -> YES
    // even -> NO
    // [x, x + k];
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    bool ok = false;
    int cnt = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] == a[i - 1]) {
            cnt++;
        }else {
            if (cnt % 2 == 0) ok = true;
            if (a[i] - a[i - 1] <= k) ok = true;
            cnt = 1;
        }
    }
    if (cnt % 2 == 0) ok = true;
    if (ok) {
        std::cout << "YES" << nl;
    }else {
        std::cout << "NO" << nl;
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
