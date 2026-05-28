//Sat Apr 18 09:07:14 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#define debug_range(...) 43
#endif
using i64 = long long;
using i128 = __int128;

void solve() {
    int n, a, b;
    std::cin >> n >> a >> b;
    if (n % 2 != 0 || ((a + b) % 2 == 0)) {
        std::cout << "No" << nl;
        return;
    }
    std::cout << "Yes" << nl;
    int row1 = 1, row2 = n;
    int col1 = 1, col2 = n;
    std::string s1, s2;
    while (row2 - row1 > 1 || col2 - col1 > 1) {
        if (a > row1 + 1) {
            s1 += std::string(col2 - col1, 'R') + 'D' + std::string(col2 - col1, 'L') + 'D';
            row1 += 2;
        }else if (b > col1 + 1) {
            s1 += std::string(row2 - row1, 'D') + 'R' + std::string(row2 - row1, 'U') + 'R';
            col1 += 2;
        }else if (a < row2 - 1) {
            s2 = "D" + std::string(col2 - col1, 'L') + 'D' + std::string(col2 - col1, 'R') + s2;
            row2 -= 2;
        }else if (b < col2 - 1) {
            s2 = "R" + std::string(row2 - row1, 'U') + 'R' + std::string(row2 - row1, 'D') + s2;
            col2 -= 2;
        }
    }
    if (a == row1 && b == col1 + 1) {
        std::cout << s1 << "DR" << s2 << nl;
    }else {
        std::cout << s1 << "RD" << s2 << nl;
    }
    
}

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
}
