#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128;
#define nl "\n"
void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] > s[i + 1]) {
            for (int j = i + 1; j < n; ++j) {
                if (s[j] > s[i]) {
                    // [0, i) [i + 1, j) [i, i + 1) [j, n) 
                    std::cout << s.substr(0, i) << s.substr(i + 1, j - i - 1) << s.substr(i, 1) << s.substr(j) << nl;
                    return;
                }
            }
            std::cout << s.substr(0, i) << s.substr(i + 1, n - i - 1) << s.substr(i, 1) << s.substr(n) << nl;
            return;
        }
    }
    std::cout << s << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
}
