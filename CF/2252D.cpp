//Mon Aug 31 03:00:40 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
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
    std::vector<i64> a(n), d(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        d[i] = a[i + 1] - a[i];
    }
    int l = 0;
    for (int r = 0; r < n - 1; ++r) {
        if (r != 0 && (d[r] + d[r - 1]) % 2 != 0){
            std::sort(d.begin() + l, d.begin() + r);
            l = r;
        }
    }
    std::sort(d.begin() + l, d.begin() + n-1);
    for (int i = 0; i < n - 1; ++i) {
        a[i + 1] = a[i] + d[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << nl;

}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
