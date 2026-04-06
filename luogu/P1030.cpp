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
    std::string sm, sl;
    std::cin >> sm >> sl;
    auto dfs = [&](auto self, std::string sm, std::string sl) -> void {
        if (sm.empty()) return;
        char root = sl.back();
        std::cout << root;
        int lsz = sm.find(root);
        int rsz = sl.size() - 1 - lsz;
        self(self, sm.substr(0, lsz), sl.substr(0, lsz));
        self(self, sm.substr(lsz + 1), sl.substr(lsz, rsz));
    };
    dfs(dfs, sm, sl);
}
