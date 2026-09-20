//Fri Jun  5 07:55:34 PM CST 2026
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
    // 10 -> 5 --> [1, 45];
    // 101 -> 25;
    // 1010 -> 125;
    i64 n;
    std::cin >> n;
    i64 L = 2;
    i64 p5 = 5;
    while (true) {
        i64 cnt = 9 * p5;
        if (n > cnt) {
            n -= cnt;
            L++;
            p5 *= 5;
        }else break;
    }
    std::cout << (n - 1) / p5 + 1;
    bool odd = ((n - 1) / p5 + 1) & 1;
    n = (n - 1) % (p5) + 1;
    for (int i = 1; i < L; ++i) {
        p5 /= 5;
        if (odd) {
            std::cout << (n - 1) / p5 * 2;
        }else {
            std::cout << (n - 1) / p5 * 2 + 1;
        }
        odd ^= 1;
        n = (n - 1) % p5 + 1;
    }
    std::cout << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    solve();
}
