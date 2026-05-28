//Mon Apr 20 08:10:52 PM CST 2026
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
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n), b(n);
    i64 tot = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        tot += a[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
        tot += b[i];
    }
    std::sort(a.begin(), a.end(), std::greater<int>());
    std::sort(b.begin(), b.end());
    int i = 0, j = 0;
    int c = 0;
    while (i < n && j < n) {
        if (a[i] + b[j] >= m) {
            i++;
            j++;
            c++;
        }else {
            j++;
        }
    }
    tot -= (i64)c * m;
    std::cout << tot << nl;
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
