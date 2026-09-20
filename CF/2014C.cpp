//Sat Aug 29 01:32:26 PM CST 2026
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
const i64 INF = 1e18;
void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    i64 tot = 0;
    i64 j = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        tot += a[i];
        if (a[i] > a[j]) j = i;
    }
    if (n <= 2) {
        std::cout << -1 << nl;
        return;
    }
    auto ck = [&](i64 x) -> bool {
        std::vector<int> b = a;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (i == j) continue;
            if (2LL * b[i] * n < tot + x) cnt++;
            if (cnt * 2 > n) return true;
        }
        return false;
    };
    i64 l = 0, r = INF;
    while (l < r) {
        i64 mid = (l + r) >> 1;
        if (ck(mid)) {
            r = mid;
        }else l = mid + 1;
    }
    std::cout << l << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
