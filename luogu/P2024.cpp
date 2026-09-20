//Sat Sep  5 08:46:13 PM CST 2026
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
const int N = 5e4;
int n;
std::vector<int> f(3*N), sz(3*N);
void initDSU(int n) {
    std::iota(f.begin(), f.begin() + 3*n, 0);
    sz.assign(3*n, 1);
}
int find(int x) {
    if (f[x] == x) return x;
    return f[x] = find(f[x]);
}
void merge(int x, int y) {
    int rx = find(x);
    int ry = find(y);
    if (rx != ry) {
        f[rx] = ry;
        sz[ry] += sz[rx];
    }
}
bool same(int x, int y) {
    return find(x) == find(y);
}
int size(int x) {
    return sz[find(x)];
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    initDSU(n);
    int cnt = 0;
    while (k--) {
        int op, x, y;
        std::cin >> op >> x >> y;
        if (op == 1) {
            if (x > n || y > n) cnt++;
            else {
                x--, y--;
                if (same(3*x,3*y+1) || same(3*x, 3*y+2)) {
                    cnt++;
                }else {
                    merge(3*x, 3*y);
                    merge(3*x+1,3*y+1);
                    merge(3*x+2,3*y+2);
                }
            }
        }else {
            if (x > n || y > n) cnt++;
            else {
                x--, y--;
                if (same(3*x,3*y) || same(3*x,3*y+2)) {
                    cnt++;
                }else {
                    merge(3*x,3*y+1);
                    merge(3*x+1,3*y+2);
                    merge(3*x+2,3*y);
                }
            }
        }
    }
    std::cout << cnt << nl;
}
