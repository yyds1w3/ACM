//Thu May 14 12:21:54 PM CST 2026
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
    std::string p, s;
    std::cin >> p >> s;
    std::vector<std::pair<char, int>> v1, v2;
    int c = 1;
    for (int i = 1, sz = p.size(); i < sz; ++i) {
        if (p[i] == p[i - 1]) {
            c++;
        }else {
            v1.push_back({p[i - 1], c});
            c = 1;
        }
    }
    v1.push_back({p.back(), c});
    c = 1;
    for (int i = 1, sz = s.size(); i < sz; ++i) {
        if (s[i] == s[i - 1]) {
            c++;
        }else {
            v2.push_back({s[i - 1], c});
            c = 1;
        }
    }
    v2.push_back({s.back(), c});
    if (v1.size() != v2.size()) {
        std::cout << "NO" << nl;
        return;
    }
    for (int i = 0, sz = v1.size(); i < sz; ++i) {
        auto [ch1, cnt1] = v1[i];
        auto [ch2, cnt2] = v2[i];
        if (ch1 != ch2 || cnt2 < cnt1 || cnt2 > cnt1 * 2) {
            std::cout << "NO" << nl;
            return;
        }
    }
    std::cout << "YES" << nl;
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
