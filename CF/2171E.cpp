//Thu Sep  3 07:23:01 PM CST 2026
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
    std::vector<std::vector<int>> a(3);
    for (int i = 1; i <= n; ++i) {
        if (i % 2 == 0) a[0].push_back(i);
        else if (i % 3 == 0) a[1].push_back(i);
        else a[2].push_back(i);
    }
    while (a[0].size() >= 2 && a[2].size() >= 1) {
        std::cout << a[2].back() << " ";
        a[2].pop_back();
        std::cout << a[0].back() << " ";
        a[0].pop_back();
        std::cout << a[0].back() << " ";
        a[0].pop_back();
    }
    while (a[1].size() >= 2 && a[2].size() >= 1) {
        std::cout << a[2].back() << " ";
        a[2].pop_back();
        std::cout << a[1].back() << " ";
        a[1].pop_back();
        std::cout << a[1].back() << " ";
        a[1].pop_back();
    }
    for (int v : a[0]) std::cout << v << " ";
    for (int v : a[1]) std::cout << v << " ";
    for (int v : a[2]) std::cout << v << " ";
    std::cout << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
