//Wed Apr 29 10:16:10 PM CST 2026
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
    std::vector<std::vector<int>> a(3, std::vector<int>(3));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cin >> a[i][j];
        }
    }
    for (int i = 0; i < 3; ++i) {
        int A = a[0][i % 3];
        int B = a[0][(i + 1) % 3];
        int C = a[0][(i + 2) % 3];
        for (int cut = 5; cut < A; cut += 5) {
            std::vector<int> r1 = {cut, B, (180 - cut - B)};
            std::vector<int> r2 = {A - cut, C, (180 - C - A + cut)};
            std::sort(r1.begin(), r1.end());
            std::sort(r2.begin(), r2.end());
            if ((r1 == a[1] || r1 == a[2]) && (r2 == a[1] || r2 == a[2])) {
                std::cout << "YES" << nl;
                return;
            }
        }
    }
    std::cout << "NO" << nl;
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
