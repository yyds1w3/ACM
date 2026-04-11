#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128;
#define nl "\n"

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    std::string s;
    std::cin >> s;
    int n = s.size();
    i64 ans = n;
    for (int i = n - 1, u = 0, v = 0; i >= 0; --i) {
        u = s[i] - '0';
        ans += (u - v + 10) % 10;
        v = u;
    }
    std::cout << ans << nl;
}
