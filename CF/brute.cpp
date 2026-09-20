//Sun Sep 20 12:03:49 AM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
void solve() {
    int n, k;
    std::cin >> n >> k;
    std::string s, rs;
    std::cin >> s;
    std::queue<std::pair<int,std::string>> q;
    q.push({0, s});
    while (!q.empty()) {
        auto [cnt, s] = q.front();
        q.pop();
        rs = s;
        std::reverse(rs.begin(), rs.end());
        if (s < rs) {
            std::cout << "YES" << nl;
            return;
        }
        if (cnt < k) {
            for (int i = 0; i < n; ++i) {
                for (int j = i; j < n; ++j) {
                    std::swap(s[i], s[j]);
                    q.push({cnt+1, s});
                    std::swap(s[i], s[j]);
                }
            }
        }
    }
    std::cout << "NO" << nl;

}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
}
