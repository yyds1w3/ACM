//Tue Sep  8 10:45:48 PM CST 2026
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
    i64 x, y, k;
    std::cin >> x >> y;
    std::cin >> k;
    // [0, k)
    i64 ans = 0;
    if (k > y) {
        for (int i = 0; i < y; ++i) {
            ans += (y + i) % (x + i);
        }
        ans += (y - x) * (k - y); //[y, k)
    }else {
        for (int i = 0; i < k; ++i) {
            ans += (y + i) % (x + i);
        }
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
