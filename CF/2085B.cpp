//Sat Sep 19 08:53:18 PM CST 2026
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
    std::vector<int> a(n);
    int mn = 2;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        mn = std::min(mn, a[i]);
    }
    if (mn > 0) {
        std::cout << 1 << nl;

        std::cout << 1 << " " << n << nl;
    }else if (a[0] != 0){
        std::cout << 2 << nl;

        std::cout << 2 << " " << n << nl;
        std::cout << 1 << " " << 2 << nl;
    }else if (a[n-1] != 0) {
        std::cout << 2 << nl;

        std::cout << 1 << " " << n-1 << nl;
        std::cout << 1 << " " << 2 << nl;
    }else {
        std::cout << 3 << nl;

        std::cout << 3 << " " << n << nl;
        std::cout << 1 << " " << 2 << nl;
        std::cout << 1 << " " << 2 << nl;
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
