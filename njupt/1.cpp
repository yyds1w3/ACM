//Mon Aug 17 01:59:55 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cerr << #x << ": " << x << nl; 
using i64 = long long;
using i128 = __int128;

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    i64 tot = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        tot += a[i];
    }
    i64 target = tot / 2;
    i64 cur = 0;
    std::sort(a.begin(), a.end());
    for (int i = n - 1; i >= 0; --i) {
        if (cur + a[i] <= target) {
            cur += a[i];
        }
    }
    std::cout << tot - 2 * cur << nl;
}
