//Mon Aug 24 03:10:54 PM CST 2026
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
    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        if (x == 1) c1++;
        else c2++;
    }
    if (c2 > 0) {
        if (c1 & 1) std::cout << "Bob" << nl;
        else std::cout << "Alice" << nl;
    }else {
        if (c1 & 1) std::cout << "Alice" << nl;
        else std::cout << "Bob" << nl;
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
