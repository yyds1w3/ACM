#include <bits/stdc++.h>
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
    int ans = 10000 - (100 * (y + 100 - x)) / 2;
    std::cout << ans << nl;
}
