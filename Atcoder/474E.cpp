//Fri Sep 11 12:21:00 PM CST 2026
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
std::ostream& operator<<(std::ostream& os, Node& rhs) {
    return os << "[" << "," << "]";
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n), d(n);
    int mnA = 2e9;
    i64 res = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i] >> b[i];
        d[i] = a[i] - b[i];
        mnA = std::min(mnA, a[i]);
        res += a[i];
    }
    i64 ans = res;
    std::sort(d.rbegin(), d.rend());
    for (int k = 0; k <= n; ++k) { // [0, k) [k, n)
        if (k > 0) {
            res -= d[k-1];
        }
        ans = std::min(ans, res + 1LL * mnA * std::max(0, (2 * k - n)));
    }
    std::cout << ans << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
