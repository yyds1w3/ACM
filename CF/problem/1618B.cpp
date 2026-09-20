//Mon Jun 15 12:30:12 PM CST 2026
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
    std::vector<std::string> a(n - 2);
    std::string s;
    int cnt = 0;
    for (int i = 0; i < n - 2; ++i) {
        std::cin >> a[i];
        if (i == 0 || a[i - 1][1] != a[i][0]) {
            s += a[i];
            cnt++;
        }else {
            s += a[i][1];
        }
    }
    if (cnt < 2) {
        s += 'b';
    }
    std::cout << s << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
