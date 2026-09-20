//Sat Jul 25 08:02:49 PM CST 2026
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
    int m, d;
    std::cin >> m >> d;
    std::string s;
    std::cin >> s;
    int n = s.size();
    std::vector<int> a(n, 1);
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'G') {
            for (int j = std::max(0, i - d); j <= std::min(n - 1, i + d); ++j) {
                a[j] = 0;
            }
        }
    }
    std::cout << std::accumulate(a.begin(), a.end(), 0) << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    solve();
}
