//Fri Sep 11 02:30:23 PM CST 2026
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
    std::vector<int> d(n), p(n);
    std::iota(p.begin(), p.end(), 0);
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        d[i] += x;
    }
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        d[i] -= x;
    }
    std::sort(p.begin(), p.end(), [&](int i, int j) {
        return d[i] > d[j];
    });
    if (d[p[0]] <= 0) {
        std::cout << "No" << nl;
    }else {
        std::cout << "Yes" << nl;
        std::vector<i64> ans(n, 1);
        ans[p[0]] = 1e18;
        for (int i = 0; i < n; ++i) std::cout << ans[i] << " ";
        std::cout << nl;
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    solve();
}
