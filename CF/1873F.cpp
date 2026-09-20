//Fri Aug 28 12:19:09 PM CST 2026
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
    i64 n, k;
    std::cin >> n >> k;
    std::vector<i64> a(n), h(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> h[i];
    }

    i64 tot = 0;
    int mx = 0;
    int l = 0;
    for (int r = 0; r < n; ++r) {
        if (r > 0 && h[r-1] % h[r] != 0) {
            l = r;
            tot = 0;
        }
        tot += a[r];
        while (tot > k) {   
            tot -= a[l++];
        }
        mx = std::max(mx, r - l + 1);
    }
    std::cout << mx << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
