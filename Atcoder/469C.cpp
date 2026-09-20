//Sat Aug  1 08:04:04 PM CST 2026
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
    std::vector<int> a(n);
    int now = 0;
    for (int i = 0; i < n; ++i) {
        now++;
        a[i] = now;
        if (s[i] == 'o') now--;
    }
    int k = 1;
    for (int i = 0; i < n; ++i) {
        if (k < a[i]) {
            std::cout << i << nl;
            k++;
        }
    }
    while (k <= n) {
        std::cout << n << nl;
        k++;
    }
}
