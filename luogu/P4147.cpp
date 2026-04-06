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
    int n, m;
    std::cin >> n >> m;
    std::vector a(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            std::cin >> c;
            if (c == 'F') {
                a[i][j] = 1;
            }
        }
    }
    std::vector<i64> h(m);
    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
        std::vector<int> stk;
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 0) {
                h[j] = 0;
            }else {
                h[j]++;
            }
            while (!stk.empty() && h[stk.back()] >= h[j]) {
                int idx = stk.back();
                stk.pop_back();
                int l = stk.empty() ? -1 : stk.back();
                int r = j;
                ans = std::max(ans, (h[idx] * (r - l - 1))); // [l + 1, r)
            }
            stk.push_back(j);
        }
        while (!stk.empty()) {
            int idx = stk.back();
            stk.pop_back();
            int l = stk.empty() ? -1 : stk.back();
            int r = m;
            ans = std::max(ans, (h[idx] * (r - l - 1))); // [l + 1, r)
        }
    }
    std::cout << 3 * ans << nl;

}
