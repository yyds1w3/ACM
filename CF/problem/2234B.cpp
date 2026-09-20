//Thu Jun 11 04:25:45 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#endif
using i64 = long long;
using i128 = __int128;
std::vector<i64> a;
void solve() {
    i64 n;
    std::cin >> n;
    i64 rem = n % 12;
    i64 a;
    if (rem != 10) {
        a = rem;
    }else{
        a = 22;
    }
    if (n < a) {
        std::cout << -1 << nl;
    }else {
        std::cout << a << " " << n - a << nl;
    }

}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
