//Tue Sep  8 06:16:19 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int m;
    while (std::cin >> m) {
        if (m == 0) break;
        int cnt = 0, sum = 0;
        std::vector<int> a(m);
        for (int i = 0; i < m; ++i) {
            std::cin >> a[i];
            sum ^= a[i];
        }
        if (sum == 0) {
            std::cout << 0 << nl;
            continue;
        }
        for (int i = 0; i < m; ++i) {
            int cur = sum ^ a[i];
            if (a[i] > cur) cnt++;
        }
        std::cout << cnt << nl;
    }
}
