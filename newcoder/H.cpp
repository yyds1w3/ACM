//Wed Aug  5 12:43:52 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
#define debug(x) std::cerr << #x << ": " << x << nl; 

void solve() {
    int n;
    std::cin >> n;
    if (n == 3 || n == 4 || n == 6) {
        std::cout << -1 << nl;
        return;
    }
    
    int target = n - 1;
    bool is_prime = true;
    if (target <= 1) is_prime = false;
    for (int i = 2; i * i <= target; ++i) {
        if (target % i == 0) {
            is_prime = false;
            break;
        }
    }
    
    if (!is_prime) {
        for (int i = 1; i <= n; ++i) {
            std::cout << i << " ";
        }
        std::cout << nl;
    } else {
        for (int i = 1; i <= n - 4; ++i) {
            std::cout << i << " ";
        }
        for (int i = n; i >= n - 3; --i) {
            std::cout << i << " ";
        }
        std::cout << nl;
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
