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
    std::cin >> n;
    std::vector<std::string> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }
    std::set<std::string> st;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            st.insert(v[i] + v[j]);
            st.insert(v[j] + v[i]);
        }
    }
    std::cout << st.size() << nl;
}
