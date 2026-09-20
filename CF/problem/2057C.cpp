//Mon Jun  8 10:29:42 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#endif
using i64 = long long;
using i128 = __int128;
void solve() {
    // 111 ==> 00
    // 110 ==> 10
    // 100 ==> 10
    // 000 ==> 00
    // 10000
    // 01111
    // ?????
    int l, r;
    std::cin >> l >> r;
    int k = 31 - __builtin_clz(l ^ r);
    int b = l | ((1 << k) - 1);
    int a = b + 1;
    int c = l;
    while (c == a || c == b) c++;
    std::cout << a << " " << b << " " << c << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
