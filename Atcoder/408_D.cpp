#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using i64 = long long;
using i128 = __int128;
#define nl "\n"

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::string s;
        std::cin >> s;
        std::vector<int> c(n + 1);
        for (int i = 0; i < n; ++i) {
            c[i + 1] = c[i] + (s[i] == '0' ? 1 : -1);
        }
        int sum = std::count(s.begin(), s.end(), '1');
        int res = 0;
        int ma = 0;
        for (int i = 0; i <= n; ++i) {
            res = std::min(res, c[i] - ma);
            ma = std::max(ma, c[i]);
        }
        std::cout << sum + res << nl;
    }
}
