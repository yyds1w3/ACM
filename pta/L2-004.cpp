//Thu Apr 16 06:30:53 PM CST 2026
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
    int n;
    std::cin >> n;
    std::vector<int> pre(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> pre[i];
    }
    std::vector<int> post;
    auto check =[&](auto self, int l, int r, bool mirr) -> bool {
        if (l == r) return true;
        int root = pre[l];
        int split = l + 1;
        if (!mirr) {
            while (split < r && pre[split] < root) {
                split++;
            }
            for (int i = split; i < r; ++i) {
                if (pre[i] < root) return false;
            }
        }else {
            while (split < r && pre[split] >= root) {
                split++;
            }
            for (int i = split; i < r; ++i) {
                if (pre[i] >= root) return false;
            }
        }
        if (!self(self, l + 1, split, mirr)) return false;
        if (!self(self, split, r, mirr)) return false;
        post.push_back(root);
        return true;
    };
    if (check(check, 0, n, false)) {
        std::cout << "YES" << nl;
        for (int i = 0, sz = post.size(); i < sz; ++i) {
            std::cout << post[i] << " \n"[i == sz - 1];
        }
    }else{
        post.clear();
        if (check(check, 0, n, true)) {
            std::cout << "YES" << nl;
            for (int i = 0, sz = post.size(); i < sz; ++i) {
                std::cout << post[i] << " \n"[i == sz - 1];
            }
        }else {
            std::cout << "NO" << nl;
        }
    }
}
