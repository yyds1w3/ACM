//Fri Jun  5 05:31:58 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#endif
using i64 = long long;
using i128 = __int128;
void solve() {
    int a, b, c;
    std::cin >> a >> b >> c;
    if (c == 0) {
        if (a > 0 && b == 0) {
            for (int i = 0; i < a; ++i) std::cout << 'L';
        }else if (b > 0 && a == 0) {
            for (int i = 0; i < b; ++i) std::cout << 'Q';
        }else {
            std::cout << -1;
        }
        return;
    }
    if (c & 1) {
        int k = (c + 1) / 2;
        if (a < k || b < k) {
            std::cout << -1;
            return;
        }
        std::cout << std::string(a - k, 'L');
        for (int i = 0; i < k; ++i) std::cout << "LQ";
        std::cout << std::string(b - k, 'Q');
    }else {
        int k = c / 2;
        if (a >= k + 1 && b >= k) {
            std::cout << std::string(a - k - 1, 'L');
            for (int i = 0; i < k; ++i) std::cout << "LQ";
            std::cout << std::string(b - k, 'Q');
            std::cout << 'L';
            return;
        }
        if (a >= k && b >= k + 1) {
            for (int i = 0; i < k; ++i) std::cout << "QL";
            std::cout << std::string(b - k, 'Q');
            return;
        }
        std::cout << -1;
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    solve();
}
