//Thu Sep 10 04:12:28 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cout << #x << ": " << x << nl 
#define debugv(v, sz) do{std::cout << #v << "[]:" << nl;\
for (int i = 0; i < sz; ++i) std::cout << v[i] << " "; std::cout << nl;}while(0)
#define debugvv(v, sz1, sz2) do{std::cout << #v << "[][]:" << nl;\
for (int i = 0; i < sz1; ++i) {std::cout << i << ":";for (int j = 0; j < sz2; ++j) std::cout << v[i][j] << " "; std::cout<<nl;}}while(0)
using i64 = long long;
using i128 = __int128;
struct Node {
};
// b[i, j] = i 到 j 的a的票 pp[i][j];
// c[i, j] = i 到 j 的b的票
void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 2), p(n + 2);
    std::vector<std::vector<int>> pp(n + 2, std::vector<int>(n + 2));
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }
    auto check = [&](int x) -> bool {
        for (int i = 1; i <= n; ++i) {
            p[i] = p[i - 1] + (a[i] >= x ? 1 : -1); // b[i, j] = p[j] - p[i - 1];
        }
        for (int len = 1; len <= n; ++len) { // c[i][j] = sum(b[x][y], i<=x<=y<=j)
            for (int i = 1; i + len - 1 <= n; ++i) {
                int j = i + len - 1;
                pp[i][j] = pp[i][j-1] + pp[i+1][j] - pp[i+1][j-1] + (p[j] - p[i - 1] > 0 ? 1 : -1);
            }
        }
        i64 res = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                res += (pp[i][j] > 0 ? 1 : -1);
            }
        }
        return res > 0;
    };
    int l = 1, r = 1e9 + 1;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (check(mid)) {
            l = mid;
        }else {
            r = mid - 1;
        }
    }
    std::cout << l << nl;

}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    solve();
}
