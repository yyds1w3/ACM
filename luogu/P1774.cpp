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
struct Fenwick {
    int n;
    std::vector<int> treeA;
    Fenwick(int n_ = 0) : n(n_) {
        treeA.assign(n + 1, 0);
    }

    void add(int pos) {
        for (int i = pos + 1; i <= n; i += i & -i) {
            treeA[i]++;
        }
    }
    int query(int pos) {
        int res = 0;
        for (int i = pos + 1; i > 0; i -= i & -i) {
            res += treeA[i];
        }
        return res;
    }
};

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i].first;
        a[i].second = i;
    }
    std::sort(a.begin(), a.end());
    std::vector<std::pair<int, int>> b = a;
    b[0].first = 0;
    int val = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i].first > a[i - 1].first) {
            val++;
        }
        b[i].first = val;
    }
    std::sort(b.begin(), b.end(), [](std::pair<int, int> &lhs, std::pair<int, int> &rhs){
        return lhs.second < rhs.second;
    });
    debug(b);
    Fenwick bit(n);
    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
        bit.add(b[i].first);
        ans += i + 1 - bit.query(b[i].first);
    }
    std::cout << ans << nl;

    

}
