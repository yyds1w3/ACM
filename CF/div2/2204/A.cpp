#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128;
#define nl "\n"

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::string s;
        std::cin >> s;
        int ball = 0;
        std::set<int> st;
        for (int i = 0; i < n; ++i) {
            st.insert(ball);
            if (s[ball] == 'R') {
                ball++;
            }else {
                ball--;
            }
        }
        st.insert(ball);
        std::cout << st.size() << nl;
    }
}
