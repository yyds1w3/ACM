//Wed May  6 11:03:57 PM CST 2026
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
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> s(n);
    std::vector<int> cnt(n);
    for (int i = 0; i < n; ++i) std::cin >> s[i];
    for (int j = 0; j < m; ++j) {
        std::vector<int> c0, c1;
        for (int i = 0; i < n; ++i) {
            if (s[i][j] == '0') c0.push_back(i);
            else c1.push_back(i);
        }
        if (!c0.empty() && !c1.empty()) {
            if (c0.size() < c1.size()) {
                for (int v : c0) {
                    cnt[v]++;
                }
            }else {
                for (int v : c1) {
                    cnt[v]++;
                } 
            }
        }
    }
    debug(cnt);
    std::vector<int> ans;
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        if (mx < cnt[i]) {
            ans.clear();
            mx = cnt[i];
            ans.push_back(i);
        }else if (mx == cnt[i]) {
            ans.push_back(i);
        }
    }
    for (int v : ans) {
        std::cout << v + 1 << " ";
    }
    std::cout << nl;
}
