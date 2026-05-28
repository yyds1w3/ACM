//Mon Apr 20 07:37:12 PM CST 2026
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
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    int n, k, x;
    std::cin >> n >> k >> x;
    std::vector<std::string> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    int tot = 1;
    for (int i = 0; i < k; ++i) {
        tot *= n;
    }
    std::vector<std::string> ans;
    auto dfs = [&](auto self, int len, std::string path) -> void {
        if (len == k) {
            ans.push_back(path);
            return;
        }
        for (int i = 0; i < n; ++i) {
            self(self, len + 1, path + a[i]);
        }
    };
    dfs(dfs, 0, "");
    std::sort(ans.begin(), ans.end());
    std::cout << ans[x - 1] << nl;
}
