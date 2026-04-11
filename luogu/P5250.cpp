//2026-04-09 21:22:32
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
    #endif
    int m;
    std::cin >> m;
    std::set<int> st;
    for (int i = 0; i < m; ++i) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int len;
            std::cin >> len;
            if (st.find(len) != st.end()) {
                std::cout << "Already Exist" << nl;
            }else {
                st.insert(len);
            }
        }else if (op == 2) {
            int len;
            std::cin >> len;
            if (st.empty()) {
                std::cout << "Empty" << nl;
            }else {
                auto it = st.lower_bound(len);
                if (it == st.end()) {
                    std::cout << *std::prev(it) << nl;
                    st.erase(std::prev(it));
                }else if (it == st.begin()) {
                    std::cout << *it << nl;
                    st.erase(it);
                }else {
                    int d1 = *it - len;
                    int d2 = len - *std::prev(it);
                    if (d2 <= d1) {
                        std::cout << *std::prev(it) << nl;
                        st.erase(std::prev(it));
                    }else {
                        std::cout << *it << nl;
                        st.erase(it);
                    }
                }
            }
        }
    }
}
