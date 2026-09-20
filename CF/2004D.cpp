//Fri Aug 21 09:23:19 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cout << #x << ": " << x << nl 
#define debugv(v, sz) do{std::cout << #v << "[]:" << nl;\
for (int i = 0; i < sz; ++i) std::cout << v[i] << " "; std::cout << nl;}while(0)
#define debugvv(v, sz1, sz2) do{std::cout << #v << "[][]:" << nl;\
for (int i = 0; i < sz1; ++i) {std::cout << i << ":";for (int j = 0; j < sz2; ++j) std::cout << v[i][j] << " "; std::cout<<nl;}}while(0)
using i64 = long long;
using i128 = __int128;
int id[128];
void solve() {
    int n, q;
    std::cin >> n >> q;
    std::vector<std::vector<int>> a(1<<4);
    std::vector<std::string> s(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> s[i];
        a[(1 << id[s[i][0]]) + (1 << id[s[i][1]])].push_back(i);
    }
    while (q--) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        if (x > y) std::swap(x, y);
        int idx = (1 << id[s[x][0]]) + (1 << id[s[x][1]]);
        int idy = (1 << id[s[y][0]]) + (1 << id[s[y][1]]);
        if (idx & idy) {
            std::cout << y - x << nl;
            continue;
        }
        int ans = 1e9;
        for (int i = 0; i < (1 << 4); ++i) {
            if (__builtin_popcount(i) == 2) {
                if ((i & idx) && (i & idy)) {
                    auto it = std::upper_bound(a[i].begin(), a[i].end(), x);
                    if (it != a[i].end()) {
                        if (*it < y) {
                            ans = y - x;
                        }else {
                            ans = std::min(ans, *it * 2 - x - y);
                        }
                    }
                    if (it != a[i].begin()) {
                        it--;
                        ans = std::min(ans, x - *it + y - *it);
                    }
                }
            }
        }
        if (ans == 1e9) std::cout << -1 << nl;
        else std::cout << ans << nl;
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    id['B'] = 0;
    id['G'] = 1;
    id['R'] = 2;
    id['Y'] = 3;
    int t;
    std::cin >> t;
    while (t--) solve();
}
