//Tue May 26 07:30:03 PM CST 2026
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
struct Point {
    int x, y;
};
void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> a(n, std::vector<int>(m));
    int mx = 0;
    std::vector<Point> b;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] > mx) {
                b.clear();
                mx = a[i][j];
                b.push_back({i, j});
            }else if (a[i][j] == mx) {
                b.push_back({i, j});
            }
        }
    }
    bool possible = false;
    int r1 = b[0].x;
    int c1 = -1;
    bool ok1 = true;
    for (int i = 1; i < (int)b.size(); ++i) {
        if (b[i].x != r1) {
            if (c1 == -1) {
                c1 = b[i].y;
            } else if (c1 != b[i].y) {
                ok1 = false;
                break;
            }
        }
    }
    if (ok1) possible = true;
    int c2 = b[0].y;
    int r2 = -1;
    bool ok2 = true;
    for (int i = 1; i < (int)b.size(); ++i) {
        if (b[i].y != c2) {
            if (r2 == -1) {
                r2 = b[i].x;
            } else if (r2 != b[i].x) {
                ok2 = false;
                break;
            }
        }
    }
    if (ok2) possible = true;
    if (possible) {
        std::cout << mx - 1 << nl;
    } else {
        std::cout << mx << nl;
    }
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
