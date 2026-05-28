//Fri May 22 04:29:52 PM CST 2026
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
    std::string s;
    std::cin >> s;
    std::vector<i64> a(n), c(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    for (int i = 0; i < n; ++i) std::cin >> c[i];
    if (!std::is_sorted(c.begin(), c.end())) {
        std::cout << "NO" << nl;
        return;
    }
    int lst = -1; // 可以动的未知数
    i64 b = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') lst = i;
        b += a[i];

        if (b > c[i]) {
            if (lst == -1) {
                std::cout << "NO" << nl;
                return;
            }
            a[lst] -= b - c[i];
            b = c[i];
        }

        if (i == 0 || c[i] > c[i - 1]) {
            if (b < c[i]) {
                if (lst == i) {
                    a[i] += c[i] - b;
                    b = c[i];
                }else {
                    std::cout << "NO" << nl;
                    return;
                }
            }
            lst = -1;
        }else {
            if (b < c[i] && lst == i) {
                a[i] += c[i] - b;
                b = c[i];
            }
        }
    }
    std::cout << "YES" << nl;
    for (int i = 0; i < n; ++i) std::cout << a[i] << " ";
    std::cout << nl;
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
