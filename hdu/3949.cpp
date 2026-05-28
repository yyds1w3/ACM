//Mon Apr 27 07:25:05 PM CST 2026
#include <iostream>
#include <vector>
#define nl "\n"
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    if (std::cin >> t) {
        for (int case_num = 1; case_num <= t; ++case_num) {
            int n;
            std::cin >> n;
            std::vector<i64> d(64);
            for (int i = 0; i < n; ++i) {
                i64 x;
                std::cin >> x;
                for (int j = 63; j >= 0; --j) {
                    if ((x >> j) & 1) {
                        if (d[j] == 0) {
                            d[j] = x;
                            break;
                        } else {
                            x ^= d[j];
                        }
                    }
                }
            }
            for (int i = 63; i >= 0; --i) {
                if (d[i]) {
                    for (int j = i - 1; j >= 0; --j) {
                        if ((d[i] >> j) & 1) {
                            if (d[j]) {
                                d[i] ^= d[j];
                            }
                        }
                    }
                }
            }
            
            std::vector<i64> p;
            for (int i = 0; i < 64; ++i) {
                if (d[i]) {
                    p.push_back(d[i]);
                }
            }
            bool canZero = (p.size() < n);
            int q;
            std::cin >> q;
            std::cout << "Case #" << case_num << ":" << nl;
            while (q--) {
                i64 k;
                std::cin >> k;
                if (canZero) k--;
                if (k == 0) {
                    std::cout << 0 << nl;
                    continue;
                }
                if (k >= (1ULL << p.size())) {
                    std::cout << -1 << nl;
                    continue;
                }
                i64 ans = 0;
                for (int i = 0; i < p.size(); ++i) {
                    if ((k >> i) & 1) {
                        ans ^= p[i];
                    }
                }
                std::cout << ans << nl;
            }
        }
    }
    return 0;
}
