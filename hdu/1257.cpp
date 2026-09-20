//Mon Jul 27 08:24:31 PM CST 2026
#include <iostream>
#include <set>
#include <vector>
#define nl "\n"
using i64 = long long;
void solve() {
    int n;
    while (std::cin >> n) {
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        std::set<int> st;
        for (int i = 0; i < n; ++i) {
            auto it = st.lower_bound(a[i]);
            if (it == st.end()) {
                st.insert(a[i]);
            }else {
                st.erase(it);
                st.insert(a[i]);
            }
        }
        std::cout << st.size() << nl;
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    solve();
}
