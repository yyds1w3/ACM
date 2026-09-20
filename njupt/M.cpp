//Fri Aug 21 02:09:31 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cout << #x << ": " << x << nl 
#define debugv(v, sz) do{std::cout << #v << "[]:" << nl;\
for (int i = 0; i < sz; ++i) std::cout << v[i] << " "; std::cout << nl;}while(0)
#define debugvv(v, sz1, sz2) do{std::cout << #v << "[][]:" << nl;\
for (int i = 0; i < sz1; ++i) {std::cout << i << ":";for (int j = 0; j < sz2; ++j) std::cout << v[i][j] << " "; std::cout<<nl;}}while(0)
using i64 = long long;
using i128 = __int128;

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n;
    i64 k;
    std::cin >> n >> k;
    std::vector<i64> v(n);
    for (int i = 0;i < n; ++i) std::cin >> v[i];
    k = std::min(k, 100LL);
    for (int ki = 0; ki < k; ++ki) {
        std::sort(v.begin(), v.end());
        if (v[0] == 0) break;
        for (int i = 1; i < n; ++i) {
            v[i] -= v[i - 1];
        }
    }
    for (int i = 0; i < n; ++i) {
        std::cout << v[i] << " " ;
    }
}
