//Fri Sep 11 03:04:19 PM CST 2026
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
    int n, k;
    std::cin >> n >> k;
    if (n % 2 == 0) {std::cout << "No" << nl; return;}
    if (k % 2 != 0) {std::cout << "No" << nl; return;}
    int mn = n - 1;
    int mx = (n * n - 1) / 2;
    if (k < mn || k > mx) {std::cout << "No" << nl; return;}
    std::cout << "Yes" << nl;
    int h = n, w = n, cur = k; std::string ans;
    while (h > 1 && w > 1) {
        int x = (h + 1) / 2 * (w - 3) + 2;
        if (cur <= x) {
            ans += std::string(h-1, 'D'); ans += 'R';
            ans += std::string(h-1, 'U'); ans += 'R';
            w -= 2;
            cur -= 2;
        }else {
            ans += std::string(w-1,'R'); ans += 'D';
            ans += std::string(w-1,'L'); ans += 'D';
            h -= 2;
            cur -= w - 1;
        }
    }
    if (h == 1 && w > 1) ans += std::string(w - 1, 'R');
    if (w == 1 && h > 1) ans += std::string(h - 1, 'D');
    std::cout << ans << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
