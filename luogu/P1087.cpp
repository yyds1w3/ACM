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
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    auto dfs = [&](auto self, int l, int r) -> int{
        if (r - l == 1) {
            if (s[l] == '0') {
                std::cout << "B";
            }else {
                std::cout << "I";
            }
            return s[l] - '0';
        } 
        if (r - l > 1) {
            int m = (l + r) / 2;
            int ls = self(self, l, m);
            int rs = self(self, m, r);
            if (ls == 0 && rs == 0) {
                std::cout << "B";
                return 0;
            }else if (ls == 1 && rs == 1) {
                std::cout << "I";
                return 1;
            }else {
                std::cout << "F";
                return 2;
            }
        }
        return -1;
    };
    dfs(dfs, 0, 1 << n);
}
