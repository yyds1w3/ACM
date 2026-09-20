//Sat Aug  1 08:01:27 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
#define debug(x) std::cerr << #x << ": " << x << nl; 

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    s = 'x' + s;
    s += 'x';
    n += 2;
    int ans = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (s[i - 1] == 'x' && s[i] == 'x' && s[i + 1] == 'x') {
            ans++;
        }
    }
    std::cout << ans << nl;
}
