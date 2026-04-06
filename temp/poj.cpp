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
    while (std::cin >> n && n != 0) {
        if (n == 1) {
            std::cout << 0 << nl;
            continue;
        }

        std::vector<int> path;
        path.push_back(1);

        auto dfs = [&](auto self, int depth, int limit) -> bool {
            if (depth == limit) {
                return path.back() == n;
            }
            int mxVal = *std::max_element(path.begin(), path.end());
            if  (mxVal * (1 << (limit - depth)) < n) {
                return false;
            }
            int cur = path.back();
            for (int i = path.size() - 1; i >= 0; --i) {
                path.push_back(cur + path[i]);
                if (self(self, depth + 1, limit)) return true;
                path.pop_back();
                if (cur > path[i]) {
                    path.push_back(cur - path[i]);
                    if (self(self, depth + 1, limit)) return true;
                    path.pop_back();
                }
            }
            return false;
        };
        for (int limit = 1; ; ++limit) {
            if (dfs(dfs, 0, limit)) {
                std::cout << limit << nl;
                break;
            }
        }
    }
}
