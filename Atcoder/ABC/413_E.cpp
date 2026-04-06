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
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> p(1 << n);
        for (int i = 0; i < (1 << n); ++i) {
            std::cin >> p[i];
        } 
        auto f = [&] (auto self, int l, int r) -> std::vector<int> {
            if (r - l == 1) return {p[l]};
            int mid = (r + l) / 2;
            std::vector<int> a = self(self, l, mid);
            std::vector<int> b = self(self, mid, r);
            if (a[0] > b[0]) swap(a, b);
            a.insert(a.end(), b.begin(), b.end());
            return a;
        };
        std::vector<int> ans = f(f, 0, (1 << n));
        for (int i = 0; i < (1 << n); ++i) {
            std::cout << ans[i] << " \n"[i == (1 << n) - 1];
        }

    }
}
