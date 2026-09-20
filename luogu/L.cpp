//Fri Aug  7 12:33:59 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
using i128 = __int128;
#define debug(x) std::cerr << #x << ": " << x << nl; 

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    i64 n;
    std::cin >> n;
    i64 ans = 0;
    for (i64 b = 1; b * b <= n; ++b) {
        i64 start = b * b;
        i64 len = std::lcm(b, b+1);
        i64 cap = b;
        i64 tot = n - start + 1;
        i64 step = tot / len;
        ans += cap * step;
        ans += std::min(tot - step * len, cap); 
    }
    std::cout << ans << nl;
}
