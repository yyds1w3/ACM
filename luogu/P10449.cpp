//Mon Jul 20 03:49:20 PM CST 2026
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
    std::vector<std::vector<int>> a(5, std::vector<int>(5));
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            char c;
            std::cin >> c;
            a[i][j] = c - '0';
        }
    }
    int acnt = 1000;
    bool aok = false;
    auto dfs = [&](auto self, int idx, int cnt) -> void {
        if (idx == 5) {
            auto b = a;
            for (int i = 1; i < 5; ++i) {
                for (int j = 0; j < 5; ++j) {
                    if (b[i - 1][j] == 0) {
                        cnt++;
                        if (cnt > 6) return;
                        b[i][j] ^= 1;
                        b[i - 1][j] ^= 1;
                        if (j > 0) b[i][j - 1] ^= 1;
                        if (j < 4) b[i][j + 1] ^= 1;
                        if (i < 4) b[i + 1][j] ^= 1;
                    }
                }
            }
            bool ok = true;
            for (int j = 0; j < 5; ++j) {
                if (b[4][j] == 0) {
                    ok = false;
                }
            }
            if (ok) {
                aok = true;
                acnt = std::min(acnt, cnt);
            }
            return;
        }
        self(self, idx + 1, cnt);

        a[0][idx] ^= 1;
        if (idx > 0) a[0][idx - 1] ^= 1;
        if (idx < 4) a[0][idx + 1] ^= 1;
        a[1][idx] ^= 1;
        self(self, idx + 1, cnt + 1);
        a[0][idx] ^= 1;
        if (idx > 0) a[0][idx - 1] ^= 1;
        if (idx < 4) a[0][idx + 1] ^= 1;
        a[1][idx] ^= 1;
    };
    dfs(dfs, 0, 0);
    if (!aok || acnt > 6) {
        std::cout << -1 << nl;
    }else {
        std::cout << acnt << nl;
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
