//Thu Sep  3 10:49:32 AM CST 2026
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
    int s;
    std::cin >> s;
    std::vector<int> a(8);
    for (int i = 1; i <= 7; ++i) {
        std::cin >> a[i];
    }
    std::vector<int> b(4);
    b[1] = a[1];
    b[2] = a[2];
    b[3] = a[4];

    auto check = [](int x, std::vector<int> a, std::vector<int> b) -> bool {
        int d1 = std::max(0, x - b[1]);
        int d2 = std::max(0, x - b[2]);
        int d3 = std::max(0, x - b[3]);
        if (d1 + d2 + d3 > a[3] + a[5] + a[6] + a[7]) {
            return false;
        }else if (d1 + d2 > a[3] + a[5] + a[6] + a[7]) {
            return false;
        }else if (d1 + d3 > a[3] + a[5] + a[6] + a[7]) {
            return false;
        }else if (d2 + d3 > a[3] + a[5] + a[6] + a[7]) {
            return false;
        }else if (d1 > a[3] + a[5] + a[7]) {
            return false;
        }else if (d2 > a[3] + a[6] + a[7]) {
            return false;
        }else if (d3 > a[5] + a[6] + a[7]) {
            return false;
        }
        return true;
    };
    int l = 0, r = 1e9;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (check(mid, a, b)) {
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
    int t;
    std::cin >> t;
    while (t--) solve();
}
