//Fri Jun  5 07:23:24 PM CST 2026
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
    std::vector<i64> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    i64 cnt = 0;
    std::vector<i64> c(n);
    for (int i = 1; i < n; ++i) {
        if (a[i - 1] > a[i]) {
            i64 k = std::__lg((a[i - 1] - 1) / a[i]) + 1;
            c[i] = c[i - 1] + k;
        }else {
            i64 k = std::__lg(a[i] / a[i - 1]);
            c[i] = std::max(0LL, c[i - 1] - k);
        }
        cnt += c[i];
    }
    std::cout << cnt << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    solve();
}
