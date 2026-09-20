//Tue Aug  4 10:51:19 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
#define debug(x) std::cerr << #x << ": " << x << nl; 

void solve() {
    int n;
    std::cin >> n;
    std::string a, b;
    std::cin >> a >> b;
    if (n < 3 && a != b) {
        std::cout << -1 << nl;
        return;
    }
    std::vector<std::vector<int>> ca(2);
    std::vector<std::vector<int>> cb(2);
    for (int i = 0; i < n; ++i) {
        if (a[i] == '1') ca[i%2].push_back(i);
        if (b[i] == '1') cb[i%2].push_back(i);
    }
    i64 cnt = 0;
    for (int i = 0; i < 2; ++i) {
        if (ca[i].size() != cb[i].size()) {
            std::cout << -1 << nl;
            return;
        }
        int m = ca[i].size();
        for (int j = 0; j < m; ++j) {
            cnt += std::abs(cb[i][j] - ca[i][j]) / 2;
        }
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
