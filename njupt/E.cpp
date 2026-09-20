//Tue Aug 25 02:06:25 PM CST 2026
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
const int INF = 1e9;
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    int mn = -INF;
    int mx = INF;
    bool ok = true;
    for (int i = 0; i < n; ++i) {
        int x, y;
        char c;
        std::cin >> x >> y >> c;
        int len = y - x;
        if (c == 'A') {
            mx = std::min(mx, x + (len - 1) / 2);
        }else if (c == 'B') {
            mn = std::max(mn, y - (len - 1) / 2);
        }else {
            if (len % 2 == 0) {
                mn = std::max(mn, x + len / 2);
                mx = std::min(mx, y - len / 2);
            }else {
                ok = false;
            }
        }
    }
    if (mn > mx || !ok) {
        std::cout << '*' << nl;
    }else {
        std::cout << mn << " " << mx << nl;
    }
}
