//Sun Apr 26 12:32:51 PM CST 2026
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

struct st {
    i64 val;
    int i, j, k;
    bool operator<(const st& other) const {return val > other.val;}
};

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
        std::vector<i64> a(n), b(n), c(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            std::cin >> b[i];
        }
        for (int i = 0; i < n; ++i) {
            std::cin >> c[i];
        }
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());
        std::sort(c.begin(), c.end());

        std::priority_queue<st> q;
        using State = std::tuple<int, int, int>;
        std::set<State> st;
        q.push({a[0] * b[0] * c[0], 0, 0, 0});
        st.insert({0, 0, 0});
        int rank = 0;
        while (rank < m && !q.empty()) {
            auto [val, i, j, k] = q.top();
            q.pop();
            rank++;
            std::cout << val << " ";
            if (i < n - 1 && !st.count({i + 1, j, k})) {
                q.push({a[i + 1] * b[j] * c[k], i + 1, j, k});
                st.insert({i + 1, j, k});
            }
            if (j < n - 1 && !st.count({i, j + 1, k})){
                q.push({a[i] * b[j + 1] * c[k], i, j + 1, k});
                st.insert({i, j + 1, k});
            }
            if (k < n - 1 && !st.count({i, j, k + 1})) {
                q.push({a[i] * b[j] * c[k + 1], i, j, k + 1});
                st.insert({i, j, k + 1});
            }
        }
        std::cout << nl;
    }
}
