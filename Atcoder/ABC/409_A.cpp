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
    int n;
    std::string s1, s2;
    std::cin >> n >> s1 >>s2;
    for (int i = 0; i < n; ++i) {
        if (s1[i] == 'o' && s2[i] == 'o') {
            std::cout << "Yes" << nl;
            return 0;
        }
    }
    std::cout << "No" << nl;
}
