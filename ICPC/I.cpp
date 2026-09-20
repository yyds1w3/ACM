//Mon Sep  7 03:57:33 PM CST 2026
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
    if (n == 0) {
        std::cout << "NO" << nl;
        return;
    }
    std::vector<int> a(32);
    a[31] = 1;
    for (int i = 0; i < 31; ++i) a[i] = -1;
    n -= 1;
    for (int i = 29; i >= 0; --i) {
        if (n >= (1 << i)) {
            a[i] = 0;
            n -= (1 << i);
        }
    }
    for (int i = 29; i >= 0; --i) {
        if (a[i+1] == 0 && a[i] == 0) {
            a[i] += 2;
            a[i + 1] -= 1;
        }
        if (a[i] >= 2 && i > 0) {
            a[i-1] += 2;
            a[i] -= 1;
        }
    }
    for (int i = 1; i <= 29; ++i) {
        if ((a[i] == 0 && a[i - 1] == 0) || (a[i] > 1 || a[i-1] > 1)) {
            std::cout << "NO" << nl;
            return;
        }
    }
    std::cout << "YES" << nl;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 8; ++j) {
            std::cout << a[i*8+j] << " ";
        }
        std::cout << nl;
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
