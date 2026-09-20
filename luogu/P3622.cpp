//Mon Jul 20 03:16:58 PM CST 2026
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
    int n;
    std::cin >> n;
    std::string s;
    auto dfs = [&](auto self, int idx) -> void {
        if (idx == n) {
            std::cout << s << nl;
            return;
        }
        s += 'N';
        self(self, idx + 1);
        s.pop_back();
        s += 'Y';
        self(self, idx + 1);
        s.pop_back();
    };
    dfs(dfs, 0);
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    solve();
}
