//Tue Aug 25 02:19:15 PM CST 2026
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

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int p, d;
    std::cin >> p >> d;
    std::vector<int> a(p);
    int mx = 0;
    for (int i = 0; i < d; ++i) {
        int x;
        std::cin >> x;
        for (int j = 0; j < x; ++j) {
            a[j]++;
            mx = std::max(mx, a[j]);
        }
        std::sort(a.begin(), a.begin() + x);
    }
    std::cout << mx << nl;
}
