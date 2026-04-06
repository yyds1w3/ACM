#include <bits/stdc++.h>
using i64 = long long;
#define nl "\n"

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);

    int t;
    if (!(std::cin >> t)) return 0;

    while (t--) {
        i64 a, b, c, m;
        std::cin >> a >> b >> c >> m;
        i64 lab = std::lcm(a, b);
        i64 lac = std::lcm(a, c);
        i64 lbc = std::lcm(b, c);
        i64 labc = std::lcm(lab, c);
        i64 abc = m / labc;
        i64 ab = (m / lab) - abc;
        i64 ac = (m / lac) - abc;
        i64 bc = (m / lbc) - abc;
        i64 a1 = (m / a) - abc - ab - ac;
        i64 b1 = (m / b) - abc - ab - bc;
        i64 c1 = (m / c) - abc - ac - bc;
        i64 ans_a = a1 * 6 + (ab + ac) * 3 + abc * 2;
        i64 ans_b = b1 * 6 + (ab + bc) * 3 + abc * 2;
        i64 ans_c = c1 * 6 + (ac + bc) * 3 + abc * 2;
        std::cout << ans_a << " " << ans_b << " " << ans_c << nl;
    }
    
    return 0;
}
