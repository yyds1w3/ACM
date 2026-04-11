#include <bits/stdc++.h>
#include <vector>
using i64 = long long;
using i128 = __int128;
#define nl "\n"
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n;
    std::cin >> n;
    std::vector<i64> a(n+1), b(n+1);
    for (int i = 1; i <= n; ++i) {
        int x; 
        std::cin >> x;
        a[i] = x;
        b[i] = (i64)a[i] + b[i-1];
    }
    i64 ans = 0;
    for (int i = n; i >= 2; --i) {
        ans += a[i] * b[i-1];
    }
    std::cout << ans << nl; 

}

