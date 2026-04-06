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
    auto f = [] (auto self, int n) -> void {
        bool first = true;
        while (n) {
            int t = std::__lg(n);
            if (!first) std::cout << "+";
            if (t == 1) {
                std::cout << "2";
            }else if (t == 0) {
                std::cout << "2(0)";
            }else {
                std::cout << "2(";
                self(self, t);
                std::cout << ")";
            }
            n -= (1 << t);
            first = false;
        }
    };
    f(f, n);
}
