//Wed Jul 22 02:24:10 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#endif
using i64 = long long;
using i128 = __int128;
std::set<i64> st;
void solve() {
    int x;
    std::cin >> x;

    for (auto it = st.begin(); it != st.end(); ++it) {
        int y = *it;
        if (y < 2) continue;
        if (y > 1e9) break;
        i64 z = 1LL * x * y;
        int cnt[10] = {0};
        while (z) {
            cnt[z % 10]++;
            z /= 10;
        }
        int c = 0;
        for (int i = 0; i < 10; ++i) {
            if (cnt[i] > 0) {
                c++;
            }
        }
        if (c <= 2) {
            std::cout << y << nl;
            return;
        }
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    auto dfs = [&](auto self, int idx, int x1, int x2, i64 val) -> void {
        st.insert(val);
        if (idx >= 9) {
            return;
        }
        self(self, idx + 1, x1, x2, 10 * val + x1);
        self(self, idx + 1, x1, x2, 10 * val + x2);
    };
    for (int i = 0; i < 10; ++i) {
        for (int j = i + 1; j < 10; ++j) {
            if (i != 0) dfs(dfs, 0, i, j, i);
            if (j != 0) dfs(dfs, 0, i, j, j);
        }
    }
    for (int i = 0; i < 9; ++i) {
        i64 val = 0;
        for (int j = 1; j < 10; ++j) {
            val = val * 10 + j;
            st.insert(val);
        }
    }
    int t;
    std::cin >> t;
    while (t--) solve();
}
