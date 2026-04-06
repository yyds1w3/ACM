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
    double pi = 3.141592653589793;
    int d;
    std::cin >> d;
    std::cout << std::setprecision(6) << std::fixed << pi * d * d / 4 << nl;
}
