//Wed Jun 17 07:37:35 PM CST 2026
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
    int n, m, L;
    std::cin >> n >> m >> L;
    std::vector<std::array<int, 2>> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i][0] >> a[i][1];
    }
    std::sort(a.begin(), a.end());
    for (int i = 0; i < m; ++i) {
        std::cin >> b[i][0] >> b[i][1];
    }
    std::sort(b.begin(), b.end());
    i64 cur = 1;
    int j = 0;
    int cnt = 0;
    std::priority_queue<int> pak;
    i64 add = 0;
    for (int i = 0; i < n; ++i) {
        i64 need = a[i][1] - a[i][0] + 2;
        while (j < m && b[j][0] < a[i][0]) {
            add += b[j][1];
            pak.push(b[j][1]);
            j++;
        }
        if (cur + add < need) {
            std::cout << -1 << nl;
            return;
        }else {
            while (cur < need) {
                cur += pak.top();
                add -= pak.top();
                pak.pop();
                cnt++;
            }
        }
        // debug(cur);
    }
    std::cout << cnt << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
