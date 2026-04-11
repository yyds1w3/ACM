#include <bits/stdc++.h>
#include <iomanip>
using i64 = long long;
using i128 = __int128;
#define nl "\n"

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int x, y;
    std::cin >> x >> y;
    int p = 0;
    for (int i = 1; i <= 6; ++i) {
        for (int j = 1; j <= 6; ++j) {
            if (i + j >= x || std::abs(i - j) >= y) p++;
        }
    }
    std::cout << std::setprecision(9) << std::fixed << (double)p / 36;
}
