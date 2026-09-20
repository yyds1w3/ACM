//Tue Aug  4 10:33:30 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
#define debug(x) std::cerr << #x << ": " << x << nl; 

void solve() {
    std::vector<int> a(3);
    for (int i = 0; i < 3; ++i) std::cin >> a[i];
    std::sort(a.begin(), a.end());
    std::cout << std::min(a[1] - a[0], a[2] - a[1]) << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
