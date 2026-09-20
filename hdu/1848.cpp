//Wed Sep  9 08:33:42 PM CST 2026
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
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    std::vector<int> f(20);
    f[0] = f[1] = 1;
    int sz = 0;
    for (int i = 2; i < 20; ++i) {
        f[i] = f[i-1] + f[i-2];
        if (f[i] > 1000) {
             sz = i;
             break;
        }
    }
    std::vector<std::vector<int>> adj(1001);
    std::vector<int> sg(1001);
    sg[0] = 0;
    for (int i = 1; i <= 1000; ++i) {
        for (int j = 1; j < sz; ++j) {
            if (i >= f[j]) {
                adj[i].push_back(i-f[j]);
            }
        }
    }
    for (int i = 1; i <= 1000; ++i) {
        int mex = 0;
        std::vector<int> mm;
        for (auto v : adj[i]) {
            mm.push_back(sg[v]);
        }
        std::sort(mm.rbegin(), mm.rend());
        while (!mm.empty()) {
            int v = mm.back();
            if (mex == v) mex++;
            mm.pop_back();
        }
        sg[i] = mex;
    }
    int n, m, p;
    while (std::cin >> n >> m >> p) {
        if (n == 0 && m == 0 && p == 0) break;
        n = sg[n];
        m = sg[m];
        p = sg[p];
        if ((n ^ m ^ p) == 0) {
            std::cout << "Nacci" << nl;
        }else {
            std::cout << "Fibo" << nl;
        }
    }

}
