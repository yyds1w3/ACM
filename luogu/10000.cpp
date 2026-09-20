//Tue Aug 18 10:12:14 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cerr << #x << ": " << x << nl; 
#define debugv(v, sz) std::cerr << #v << "[]:" << nl;\
for (int i = 0; i < sz; ++i) std::cerr << v[i] << " "; std::cerr << nl;
#define debugvv(v, sz1, sz2) std::cerr << #v << "[][]:" << nl;\
for (int i = 0; i < sz1; ++i) {std::cerr << i << ":";for (int j = 0; j < sz2; ++j) std::cerr << v[i][j] << " "; std::cerr<<nl;}
using i64 = long long;
using i128 = __int128;
int a[10] = {1,2,3};
int b[2][2] = {{1,2}, {3, 4}};
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    debugv(a, 10);
    debugvv(b, 2, 2);
}
