//Sat Aug 22 01:58:22 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cout << #x << ": " << x << nl 
#define debugv(v, sz) do{std::cout << #v << "[]:" << nl;\
for (int i = 0; i < sz; ++i) std::cout << v[i] << " "; std::cout << nl;}while(0)
#define debugvv(v, sz1, sz2) do{std::cout << #v << "[][]:" << nl;\
for (int i = 0; i < sz1; ++i) {std::cout << i << ":";for (int j = 0; j < sz2; ++j) std::cout << v[i][j] << " "; std::cout<<nl;}}while(0)
using i64 = long long;
using i128 = __int128;

void solve() {
    int n, q;
    std::cin >> n >> q;
    for (int i = 1; i < n; ++i) {
        std::cout << i << " " << i + 1 << nl;
    }
    int tmp = n - 1;
    while (q--) {
        int d;
        std::cin >> d;
        if (d == tmp) std::cout << -1 << " " << -1 << " " << -1 << nl;
        else std::cout << n << " " << tmp << " " << d << nl;
        tmp = d;
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
