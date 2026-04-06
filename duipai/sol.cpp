#include <bits/stdc++.h>

#define nl '\n'
using i64 = long long;
using i128 = __int128;

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int a, b;
        std::cin >> a >> b;
        if (a == 1) std::cout << 1;
        std::cout << a + b << nl;
    }
}
