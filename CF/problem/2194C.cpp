//Fri May  1 07:02:07 PM CST 2026
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

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<std::vector<char>> a(k, std::vector<char>(n));
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> a[i][j];
        }
    }
    for (int len = 1; len * len <= n; ++len) {
        if (n % len != 0) continue;
        std::string s;
        s.resize(len);
        bool f0 = true;
        for (int i = 0; i < len; ++i) {
            bool f1 = false;
            for (int j = 0; j < k; ++j) {
                bool f2 = true; 
                for (int p = i + len; p < n; p += len) {
                    bool f3 = false;
                    for (int r = 0; r < k; ++r) {
                        if (a[r][p] == a[j][i]) {
                            f3 = true;
                            break;
                        }
                    }
                    if (!f3) {
                        f2 = false;
                        break;
                    }
                }
                if (f2) {
                    s[i] = a[j][i];
                    f1 = true;
                    break;
                }
            }
            if (!f1) {
                f0 = false;
                break;
            }
        }
        if (f0) {
            for (int i = 0; i < n / len; ++i) {
                std::cout << s;
            }
            std::cout << nl;
            return;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
}
