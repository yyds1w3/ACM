// Fri May  8 09:29:34 PM CST 2026
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
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        std::string s;
        std::cin >> s;
        std::set<std::pair<int, int>> st;
        auto ins = [&](int x) -> void {
            int l = x, r = x;
            auto it = st.upper_bound({x, 2e9});  // [x + 1 ,...]
            if (it != st.begin()) {
                auto p = std::prev(it);
                if (p->second >= x) return;
                if (p->second == x - 1) {
                    l = p->first;
                    st.erase(p);
                }
            }
            it = st.upper_bound({x, 2e9});
            if (it != st.end() && it->first == x + 1) {
                r = it->second;
                st.erase(it);
            }
            st.insert({l, r});
        };
        for (int i = 0; i < m; ++i) {
            int x;
            std::cin >> x;
            ins(x);
        }
        int pos = 1;
        int lst = 1;
        for (int i = 0; i < n; ++i) {
            pos = lst;
            for (int j = std::max(0, i - 1); j <= i; ++j) {
                if (s[j] == 'A') {
                    pos++;
                } else {
                    pos++;
                    auto it = st.upper_bound({pos, 2e9});
                    if (it != st.begin()) {
                        auto p = std::prev(it);
                        if (p->first <= pos && pos <= p->second) {
                            pos = p->second + 1;
                        }
                    }
                }
                if (j == i - 1) lst = pos;
            }
            ins(pos);
        }
        i64 tot = 0;
        for (auto [l, r] : st) {
            tot += r - l + 1;
        }
        std::cout << tot << nl;
        for (auto [l, r] : st) {
            for (int i = l; i <= r; ++i) {
                std::cout << i << " ";
            }
        }
        std::cout << nl;
    }
}
