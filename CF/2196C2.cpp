//Sat Aug 29 12:03:31 PM CST 2026
#include <bits/stdc++.h>
#define nl std::endl
#define debug(x) std::cout << #x << ": " << x << nl 
#define debugv(v, sz) do{std::cout << #v << "[]:" << nl;\
for (int i = 0; i < sz; ++i) std::cout << v[i] << " "; std::cout << nl;}while(0)
#define debugvv(v, sz1, sz2) do{std::cout << #v << "[][]:" << nl;\
for (int i = 0; i < sz1; ++i) {std::cout << i << ":";for (int j = 0; j < sz2; ++j) std::cout << v[i][j] << " "; std::cout<<nl;}}while(0)
using i64 = long long;
using i128 = __int128;
struct st {
};
std::ostream& operator<<(std::ostream& os, st& rhs) {
    return os;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<bool>> g(n + 1, std::vector<bool>(n + 1));
    int idx = 1;
    int cnt = 0;
    while (true) {
        std::cout << "? " << idx << nl;
        int x;
        std::cin >> x;
        std::vector<int> a(x);
        for (int i = 0; i < x; ++i) {
            std::cin >> a[i];
        }
        if (a[0] != 1) break;
        for (int i = 0; i < x - 1; ++i) {
            if (g[a[i]][a[i+1]] == false) {
                g[a[i]][a[i+1]] = true;
                cnt++;
            }
        }
        idx++;
    }
    std::cout << "! " << cnt << nl;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (g[i][j]) {
                std::cout << i << " " << j << nl;
            }
        }
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
