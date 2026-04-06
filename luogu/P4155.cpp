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
    int id;
    int l, r;
    bool operator<(const st& other) const {
        if (l != other.l) {
            return l < other.l;
        }
        return r < other.r;
    }
};

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n, m;
    std::cin >> n >> m;
    std::vector<st> a(2 * n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i].l >> a[i].r;
        a[i].id = i;

        if (a[i].l > a[i].r) {
            a[i].r += m;
        }
        a[i + n] = {a[i].id, a[i].l + m, a[i].r + m};
    }
    std::sort(a.begin(), a.end());
    std::vector sta(2 * n, std::vector<int>(20));
    for (int i = 0, j = 0; i < 2 * n; ++i) {
        while (j < 2 * n && a[j].l <= a[i].r) {
            j++;
        }
        j--;
        sta[i][0] = j;
    }
    for (int k = 1; k < 20; ++k) {
        for (int i = 0; i < 2 * n; ++i) {
            sta[i][k] = sta[sta[i][k-1]][k-1];
        }
    }
    std::vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        int cur = i;
        int target = a[i].l + m;
        int res = 1;
        for (int k = 19; k >= 0; --k) {
            if (a[sta[cur][k]].r < target) {
                cur = sta[cur][k];
                res += (1 << k);
            }
        }
        ans[a[i].id] = res + 1;
    }
    for (int i = 0; i < n; ++i) {
        std::cout << ans[i] << " ";
    }
    std::cout << nl;


}
