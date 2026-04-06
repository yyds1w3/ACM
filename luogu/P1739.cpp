#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#define debug_range(...) 43
#endif
using i64 = long long;
using i128 = __int128;


int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    std::string s;
    std::cin >> s;
    int top = -1;
    for (int i = 0, n = s.size() - 1; i < n; ++i) {
        if (s[i] == '(') {
            ++top; 
        }else if (s[i] == ')') {
            if (top >= 0) { 
                --top;
            }else {
                std::cout << "NO" << nl;
                return 0;
            }
        }
    }
    if (top == -1) {
        std::cout << "YES" << nl;
    }else {
        std::cout << "NO" << nl;
    }
}
